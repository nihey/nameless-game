/* 
 * File:   Fighter.cpp
 * Author: Nihey
 * 
 * Created on 5 de Maio de 2012, 16:33
 */

#include "Fighter.h"

Fighter::Fighter(string pAlias, int pPower) : Character(pAlias) {
        
    if(pPower < 30){
            
        pPower = 30;
    }
    else if(pPower > 100){
            
        pPower = 100;
    }
    mPower = pPower;
}
    
Fighter::Fighter(string pAlias, int pSTR, int pSPD, int pDEX, int pCON, int pPower) : Character(pAlias, pSTR, pSPD, pDEX, pCON) {
        
    if(pPower < 30){
            
        pPower = 30;
    }
    else if(pPower > 100){
            
        pPower = 100;
    }
    mPower = pPower;
}

int Fighter::attackChartr(Character* pChartr){
    
    if(getHP() == 0){
        
        return 0;
    }
    
    int damage;
                   
    damage = (int) (getAttackPoints() - pChartr->getDefensePoints() - (rand()%10) - 5);
    
    if(damage <= 0){
           
        damage = 1;
    }
        
    if((rand()%10000) < (1000/mXP)){
        
        return 0;
    }
    
    if((rand()%10000) < (200*((double) mXP/2))){
               
        pChartr->addHP(-2 * damage);
        
        return (2*damage);
    }
    else{
                
        pChartr->addHP(-damage);
        
        return damage;
    }
}

int Fighter::getDefensePoints(){
        
    int item_def = mEquippedArmor->getDefensepts() + mEquippedWeapon->getDefensepts();
        
    return ((int) ((((int) mCON * 0.6) + ((int) mDEX * 0.1) + ((int) mSPD * 0.3 + item_def)) * mXP)/6);
}

int Fighter::getAttackPoints(){
        
    int item_att = mEquippedWeapon->getAttackpts();
        
    return (int) (((((int) mSTR * 0.6) + ((int) mDEX * 0.4) + ((int) mPower * 0.1) + item_att) * mXP)/2);
}

Fighter::~Fighter() {
}

