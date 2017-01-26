/* 
 * File:   Button.cpp
 * Author: NLT
 * 
 * Created on June 3, 2012, 9:52 PM
 */

#include "Button.h"

Button::Button(string pImagePath, int pX, int pY){
    
    mImage = new SpriteSheet(pImagePath);
    
    mImage->setSpriteWidth(BUTTON_WIDTH);
    mImage->setSpriteHeight(BUTTON_HEIGHT);
    
    mClickRect = new Rectangle(pX, pY, BUTTON_WIDTH, BUTTON_HEIGHT);
    
    mClickDown = false;
    
    mClicked = false;
    
    mButton_height = BUTTON_HEIGHT;
}

void Button::Draw(){
    
    mImage->Draw(mClickRect->x, mClickRect->y);
}

void Button::HandleEvent(SDL_Event* pEvent){
    
    if(pEvent->type == SDL_MOUSEMOTION){
        
        if(!mClickDown){
            
            int x = pEvent->motion.x;
            int y = pEvent->motion.y;

            if(mClickRect->isInside(x, y)){

                mImage->setOffsetY(mButton_height);
            }
            else{

                mImage->setOffsetY(0);
            }
        }
    }
    if(pEvent->type == SDL_MOUSEBUTTONDOWN){
        
        if(pEvent->button.button == SDL_BUTTON_LEFT){
            
            int x = pEvent->motion.x;
            int y = pEvent->motion.y;

            if(mClickRect->isInside(x, y)){

                mImage->setOffsetY(2*mButton_height);
                mClickDown = true;
            }
        }
    }
    if(pEvent->type == SDL_MOUSEBUTTONUP){
        
        if(pEvent->button.button == SDL_BUTTON_LEFT){
            
            if(mClickDown){
            
                int x = pEvent->motion.x;
                int y = pEvent->motion.y;

                if(mClickRect->isInside(x, y)){

                    mImage->setOffsetY(mButton_height);
                    mClicked = true;
                }
                else{

                    mImage->setOffsetY(0);
                }
            
            }
            
            mClickDown = false;
        }
    }
}

bool Button::WasClicked(){
    
    return mClicked;
}

void Button::Reset(){
    
    mClicked = false;
}

Button::~Button() {
    
    delete mClickRect;
    delete mImage;
}

