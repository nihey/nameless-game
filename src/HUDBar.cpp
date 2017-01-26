/* 
 * File:   HUDBar.cpp
 * Author: Nihey
 * 
 * Created on 12 de Maio de 2012, 19:11
 */

#include "HUDBar.h"

HUDBar::HUDBar(string pText, Rectangle* pBar, Uint8 pR, Uint8 pG, Uint8 pB, Uint8 pA, SDL_Color pTextColor){
    
    mText = pText;
    
    mBar = pBar;
    
    mOffset.x = mBar->x;
    mOffset.y = mBar->y - FONTSIZE;
    
    mFont = TTF_OpenFont(FONTPATH, FONTSIZE);
    
    mRenderizedImage = TTF_RenderText_Solid(mFont, mText.c_str(), pTextColor);

    mBarImage =  SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_ANYFORMAT, mBar->w, mBar->h, SDL_GetVideoSurface()->format->BitsPerPixel, 0, 0, 0, 0);
    SDL_FillRect(mBarImage, NULL, SDL_MapRGB(mBarImage->format, pR, pG, pB));
    SDL_SetAlpha(mBarImage, SDL_SRCALPHA, pA);
    
    mCompBarImage = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_ANYFORMAT, mBar->w, mBar->h/3, SDL_GetVideoSurface()->format->BitsPerPixel, 0, 0, 0, 0);
}

void HUDBar::Draw(Uint8 pR, Uint8 pG, Uint8 pB, Uint8 pA){
    
    SDL_Rect rect = mBar->getSDLRect();
    
    SDL_BlitSurface(mBarImage, NULL, SDL_GetVideoSurface(), &rect);
    
    SDL_FillRect(mCompBarImage, NULL, SDL_MapRGB(mBarImage->format, pR, pG, pB));
    SDL_SetAlpha(mCompBarImage, SDL_SRCALPHA, pA);
    
    SDL_BlitSurface(mCompBarImage, NULL, SDL_GetVideoSurface(), &rect);
    
//    mBar->FillRectangle(mRed, mGreen, mBlue);
//    
//    Rectangle mAdditionalBar(mBar->x, mBar->y, mBar->w, mBar->h/3);
//    
//    mAdditionalBar.FillRectangle(pR, pG, pB);
    
    SDL_BlitSurface(mRenderizedImage, NULL, SDL_GetVideoSurface(), &mOffset);
}

void HUDBar::DrawMutating(){
    
    mBar->Mutate();
    
    SDL_BlitSurface(mRenderizedImage, NULL, SDL_GetVideoSurface(), &mOffset);
}

Rectangle *HUDBar::getBar(){
    
    return mBar;
}

HUDBar::~HUDBar() {
    
    SDL_FreeSurface(mRenderizedImage);
    SDL_FreeSurface(mBarImage);
    SDL_FreeSurface(mCompBarImage);
    
    TTF_CloseFont(mFont);
    
    delete mBar;
}

