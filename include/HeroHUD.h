/* 
 * File:   HeroHUD.h
 * Author: Nihey
 *
 * Created on 12 de Maio de 2012, 22:14
 */

#ifndef HEROHUD_H
#define	HEROHUD_H

#include "HUDBar.h"
#include "Image.h"

#define COMMONALPHA 233

#define EMPTYALPHA 55

#define HPCOLOR1 218, 26, 53
#define HPCOLOR2 241, 107, 129
#define HPFONTCOLOR  38, 44, 38

#define OTHERFONTCOLOR 38, 44, 38

#define STRCOLOR1 0, 66, 28
#define STRCOLOR2 0, 176, 90

#define DEXCOLOR1 108, 33, 111
#define DEXCOLOR2 156, 63, 152

#define SPDCOLOR1 121, 111, 16
#define SPDCOLOR2 201, 196, 114

#define CONCOLOR1 0, 0, 52
#define CONCOLOR2 39, 54, 145

#define EMPTYCOLOR1 0, 0, 0
#define EMPTYCOLOR2 255, 255, 255

#define GENERALOFFSET 5

#define BAROFFSETX 5.0 
#define BAROFFSETY SDL_GetVideoSurface()->h - 20

#define IMGOFFSETX 15
#define IMGOFFSETY SDL_GetVideoSurface()->h - 120

#define BARHEIGHT 10

#define BARJUMPY -30

#define MINIHUDHEIGHT 64
#define MINIHUDWIDTH 64

#define MINIIMGOFFSETX 13
#define MINIIMGOFFSETY SDL_GetVideoSurface()->h - 64 - 13 

class HeroHUD {
    
    protected:

        Image *mHeroImage;
        Image *mMiniHeroImage;
        
        HUDBar *mHPBar;
        
        HUDBar *mSTRBar;
        HUDBar *mDEXBar;
        HUDBar *mSPDBar;
        HUDBar *mCONBar;
        
        HUDBar *mEmptHPBar;
        
        HUDBar *mEmptSTRBar;
        HUDBar *mEmptDEXBar;
        HUDBar *mEmptSPDBar;
        HUDBar *mEmptCONBar;
        
        bool mShowHUD;

    public:
        
        /**
         * Instatantiate a Hero HUD, containing all hero information
         * 
         * @param pImagePath HUD image path
         * @param pMiniImagePath HUD mini Image path
         * @param pSTR Hero STR
         * @param pDEX Hero DEX
         * @param pSPD Hero SPD
         * @param pCON Hero CON
         */
        
        HeroHUD(string pImagePath, string pMiniImagePath, int pSTR, int pDEX, int pSPD, int pCON);

        /**
         * Draw the HUD
         */
        
        void Draw();
        
        /**
         * Handle HUD events
         * 
         * @param pEvent Event to be handled
         */
        
        void HandleEvent(SDL_Event* pEvent);

        virtual ~HeroHUD();

};

#endif	/* HEROHUD_H */

