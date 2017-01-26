/* 
 * File:   HUDBar.h
 * Author: Nihey
 *
 * Created on 12 de Maio de 2012, 19:11
 */

#ifndef HUDBAR_H
#define	HUDBAR_H

#include <cstdlib>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Rectangle.h"

// Manter fonte fixa
#define FONTSIZE 13
#define FONTPATH "res/fonts/Archive.otf"

using namespace std;

class HUDBar {

    protected:
        
        Rectangle *mBar;

        string mText;
        
        TTF_Font* mFont;
        
        SDL_Rect mOffset;
        
        SDL_Surface* mRenderizedImage;
        
        SDL_Surface* mBarImage;
        SDL_Surface* mCompBarImage;
        
    public:
        
        /**
         * Instantiates a HUD bar
         * 
         * @param pText Bar Text
         * @param pBar Bar rectangle
         * @param pR Bar red component
         * @param pG Bar green component
         * @param pB Bar blue component
         * @param pA Bar Alpha Component
         */
        HUDBar(string pText, Rectangle* pBar, Uint8 pR, Uint8 pG, Uint8 pB, Uint8 pA, SDL_Color pTextColor);
        
        /**
         * Draw the HUD Bar on the screen with another complementary bar
         * 
         * @param pR Complementary bar color
         * @param pG Complementary bar color
         * @param pB Complementary bar color
         * @param pA Complementary bar Alpha
         */
        
        void Draw(Uint8 pR, Uint8 pG, Uint8 pB, Uint8 pA);
        
        /**
         * Draw the HUD Bar with its color mutating
         */
        
        void DrawMutating();
        
        /**
         * get The HUD bar rectangle
         * 
         * @return HUD bar rectangle
         */
        
        Rectangle *getBar();
        
        virtual ~HUDBar();

};

#endif	/* HUDBAR_H */

