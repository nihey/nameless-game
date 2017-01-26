/* 
 * File:   Hero.h
 * Author: Nihey
 *
 * Created on 6 de Junho de 2012, 10:40
 */

#ifndef HERO_H
#define	HERO_H

#include <SDL.h>

#include "Entity.h"
#include "Collidable.h"
#include "HeroHUD.h"

#define ARROWPATH "res/arrow/arrow.png"
#define ARROWSIZEX 32
#define ARROWSIZEY 16

class Arrow{ // Arrow to be displayed upwards the player
    
    private:
        
        SpriteSheet *mImage;
        Timer *mSpriteTimer;
        
        int mOffset;
        
    public:
        
        /**
         * Instantiates a arrow
         */
        
        Arrow(){
            
            mImage = new SpriteSheet(ARROWPATH);
            mSpriteTimer = new Timer();
            
            mImage->setSpriteWidth(ARROWSIZEX);
            mImage->setSpriteHeight(ARROWSIZEY);
            
            mOffset = 0;
        }
        
        /**
         * Draw Arrow on (pX, pY) point
         * 
         * @param pX X component
         * @param pY Y component
         */
        
        void Draw(int pX, int pY){
            
            if(mSpriteTimer->getElapsed() > 200){
                
                if(mOffset == 0){
                    
                    mOffset = ARROWSIZEY;
                }
                else{
                    
                    mOffset = 0;
                }
                
                mImage->setOffsetY(mOffset);
                mSpriteTimer->Refresh();
            }
            
            mImage->Draw(pX, pY);
        }

        virtual ~Arrow(){

            delete mImage;
            delete mSpriteTimer;
        }
    
};

class Hero : public Entity, public Collidable {

    private:
        
        friend class HUDDrawer;
        
        HeroHUD* mHUD;
        
        Arrow *mHeadArrow;
        
        Coordinate2D* mLastPosition;
        
        bool mFreeze;
    
    public:
        
        /**
         * Load a hero to be used
         * 
         * @param pImagePath Hero SpriteSheet Path
         * @param HUDPath Hero HUD image
         * @param miniHUDPath Hero mini HUD image
         */
        
        Hero(string pImagePath, string HUDPath, string miniHUDPath);
        
        /**
         * Handle an external event
         * 
         * @param pEvent Event to be handled
         */
        
        void HandleEvent(SDL_Event* pEvent);
        
        /**
         * Draw the image on the screen and apply further properties
         */
        
        void Draw();
        
        /**
         * Usable when go from paused to unpaused, reset character movement timer and other properties.
         */
        
        void Resume();
        
        virtual ~Hero();

};

#endif	/* HERO_H */

