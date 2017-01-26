/* 
 * File:   Timer.cpp
 * Author: Nihey
 * 
 * Created on 7 de Maio de 2012, 13:46
 */

#include "Timer.h"

Timer::Timer() {

    mOriginTime = SDL_GetTicks();
    mFinalTime = 0;
}

int Timer::getElapsed(){
    
    mFinalTime = SDL_GetTicks();
    
    return (mFinalTime - mOriginTime);
}

void Timer::Refresh(){
    
    mOriginTime = SDL_GetTicks();
}

Timer::~Timer() {
}

