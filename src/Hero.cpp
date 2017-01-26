/* 
 * File:   Hero.cpp
 * Author: Nihey
 * 
 * Created on 6 de Junho de 2012, 10:40
 */

#include "Hero.h"

Hero::Hero(string pImagePath, string HUDPath, string miniHUDPath) : Entity(pImagePath){
    
    mHUD = new HeroHUD(HUDPath, miniHUDPath, 30, 20, 10, 40);
    
    mHeadArrow = new Arrow();
    
    mLastPosition = new Coordinate2D(0.0, 0.0);
    
    mCollidableRect = new Rectangle(7, 19, 18, 12);
    mRealRectPos = new Rectangle(7, 19, 18, 12);
    
    mFreeze = true;
    
    // Personalizacao - Mude caso deseje outra configuracao
    mImage->setOffsetX(32);
    mImage->setOffsetX(0);
    mImage->setSpriteWidth(32);
    mImage->setSpriteHeight(32);
    mImage->setOffsetXJump(32);
    mImage->setOffsetYJump(32);    
    // Personalizacao
    
    RefreshPhysics();
}

void Hero::HandleEvent(SDL_Event* pEvent){
    
    mHUD->HandleEvent(pEvent);
    
    if(pEvent->type == SDL_MOUSEBUTTONDOWN){
        
        if(pEvent->button.button == SDL_BUTTON_LEFT){
            
            int x = pEvent->motion.x;
            int y = pEvent->motion.y;

            Rectangle clickrect(mPosition->x, mPosition->y, mImage->getSpriteWidth(), mImage->getSpriteHeight());
            
            if(clickrect.isInside(x, y)){

                mFreeze = false;
                mMovementTimer->Refresh();
            }
            else{
                
                mFreeze = true;
            }
        }
    }
    
    if(pEvent->type == SDL_KEYDOWN){
        
        if(pEvent->key.keysym.sym == SDLK_UP){
            
            mSpeed->y -= mSpeedChangeAMT;
        }
        if(pEvent->key.keysym.sym == SDLK_DOWN){
            
            mSpeed->y += mSpeedChangeAMT;
        }
        if(pEvent->key.keysym.sym == SDLK_LEFT){
            
            mSpeed->x -= mSpeedChangeAMT;
        }
        if(pEvent->key.keysym.sym == SDLK_RIGHT){
            
            mSpeed->x += mSpeedChangeAMT;
        }
    }
    if(pEvent->type == SDL_KEYUP){
        
        if(pEvent->key.keysym.sym == SDLK_UP){
            
            mSpeed->y += mSpeedChangeAMT;
        }
        if(pEvent->key.keysym.sym == SDLK_DOWN){
            
            mSpeed->y -= mSpeedChangeAMT;
        }
        if(pEvent->key.keysym.sym == SDLK_LEFT){
            
            mSpeed->x += mSpeedChangeAMT;
        }
        if(pEvent->key.keysym.sym == SDLK_RIGHT){
            
            mSpeed->x -= mSpeedChangeAMT;
        }
    }
}

void Hero::Draw(){
    
    mLastPosition->x = mPosition->x;
    mLastPosition->y = mPosition->y;
    
    if(!mFreeze){
        
        RefreshPhysics();
    }
    else{
        
        mHeadArrow->Draw(mPosition->x, mPosition->y - ARROWSIZEY);
    }
    
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

void Hero::Resume(){
    
    Entity::Resume();
    
    mSpeed->x = 0;
    mSpeed->y = 0;
}

Hero::~Hero() {
    
    delete mHUD;
    delete mLastPosition;
    delete mHeadArrow;
}

