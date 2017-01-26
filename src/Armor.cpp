/* 
 * File:   Armor.cpp
 * Author: NLT
 * 
 * Created on 18 de Abril de 2012, 16:34
 */

#include "Armor.h"

Armor::Armor(string pName, double pPrice, int pDefensepts, int pFlexibility) : Item(pName, pPrice, 0, pDefensepts) {
    
    mAttackpts = 0;
    mFlexibility = pFlexibility;
    
}

Armor::Armor(string pName, double pPrice, int pDefensepts, char pRank, int pFlexibility) : Item(pName, pPrice, 0, pDefensepts, pRank) {
    
    mAttackpts = 0;
    mFlexibility = pFlexibility;
    
}

Armor::Armor(Armor* pArmor) : Item((Item *) pArmor ){
    
    mFlexibility = pArmor->getFlexibility();
    
}

int Armor::getFlexibility(){
    
    return mFlexibility;
    
}

Armor::~Armor() {
}

