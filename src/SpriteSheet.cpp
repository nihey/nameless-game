/* 
 * File:   SpriteSheet.cpp
 * Author: Nihey
 * 
 * Created on 24 de Abril de 2012, 12:14
 */

#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(string pImagePath) : Image(pImagePath){
    
    mOffsetXJump = 0;
    mOffsetYJump = 0;
    
    mClipRect.x = 0;
    mClipRect.y = 0;
    mClipRect.w = getWidth();
    mClipRect.h = getHeight();
    
    mCycleRight = true;
}

void SpriteSheet::setOffsetX(int pOffset){
    
    mClipRect.x = pOffset;
}

void SpriteSheet::setOffsetY(int pOffset){
    
    mClipRect.y = pOffset;
}

void SpriteSheet::setOffsetXJump(int pOffsetJump){
    
    mOffsetXJump = pOffsetJump;
}

void SpriteSheet::setOffsetYJump(int pOffsetJump){
    
    mOffsetYJump = pOffsetJump;
}

void SpriteSheet::setSpriteWidth(int pWidth){
    
    mClipRect.w = pWidth;
}

void SpriteSheet::setSpriteHeight(int pHeight){
    
    mClipRect.h = pHeight;
}

void SpriteSheet::Draw(){
    
    SDL_BlitSurface(mImage, &mClipRect, SDL_GetVideoSurface(), NULL);
}

void SpriteSheet::Draw(SDL_Rect* pOffset){
    
    SDL_BlitSurface(mImage, &mClipRect, SDL_GetVideoSurface(), pOffset);
}

void SpriteSheet::Draw(int pX, int pY){
    
    SDL_Rect pOffset;
    
    pOffset.x = pX;
    pOffset.y = pY;
    
    SDL_BlitSurface(mImage, &mClipRect, SDL_GetVideoSurface(), &pOffset);
}

void SpriteSheet::Draw(SDL_Rect* pOffset, SDL_Rect* pClip){
    
}

void SpriteSheet::Draw(int pX, int pY, int pClipX, int pClipY, int pClipWidth, int pClipHeight){
    
}

int SpriteSheet::getOffsetXJump(){
    
    return mOffsetXJump;
}

int SpriteSheet::getOffsetYJump(){
    
    return mOffsetYJump;
}

int SpriteSheet::getSpriteWidth(){
    
    return mClipRect.w;
}

int SpriteSheet::getSpriteHeight(){
    
    return mClipRect.h;
}

void SpriteSheet::JumpRight(){
    
    if(mCycleRight){
    
        mClipRect.x += mOffsetXJump;
        
        if(mClipRect.x >= (getSurface()->w)){

            mClipRect.x -= mOffsetXJump;

            mCycleRight = false;
        }        
    }
    else{
        
        mClipRect.x -= mOffsetXJump;
        
        if(mClipRect.x < 0){
        
            mClipRect.x += mOffsetXJump;

            mCycleRight = true;
        }
    }
    
}

SpriteSheet::~SpriteSheet() {
}

