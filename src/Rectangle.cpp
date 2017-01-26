/* 
 * File:   Rectangle.cpp
 * Author: Nihey
 * 
 * Created on 9 de Maio de 2012, 17:07
 */

#include "Rectangle.h"

Rectangle::Rectangle(double pX, double pY, double pW, double pH){
    
    x = pX;
    y = pY;
    w = pW;
    h = pH;
}

bool Rectangle::Collides(Rectangle* pRect){
    
    double LeftA, RightA, TopA, BottomA;
    double LeftB, RightB, TopB, BottomB;
    
    LeftA = x;
    RightA = x + w;
    TopA = y; 
    BottomA = y + h;
    
    LeftB = pRect->x;
    RightB = pRect->x + pRect->w;
    TopB = pRect->y;
    BottomB = pRect->y + pRect->h;
    
    if(LeftA > RightB){
        
        return false;
    }
    if(RightA < LeftB){
        
        return false;
    }
    if(TopA > BottomB){
        
        return false;
    }
    if(BottomA < TopB){
        
        return false;
    }
    
    return true;
}

void Rectangle::FillRectangle(Uint8 pR, Uint8 pG, Uint8 pB){
    
    SDL_Rect rect;
        
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
        
    Uint32 color = SDL_MapRGB(SDL_GetVideoSurface()->format, pR, pG, pB);
        
    SDL_FillRect(SDL_GetVideoSurface(), &rect, color);
}

bool Rectangle::isInside(int pX, int pY){
    
    if((pX >= x)&&(pX <= x + w)&&(pY >= y)&&(pY <= y + h)){
        
        return true;
    }
    return false;
}

void Rectangle::Mutate(){
    
    static int r = 0;
    static int g = 0;
    static int b = 0;
    
    static bool rdown = false;
    static bool gdown = false;
    static bool bdown = false;
    
    if(!rdown){
        
        r += 2;
    }
    else{
        
        r -= 2;
    }
    if(!gdown){
        
        g += 3;
    }
    else{
        
        g -= 3;
    }
    if(!bdown){
        
        b += 5;
    }
    else{
        
        b -= 5;
    }
    if((r+2) > 255){
        
        rdown = true;
    }
    if((g+3) > 255){
        
        gdown = true;
    }
    if((b+5) > 255){
        
        bdown = true;
    }
    if((r-2) < 0){
        
        rdown = false;
    }
    if((g-3) < 0){
        
        gdown = false;
    }
    if((b-5) < 0){
        
        bdown = false;
    }
//    1 1 2 3 5 8 13
    
    FillRectangle(r, g, b);
}

SDL_Rect Rectangle::getSDLRect(){
    
    SDL_Rect rect;
    
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    
    return rect;
}

Rectangle::~Rectangle() {
}

