/* 
 * File:   RevivePotion.cpp
 * Author: Nihey
 * 
 * Created on 6 de Junho de 2012, 16:26
 */

#include "RevivePotion.h"

RevivePotion::RevivePotion() : Item("Revive Potion", 0, 0, 0) {
    
    mRevivePts = 20 + (rand()%20);
}

int RevivePotion::Restore(){
    
    return 0;
}

int RevivePotion::Revive(){
    
    return mRevivePts;
}

bool RevivePotion::ConsumableBy(Character* pChar){
    
    return (pChar->getHP() <= 0);
}

void RevivePotion::Consume(Character* pChar){
    
    if(ConsumableBy(pChar)){
        
        pChar->addHP(mRevivePts);
    }
}

RevivePotion::~RevivePotion() {
}

