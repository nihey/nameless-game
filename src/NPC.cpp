/* 
 * File:   NPC.cpp
 * Author: Nihey
 * 
 * Created on 7 de Maio de 2012, 15:45
 */

#include "NPC.h"

NPC::NPC(string pImagePath) : Entity(pImagePath) {

    mCurrentWaypoint = 0;
    
    mCycleWaypoints = true;
    
    mCollidableRect = new Rectangle(7, 19, 18, 12);
    mRealRectPos = new Rectangle(7, 19, 18, 12);
    
    mLastPosition = new Coordinate2D(0,0);
    
    mWanderer = true;
    
    // Personalizacao - Mude caso deseje outra configuracao
    mImage->setOffsetX(32);
    mImage->setOffsetX(0);
    mImage->setSpriteWidth(32);
    mImage->setSpriteHeight(32);
    mImage->setOffsetXJump(32);
    mImage->setOffsetYJump(32);    
    // Personalizacao
    
    mTalkable = false;
    
    mTalktimer = new Timer();
    
    RefreshPhysics();
}

NPC::NPC(string pImagePath, int pX, int pY, double pAMT, bool pWander, bool pCycle) : Entity(pImagePath) {

    mCurrentWaypoint = 0;
    
    mCycleWaypoints = pCycle;
    
    mCollidableRect = new Rectangle(7, 19, 18, 12);
    mRealRectPos = new Rectangle(7, 19, 18, 12);
    
    mLastPosition = new Coordinate2D(pX, pY);
    
    mWanderer = pWander;
    
    // Personalizacao - Mude caso deseje outra configuracao
    mImage->setOffsetX(32);
    mImage->setOffsetX(0);
    mImage->setSpriteWidth(32);
    mImage->setSpriteHeight(32);
    mImage->setOffsetXJump(32);
    mImage->setOffsetYJump(32);    
    // Personalizacao
    
    mPosition->x = pX;
    mPosition->y = pY;
    
    mSpeedChangeAMT = pAMT;
    
    mTalkable = false;
    
    mTalktimer = new Timer();
    
    RefreshPhysics();
}

NPC::NPC(string pImagePath, int pX, int pY, double pAMT, bool pWander, bool pCycle, string pPhrase, SDL_Color pColor) : Entity(pImagePath){
    
    mCurrentWaypoint = 0;
    
    mCycleWaypoints = pCycle;
    
    mCollidableRect = new Rectangle(7, 19, 18, 12);
    mRealRectPos = new Rectangle(7, 19, 18, 12);
    
    mLastPosition = new Coordinate2D(pX, pY);
    
    mWanderer = pWander;
    
    // Personalizacao - Mude caso deseje outra configuracao
    mImage->setOffsetX(32);
    mImage->setOffsetX(0);
    mImage->setSpriteWidth(32);
    mImage->setSpriteHeight(32);
    mImage->setOffsetXJump(32);
    mImage->setOffsetYJump(32);    
    // Personalizacao
    
    mPosition->x = pX;
    mPosition->y = pY;
    
    mSpeedChangeAMT = pAMT;
    
    mTalkable = true;
    
    mTalking = false;
    
    TTF_Font *font;
        
    font = TTF_OpenFont(FONTPATH, SIZE);
        
    mPhrases.push_back(new Image(TTF_RenderText_Solid(font, pPhrase.c_str(), pColor)));
        
    mPhraseIndex = mPhrases.begin();
    
    TTF_CloseFont(font);
    
    talktime = 0;
    
    mTalktimer = new Timer();
    
    RefreshPhysics();
}

void NPC::addWayPoint(Coordinate2D* pWaypoint){
    
    mWaypoints.push_back(pWaypoint);
}

void NPC::setCycleWaypoints(bool pCycle){
    
    mCycleWaypoints = pCycle;
}

void NPC::setWandererMode(bool pWander){
    
    mWanderer = pWander;
}

void NPC::Draw(){
    
    mLastPosition->x = mPosition->x;
    mLastPosition->y = mPosition->y;
    
    if(mWanderer){
        
        Wander();
    }
    
    FollowWaypoints();
    
    RefreshPhysics();
    
    mRealRectPos->x = mCollidableRect->x + mPosition->x;
    mRealRectPos->y = mCollidableRect->y + mPosition->y;
    
    for(vector<Collidable *>::iterator it = mCollidables.begin(); it != mCollidables.end(); it++){
        
        if((*it)->Collides(this)){
            
            double aux;
            
            aux = mPosition->x;
            mPosition->x = mLastPosition->x;
            
            mRealRectPos->x = mCollidableRect->x + mPosition->x;
            
            if(!((*it)->Collides(this))){
                
                continue;
            }
            
            mPosition->x = aux;
            mPosition->y = mLastPosition->y;
            
            mRealRectPos->x = mCollidableRect->x + mPosition->x;
            mRealRectPos->y = mCollidableRect->y + mPosition->y;
            
            if(!((*it)->Collides(this))){
                
                continue;
            }
            
            mPosition->x = mLastPosition->x;
            
            mRealRectPos->x = mCollidableRect->x + mPosition->x;
        }
    }
    
    DrawImage();
}

void NPC::FollowWaypoints(){
    
    if(mWaypoints.size() == 0){
        
        return;
    }  
    
    mSpeed->x = mWaypoints.at(mCurrentWaypoint)->x - mPosition->x;
    mSpeed->y = mWaypoints.at(mCurrentWaypoint)->y - mPosition->y;
    
    double module = mSpeed->getModule();
    
    if(mSpeed->x > 0){
        
        mSpeed->x = mSpeedChangeAMT;
    }
    else if(mSpeed->x < 0){
        
        mSpeed->x = -mSpeedChangeAMT;
    }
    if(mSpeed->y > 0){
        
        mSpeed->y = mSpeedChangeAMT;
    }
    else if(mSpeed->y < 0){
        
        mSpeed->y = -mSpeedChangeAMT;
    }
     
    
    if(mWaypoints.at(mCurrentWaypoint)->equals(mPosition)){
        
        mCurrentWaypoint++;
        mCurrentWaypoint = mCurrentWaypoint % mWaypoints.size();
        
        if(!mCycleWaypoints){
         
            if(mCurrentWaypoint == 0){
                
                for(int i = 0; i < mWaypoints.size(); i++){
                    
                    delete mWaypoints.at(i);
                }               
                mWaypoints.clear();
                
                mSpeed->x = 0;
                mSpeed->y = 0;
            }
        }
    }
}

void NPC::Wander(){
    
    if(((rand()%10000) < 100)){
        
        for(int i = 0; i < mWaypoints.size(); i++){
            
            delete mWaypoints.at(i);
        }
        mWaypoints.clear();
        
        switch(rand()%4){
            
            case 0:
            
                addWayPoint(new Coordinate2D(mPosition->x, mPosition->y + mImage->getSpriteHeight()));
                
            break;
            case 1:
                
                addWayPoint(new Coordinate2D(mPosition->x, mPosition->y - mImage->getSpriteHeight()));
                
            break;
            case 2:
                
                addWayPoint(new Coordinate2D(mPosition->x + mImage->getSpriteWidth(), mPosition->y));
                
            break;
            case 3:
                
                addWayPoint(new Coordinate2D(mPosition->x - mImage->getSpriteWidth(), mPosition->y));
                
            break;
        }
    }
}

bool NPC::Collides(Collidable* pCollidable){
    
    bool retval = Collidable::Collides(pCollidable);
    
    if(retval){
            
        if(talktime != 0){
                
            if(!mTalking){
                    
                mPhraseIndex++;
                    
                if(mPhraseIndex == mPhrases.end()){
                        
                    mPhraseIndex = mPhrases.begin();
                }
            }
        }
            
        if(mTalkable){
                
            mTalktimer->Refresh();
            mTalking = true;
            talktime = TALKTIME;
        }
    }
    
    return retval;
}

void NPC::addPhrase(string pPhrase, SDL_Color pColor){
    
    if(!mTalkable){
        
        return;
    }
    
    TTF_Font *font;
        
    font = TTF_OpenFont(FONTPATH, SIZE);
        
    mPhrases.push_back(new Image(TTF_RenderText_Solid(font, pPhrase.c_str(), pColor)));
        
    mPhraseIndex = mPhrases.begin();
    
    TTF_CloseFont(font);
}

void NPC::DrawPhrase(){
    
    if(mTalkable){
        
        if(mTalktimer->getElapsed() < talktime){
                
            (*mPhraseIndex)->Draw(mPosition->x - ((*mPhraseIndex)->getWidth()/2) + (mImage->getSpriteWidth()/2), mPosition->y - FONTSIZE);
        }
        else{
            
            mTalking = false;
        }
    }
}

NPC::~NPC() {
    
    for(int i = 0; i < mWaypoints.size(); i++){
        
        delete mWaypoints.at(i);
    }
    mWaypoints.clear();
    
    for(mPhraseIndex = mPhrases.begin(); mPhraseIndex != mPhrases.end(); mPhraseIndex++){
        
        delete *mPhraseIndex;
    }
    mPhrases.clear();
    
    delete mTalktimer;
    delete mLastPosition;
    
}

