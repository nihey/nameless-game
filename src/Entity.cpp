/* 
 * File:   Entity.cpp
 * Author: Nihey
 * 
 * Created on 5 de Maio de 2012, 14:44
 */

#include "Entity.h"

Entity::Entity(string pImagePath) {
    
    mImage = new SpriteSheet(pImagePath);
    
    mImage->setOffsetX(0);
    mImage->setOffsetY(0);
    mImage->setOffsetXJump(0);
    mImage->setOffsetYJump(0);
    mImage->setSpriteWidth(mImage->getWidth());
    mImage->setSpriteHeight(mImage->getHeight());
    
    mPosition = new Coordinate2D(0.0, 0.0);
    
    mSpeed = new Vector2D(0.0, 0.0);
    
    mMovementTimer = new Timer();
    mSpriteTimer = new Timer();
    
}

void Entity::DrawImage(){
    
    mImage->Draw(mPosition->x, mPosition->y);
}

void Entity::RefreshPhysics(){
    
    int elapsed = mMovementTimer->getElapsed();
    
    elapsed /= 10;
    
    mPosition->x += (mSpeed->x * elapsed);
    mPosition->y += (mSpeed->y * elapsed);
    
    if(mSpeed->y > 0){
        
        mImage->setOffsetY(0);
    }
    else if(mSpeed->y < 0){
        
        mImage->setOffsetY(3 * mImage->getOffsetYJump());
    }
    if(mSpeed->x > 0){
        
        mImage->setOffsetY(2 * mImage->getOffsetYJump());
    }
    else if(mSpeed->x < 0){
        
        mImage->setOffsetY(mImage->getOffsetYJump());
    }
    
    if(mSpeed->getModule() != 0){
        
        if(mSpriteTimer->getElapsed() > 70){
            
            mImage->JumpRight();
            mSpriteTimer->Refresh();
        }
    }
    else{
        
        mImage->setOffsetX(mImage->getOffsetXJump());
    }
    
    mMovementTimer->Refresh();
    
}

void Entity::setPosition(double pX, double pY){
    
    mPosition->x = pX;
    mPosition->y = pY;
}

void Entity::setSpeedChangeAMT(double pAMT){
    
    mSpeedChangeAMT = pAMT;
}

void Entity::Resume(){
    
    mMovementTimer->Refresh();
}

Entity::~Entity() {
    
    delete mImage;
    delete mPosition;
    delete mSpeed;
    delete mSpriteTimer;
    delete mMovementTimer;
}