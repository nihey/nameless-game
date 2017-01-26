/* 
 * File:   HealthPotion.cpp
 * Author: Nihey
 * 
 * Created on 6 de Junho de 2012, 16:59
 */

#include "HealthPotion.h"

HealthPotion::HealthPotion() : Item("Health Potion", 0, 0, 0) {
    
    mRestorepts = 50 + (rand()%50);
}

int HealthPotion::Restore(){
    
    return mRestorepts;
}

int HealthPotion::Revive(){
    
    return 0;
}

bool HealthPotion::ConsumableBy(Character* pChar){
    
    return ((pChar->getHP() != 0)&&(pChar->getHP() != pChar->getMaxHP()));
}

void HealthPotion::Consume(Character* pChar){
    
    if(ConsumableBy(pChar)){
        
        pChar->addHP(mRestorepts);
    }
}

HealthPotion::~HealthPotion() {
}

