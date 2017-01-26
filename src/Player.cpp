/* 
 * File:   Player.cpp
 * Author: Nihey
 * 
 * Created on 4 de Julho de 2012, 14:48
 */

#include "Player.h"

Player::Player(string pImage, Character *pChar) : NPC(pImage) {
    
    mCharacter = pChar;
    
    mRange = 1;
    
    mWalkableRect = new Rectangle(mPosition->x - (TILESIZE*3), mPosition->y - (TILESIZE*3), TILESIZE*7, TILESIZE*7);
    
    mHitBox = new Rectangle(mPosition->x - (TILESIZE*mRange), mPosition->y - (TILESIZE*mRange), TILESIZE*((mRange*2) + 1), TILESIZE*((mRange*2) + 1));
    
    mConsumeBox = new Rectangle(mPosition->x - (TILESIZE*2), mPosition->y - (TILESIZE*2), TILESIZE*5, TILESIZE*5);
    
    mWayPosition = new Coordinate2D(0.0, 0.0);
    
    mFinishedMovement = true;
    
    mDeathImage = new Image(DEATHPATH);
    
    mWalk = new MiniButton(WALKPATH);
    mAttack = new MiniButton(ATKPATH);
    mConsume = new MiniButton(CONSPATH);
    
    mArrow = new Arrow();
    
    mWalkable = false;
    mFinished = true;
    
    mActive = false;
    
    setSpeedChangeAMT(0.5);
    setWandererMode(false);
    mWaypoints.clear();
    
    mCycleWaypoints = false;
    
    mStatus = MENU;
    
    mDamageTimer = new Timer();
    
    mFont = TTF_OpenFont(FONTPATH, FONTSIZE);
    
    mDamageImg = TTF_RenderText_Solid(mFont, " ", (SDL_Color) {ATTACKCOLOR});
    
    mEntities.push_back(this);
}

void Player::HandleEvent(SDL_Event *pEvent){
    
    if(mFinished || (!isAlive())){
        
        return;
    }
    
    if(mActive && (mStatus == MENU)){
        
        mWalk->HandleEvent(pEvent);
        mAttack->HandleEvent(pEvent);
        mConsume->HandleEvent(pEvent);
        
        if(mWalk->WasClicked()){
            
            mWalk->Reset();
            
            if(mWalkable){
                
                mStatus = WALK;
            }
        }
        if(mAttack->WasClicked()){
            
            mAttack->Reset();
            
            mStatus = ATTACK;
        }
        if(mConsume->WasClicked()){
            
            mConsume->Reset();
            
            mStatus = CONSUME;
        }
    }
    
    if(pEvent->type == SDL_MOUSEBUTTONDOWN){
        
        if(pEvent->button.button == SDL_BUTTON_LEFT){
            
            int x = pEvent->motion.x;
            int y = pEvent->motion.y;
            
            Rectangle clickrect(mPosition->x, mPosition->y,TILESIZE, TILESIZE );
            if(mActive){
                
                if(mWalkable && (mStatus == WALK)){
                    if(mWalkableRect->isInside(x, y)){

                        x = x - (x%32);
                        y = y - (y%32);
                        
                        for(vector<Player*>::iterator it = mEntities.begin(); it != mEntities.end(); it++){
                            
                            if(((*it)->mWayPosition->x == x) && ((*it)->mWayPosition->y == y)){
                                
                                if((*it)->isAlive()){
                                 
                                    return;
                                }
                            }
                        }
                        
                        mMovementTimer->Refresh();

                        mWayPosition->x = (double) x;
                        mWayPosition->y = (double) y;
                        
                        addWayPoint(new Coordinate2D(x - (x%32), y - (y%32)));

                        mWalkable = false;
                        
                        mStatus = MENU;
                        
                        mFinishedMovement = false;
                    }
                    else{
                        
                        mActive = false;
                        
                        mStatus = MENU;
                    }
                }
                if(mStatus == ATTACK){
                    
                    if(mHitBox->isInside(x, y)){
                        
                        x = x - (x%32);
                        y = y - (y%32);
                        
                        for(vector<Player*>::iterator it = mEntities.begin(); it != mEntities.end(); it++){
                            
                            if(((*it)->mWayPosition->x == x) && ((*it)->mWayPosition->y == y)){
                                
                                if((*it)->isAlive()){
                                 
                                    Attack(*it);
                                }
                            }
                        }
                    }
                    else{
                        
                        mActive = false;
                        
                        mStatus = MENU;
                    }
                }
                if(mStatus == CONSUME){
                    
                    if(mConsumeBox->isInside(x, y)){
                        
                        x = x - (x%32);
                        y = y - (y%32);
                        
                        for(vector<Player*>::iterator it = mEntities.begin(); it != mEntities.end(); it++){
                            
                            if(((*it)->mWayPosition->x == x) && ((*it)->mWayPosition->y == y)){
                                
                                Consume(*it);
                            }
                        }
                    }
                    else{
                        
                        mActive = false;
                        
                        mStatus = MENU;
                    }
                }
            }
            else if(clickrect.isInside(x, y)){

                mActive = true;
            }
        }
    }
    
    if(pEvent->type == SDL_KEYDOWN){
        
        switch(pEvent->key.keysym.sym){
            
            case SDLK_SPACE:
                
                mActive = false;
                
                mStatus = MENU;
                
            break;
        }
    }
}

void Player::Reset(){
    
    mWalkable = true;
    
    mFinished = false;
    
    mActive = false;
    
    mStatus = MENU;
}

void Player::Draw(){
    
    if(isAlive()){
       
        NPC::Draw();

        if((!mFinished)&&(!mActive)){
            
            mArrow->Draw(mPosition->x, mPosition->y - ARROWSIZEY);
        }
        
        if(!mFinishedMovement){

            if((mSpeed->x == 0) && (mSpeed->y == 0)){

                setPosition(mWayPosition->x, mWayPosition->y);

                mFinishedMovement = true;
            }
        }
        if(mDamageTimer->getElapsed() < DAMAGETIME){

            SDL_Rect offset;

            offset.x = mPosition->x - (mDamageImg->w/2) + (mImage->getSpriteWidth()/2);
            offset.y = mPosition->y - FONTSIZE;

            SDL_BlitSurface(mDamageImg, NULL, SDL_GetVideoSurface(), &offset);
        }

        mWalkableRect->x = mPosition->x - (TILESIZE*3);
        mWalkableRect->y = mPosition->y - (TILESIZE*3);

        mHitBox->x = mPosition->x - (TILESIZE*mRange);
        mHitBox->y = mPosition->y - (TILESIZE*mRange);

        mConsumeBox->x = mPosition->x - (TILESIZE*2);
        mConsumeBox->y = mPosition->y - (TILESIZE*2);

        if(mPosition->x < (SDL_GetVideoSurface()->w/2)){

            mWalk->Update(mPosition->x + 40, mPosition->y);
            mAttack->Update(mPosition->x + 40, mPosition->y + (BUTTON_HEIGHT/2) + 5);
            mConsume->Update(mPosition->x + 40, mPosition->y + (BUTTON_HEIGHT) + 10);
        }
        else{

            mWalk->Update(mPosition->x - 8 - (BUTTON_WIDTH/2), mPosition->y);
            mAttack->Update(mPosition->x - 8 - (BUTTON_WIDTH/2), mPosition->y + (BUTTON_HEIGHT/2) + 5);
            mConsume->Update(mPosition->x - 8 - (BUTTON_WIDTH/2), mPosition->y + (BUTTON_HEIGHT) + 10);
        }
    }
    else{
        
        mDeathImage->Draw(mPosition->x, mPosition->y);
        
        Finish();
    }
}

void Player::DrawWRect(){
    
    if(mActive && mWalkable && (mStatus == WALK)){
        
        mWalkableRect->Mutate();
    }
    if(mActive && (mStatus == ATTACK)){
        
        mHitBox->FillRectangle(ATTACKCOLOR);
    }
    if(mActive && (mStatus == CONSUME)){
        
        mConsumeBox->FillRectangle(CONSUMECOLOR);
    }
}

void Player::DrawButtons(){
    
    if(mActive && (mStatus == MENU)){
        
        mWalk->Draw();
        mAttack->Draw();
        mConsume->Draw();
    }
}

void Player::Finish(){
    
    mFinished = true;
    mActive = false;
    
    mStatus = MENU;
}

void Player::Damage(int pDamage){
    
    stringstream sstr;
    
    sstr << pDamage;
    
    mDamageImg = TTF_RenderText_Solid(mFont, sstr.str().c_str(), (SDL_Color) {BLACK});
    
    mDamageTimer->Refresh();
}

void Player::addEntity(Player* pPlayer){
    
    mEntities.push_back(pPlayer);
}

void Player::setPosition(int pX, int pY){
    
    Entity::setPosition(pX, pY);
    
    mWayPosition->x = pX;
    mWayPosition->y = pY;
}

void Player::HPGain(int pGain){
    
    stringstream sstr;
    
    sstr << pGain;
    
    mDamageImg = TTF_RenderText_Solid(mFont, sstr.str().c_str(), (SDL_Color) {BLACK});
    
    mDamageTimer->Refresh();
}

bool Player::isAlive(){
    
    return (mCharacter->getHP() > 0);
}

void Player::Attack(Player* pPlayer){
    
    pPlayer->Damage(mCharacter->attackChartr(pPlayer->mCharacter));
    
    Finish();
}

void Player::Consume(Player* pPlayer){
    if(mCharacter->mConsumable != NULL){
        
        if(mCharacter->mConsumable->Restore() != 0){

            pPlayer->HPGain(mCharacter->mConsumable->Restore());
        }
        else{

            pPlayer->HPGain(mCharacter->mConsumable->Revive());
        }
    
        mCharacter->useConsumable(pPlayer->mCharacter);
        
        Finish();
    }
}

Player::~Player() {
    
    delete mWalk;
    delete mAttack;
    delete mConsume;
    
    delete mWayPosition;
    
    delete mWalkableRect;
    delete mHitBox;
    delete mConsumeBox;
    
    delete mArrow;
    
    delete mDamageTimer;
    
    delete mDeathImage;
    
    delete mCharacter;
    
    TTF_CloseFont(mFont);
    
    SDL_FreeSurface(mDamageImg);
}

