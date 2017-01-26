/* 
 * File:   HUDDrawer.cpp
 * Author: Nihey
 * 
 * Created on 16 de Junho de 2012, 11:48
 */

#include "HUDDrawer.h"

HUDDrawer::HUDDrawer() {
}

void HUDDrawer::Draw(){
    
    Hero* hero = NULL;
    
    for(vector<Hero*>::iterator it = mHeroes.begin(); it != mHeroes.end(); it++){
        
        if(!(*it)->mFreeze){
            
            hero = *it;
            break;
        }
    }
    
    if(hero != NULL){
        
        hero->mHUD->Draw();
    }
}

void HUDDrawer::addHero(Hero* pHero){
    
    mHeroes.push_back(pHero);
}

HUDDrawer::~HUDDrawer() {
}

