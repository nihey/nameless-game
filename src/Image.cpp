/* 
 * File:   Image.cpp
 * Author: Nihey
 * 
 * Created on 20 April 2012, 15:58
 */

#include "Image.h"

Image::Image(string pImagePath){
    
    SDL_Surface* loaded = NULL; // Will be optimized soon
    
    mImage = NULL;
    
    loaded = IMG_Load(pImagePath.c_str());
    
    mImage = SDL_DisplayFormatAlpha(loaded); // Optimization
    
    mWidth = mImage->w;
    
    mHeight = mImage->h;
    
    SDL_FreeSurface(loaded);
}

Image::Image(SDL_Surface* pSurface){
    
    SDL_Surface* loaded = NULL; // Will be optimized soon
    
    mImage = NULL;
    
    loaded = pSurface;
    
    mImage = SDL_DisplayFormatAlpha(loaded); // Optimization
    
    mWidth = mImage->w;
    
    mHeight = mImage->h;
    
    SDL_FreeSurface(loaded);

}

void Image::setChromakey(Uint32 pChromaRGB){
    
    SDL_SetColorKey(mImage, SDL_SRCCOLORKEY, pChromaRGB);
}

void Image::setChromakey(int pChromaRed, int pChromaGreen, int pChromaBlue){
    
    Uint32 pChromaRGB = SDL_MapRGB(mImage->format, pChromaRed, pChromaGreen, pChromaBlue);
    
    SDL_SetColorKey(mImage, SDL_SRCCOLORKEY, pChromaRGB);
}

void Image::Draw(){
    
    SDL_BlitSurface(mImage, NULL, SDL_GetVideoSurface(), NULL);
}

void Image::Draw(SDL_Rect* pOffset){
    
    SDL_BlitSurface(mImage, NULL, SDL_GetVideoSurface(), pOffset);
}

void Image::Draw(int pX, int pY){
    
    SDL_Rect pOffset;
    
    pOffset.x = pX;
    pOffset.y = pY;
    
    SDL_BlitSurface(mImage, NULL, SDL_GetVideoSurface(), &pOffset);
}

void Image::Draw(SDL_Rect* pOffset, SDL_Rect* pClip){
    
    SDL_BlitSurface(mImage, pClip, SDL_GetVideoSurface(), pOffset);
}

void Image::Draw(int pX, int pY, int pClipX, int pClipY, int pClipWidth, int pClipHeight){
    
    SDL_Rect pClip;
    SDL_Rect pOffset;
    
    pOffset.x = pX;
    pOffset.y = pY;
    
    pClip.x = pClipX;
    pClip.y = pClipY;
    pClip.w = pClipWidth;
    pClip.h = pClipHeight;
    
    SDL_BlitSurface(mImage, &pClip, SDL_GetVideoSurface(), &pOffset);
}

int Image::getWidth(){
    
    return mWidth;
}

int Image::getHeight(){
    
    return mHeight;
}

SDL_Surface* Image::getSurface(){
    
    return mImage;
}

Image::~Image() {

    SDL_FreeSurface(mImage);
}

