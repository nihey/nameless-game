/* 
 * File:   Weapon.cpp
 * Author: NLT
 * 
 * Created on 18 April 2012, 13:40
 */

#include "Weapon.h"

Weapon::Weapon(string pName, double pPrice, int pAttackpts, int pDefensepts, int pRange) : Item(pName, pPrice, pAttackpts, pDefensepts) {
    
    if(pRange < 1){
           
        pRange = 1;
    }
        
    if(pDefensepts > 5){
            
        mDefensepts = 5;
    }
    mRange = pRange;
    
}

Weapon::Weapon(string pName, double pPrice, int pAttackpts, int pDefensepts, char pRank, int pRange) : Item(pName, pPrice, pAttackpts, pDefensepts, pRank){
    
    if(pRange < 1){
           
        pRange = 1;
    }
        
    if(pDefensepts > 5){
            
        mDefensepts = 5;
    }
    mRange = pRange;
}

Weapon::Weapon(const Weapon* pWeapon) : Item((Item *) pWeapon) {
    
    mRange = pWeapon->mRange;
    
}

int Weapon::getRange(){
    
    return mRange;
}

Weapon::~Weapon() {
}

