/* 
 * File:   HeroHUD.cpp
 * Author: Nihey
 * 
 * Created on 12 de Maio de 2012, 22:14
 */

#include "HeroHUD.h"
#include "Circle.h"

HeroHUD::HeroHUD(string pImagePath, string pMiniImagePath, int pSTR, int pDEX, int pSPD, int pCON) {
    
    mHeroImage = new Image(pImagePath);
    mMiniHeroImage = new Image(pMiniImagePath);
    
    mHPBar = new HUDBar("HP", new Rectangle(BAROFFSETX + GENERALOFFSET, BAROFFSETY + GENERALOFFSET, 100.0, BARHEIGHT), HPCOLOR1,  COMMONALPHA, (SDL_Color) {HPFONTCOLOR});

    mSTRBar = new HUDBar("STR", new Rectangle(BAROFFSETX + GENERALOFFSET + 110, BAROFFSETY + GENERALOFFSET + BARJUMPY, pSTR, BARHEIGHT), STRCOLOR1,  COMMONALPHA, (SDL_Color) {OTHERFONTCOLOR});
   
    mDEXBar = new HUDBar("DEX", new Rectangle(BAROFFSETX + GENERALOFFSET + 110, BAROFFSETY + GENERALOFFSET, pDEX, BARHEIGHT), DEXCOLOR1,  COMMONALPHA, (SDL_Color) {OTHERFONTCOLOR});
    
    mSPDBar = new HUDBar("SPD", new Rectangle(BAROFFSETX + GENERALOFFSET + 220, BAROFFSETY + GENERALOFFSET + BARJUMPY, pSPD, BARHEIGHT), SPDCOLOR1,  COMMONALPHA, (SDL_Color) {OTHERFONTCOLOR});
    
    mCONBar = new HUDBar("CON", new Rectangle(BAROFFSETX + GENERALOFFSET + 220, BAROFFSETY + GENERALOFFSET, pCON, BARHEIGHT), CONCOLOR1,  COMMONALPHA, (SDL_Color) {OTHERFONTCOLOR});
    
    
    mEmptHPBar = new HUDBar("HP", new Rectangle(BAROFFSETX + GENERALOFFSET, BAROFFSETY + GENERALOFFSET, 100.0, BARHEIGHT), HPCOLOR1, EMPTYALPHA, (SDL_Color) {HPFONTCOLOR});

    mEmptSTRBar = new HUDBar("STR", new Rectangle(BAROFFSETX + GENERALOFFSET + 110, BAROFFSETY + GENERALOFFSET + BARJUMPY, 100.0, BARHEIGHT), STRCOLOR1, EMPTYALPHA, (SDL_Color) {OTHERFONTCOLOR});
   
    mEmptDEXBar = new HUDBar("DEX", new Rectangle(BAROFFSETX + GENERALOFFSET + 110, BAROFFSETY + GENERALOFFSET, 100.0, BARHEIGHT), DEXCOLOR1, EMPTYALPHA, (SDL_Color) {OTHERFONTCOLOR});
    
    mEmptSPDBar = new HUDBar("SPD", new Rectangle(BAROFFSETX + GENERALOFFSET + 220, BAROFFSETY + GENERALOFFSET + BARJUMPY, 100.0, BARHEIGHT), SPDCOLOR1, EMPTYALPHA, (SDL_Color) {OTHERFONTCOLOR});
    
    mEmptCONBar = new HUDBar("CON", new Rectangle(BAROFFSETX + GENERALOFFSET + 220, BAROFFSETY + GENERALOFFSET, 100.0, BARHEIGHT), CONCOLOR1, EMPTYALPHA, (SDL_Color) {OTHERFONTCOLOR});
    
    mShowHUD = false;
}

void HeroHUD::Draw(){
    
    if(mShowHUD){
        
        mHeroImage->Draw(IMGOFFSETX, IMGOFFSETY);

        mEmptHPBar->Draw(HPCOLOR2,  EMPTYALPHA);

        mEmptSTRBar->Draw(STRCOLOR2,  EMPTYALPHA);
        mEmptDEXBar->Draw(DEXCOLOR2,  EMPTYALPHA);
        mEmptSPDBar->Draw(SPDCOLOR2,  EMPTYALPHA);
        mEmptCONBar->Draw(CONCOLOR2,  EMPTYALPHA);

        mHPBar->Draw(HPCOLOR2,  COMMONALPHA);

        mSTRBar->Draw(STRCOLOR2,  COMMONALPHA);
        mDEXBar->Draw(DEXCOLOR2,  COMMONALPHA);
        mSPDBar->Draw(SPDCOLOR2,  COMMONALPHA);
        mCONBar->Draw(CONCOLOR2,  COMMONALPHA);
    }
    else{
        
        mMiniHeroImage->Draw(MINIIMGOFFSETX, MINIIMGOFFSETY);
    }
}

void HeroHUD::HandleEvent(SDL_Event* pEvent){
    
    static Circle mini_hud_circ(MINIIMGOFFSETX + 32, MINIIMGOFFSETY + 32, 32);
    
    if(pEvent->type == SDL_MOUSEMOTION){
        
        int x = pEvent->motion.x;
        int y = pEvent->motion.y;
        
        if(mini_hud_circ.isInside(x, y)){
            
            mShowHUD = true;
        }
        else{
            
            mShowHUD = false;
        }
    }
}

HeroHUD::~HeroHUD() {
    
    delete mHeroImage;
    delete mMiniHeroImage;
    
    delete mHPBar;
    
    delete mSTRBar;
    delete mDEXBar;
    delete mSPDBar;
    delete mCONBar;
    
    delete mEmptHPBar;
    
    delete mEmptSTRBar;
    delete mEmptDEXBar;
    delete mEmptSPDBar;
    delete mEmptCONBar;   
}

