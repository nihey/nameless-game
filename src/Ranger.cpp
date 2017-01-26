/* 
 * File:   Ranger.cpp
 * Author: Nihey
 * 
 * Created on 5 de Maio de 2012, 17:08
 */

#include "Ranger.h"

Ranger::Ranger(string pAlias, int pAccurracy) : Character(pAlias) {
        
    if(pAccurracy < 30){
            
        pAccurracy = 30;
    }
    else if(pAccurracy > 100){
            
        pAccurracy = 100;
    }
    mAccurracy = pAccurracy;
}

Ranger::Ranger(string pAlias, int pSTR, int pSPD, int pDEX, int pCON, int pAccurracy) : Character(pAlias, pSTR, pSPD, pDEX, pCON) {
        
    if(pAccurracy < 30){
            
        pAccurracy = 30;
    }
    else if(pAccurracy > 100){
            
        pAccurracy = 100;
    }
    mAccurracy = pAccurracy;
}

int Ranger::attackChartr(Character* pChartr){
    
    if(getHP() == 0){
        
        return 0;
    }
    
    int damage;
                   
    damage = (int) (getAttackPoints() - pChartr->getDefensePoints() - (rand()%10) - 5);
    
    if(damage <= 0){
           
        damage = 1;
    }
    
    if((rand()%10000) < (700/mXP)){
        
        return 0;
    }
    
    if((rand()%10000) < 200*((double) mXP/2)){
               
        pChartr->addHP(-2 * damage);
        
        return (2*damage);
    }
    else{
                
        pChartr->addHP(-damage);
        
        return (damage);
    }
}

int Ranger::getDefensePoints(){
        
    int item_def = mEquippedArmor->getDefensepts() + mEquippedWeapon->getDefensepts();
        
    return ((int) ((((int) mCON * 0.5) + ((int) mDEX * 0.2) + ((int) mSPD * 0.3 + item_def)) * mXP)/6);
}

int Ranger::getAttackPoints(){
        
  int item_att = mEquippedWeapon->getAttackpts();
   
  return (int) (((((int) mSTR * 0.5) + ((int) mDEX * 0.5) + ((int) mAccurracy * 0.1) + item_att) * mXP)/2);
}

Ranger::~Ranger() {
}

