/* 
 * File:   Character.cpp
 * Author: NLT
 * 
 * Created on April 19, 2012, 12:38 AM
 */

#include "Character.h"
#include "RevivePotion.h"

Character::Character(string pAlias){
    
    mAlias = pAlias;
       
    mHP = 100;
    mMaxHP = 100;
    mXP = 1;
    
    mSTR = 25;
    mSPD = 25;
    mDEX = 25;
    mCON = 25;
    
    mEquippedWeapon = new Weapon("Default Weapon", 0, 0, 0, 0);
    mEquippedArmor = new Armor("Default Armor", 0, 0, 0);
    
    mConsumable = new RevivePotion();
}

Character::Character(string pAlias, int pSTR, int pSPD, int pDEX, int pCON){
    
    mAlias = pAlias;
        
    mHP = 100;
    mMaxHP = 100;
    mXP = 1;
    if((pSTR + pSPD + pDEX + pCON) == 100){

        mSTR = pSTR;
        mSPD = pSPD;
        mDEX = pDEX;
        mCON = pCON;
    }
    else{
            
        mSTR = 25;
        mSPD = 25;
        mDEX = 25;
        mCON = 25;
    }
        
    mEquippedWeapon = new Weapon("Default Weapon", 0, 0, 0, 0);
    mEquippedArmor = new Armor("Default Armor", 0, 0, 0);
    
    mConsumable = new RevivePotion();
}

int Character::getHP(){
    
    return mHP;
}

string Character::getName(){
    
    return mAlias;
}

void Character::AddItem(int pKey, Item* pItem){
    
    mInventory.insert(pair<int, Item*>(pKey, pItem));
}

void Character::EquipWeapon(Weapon *pWeapon){

    delete mEquippedWeapon;
    
    mEquippedWeapon = pWeapon;
}

void Character::EquipArmor(Armor* pArmor){
    
    delete mEquippedArmor;
    
    mEquippedArmor = pArmor;
}

int Character::getDefensePoints(){
        
    int item_def = mEquippedArmor->getDefensepts() + mEquippedWeapon->getDefensepts();
        
    return ((int) ((((int) mCON * 0.6) + ((int) mDEX * 0.1) + ((int) mSPD * 0.3 + item_def)) * mXP)/6);
}

int Character::getAttackPoints(){
    
    int item_att = mEquippedWeapon->getAttackpts();
        
    return (int) (((((int) mSTR * 0.6) + ((int) mDEX * 0.4) + item_att) * mXP)/2);
}

void Character::AddXP(int pXP){
    
    mXP += pXP;
    
    for(int i = 0; i < pXP; i++){
            
        mHP +=  (int) ((mHP)*(0.3));
        mMaxHP += (int) ((mMaxHP)*(0.3));
    }
}

int Character::getMaxHP(){
    
    return mMaxHP;
}

void Character::addHP(int pHP){
    
    mHP += pHP;
    
    if(mHP < 0){
        
        mHP = 0;
    }
    else if(mHP > mMaxHP){
        
        mHP = mMaxHP;
    }
}

void Character::setStrenght(int pStrenght){
    
    mSTR = pStrenght;
        
    int reajust = 100 - (mCON + mDEX + mSTR + mSPD);
        
    if(mSPD >= reajust){
           
        mSPD -= reajust;
    } 
    else if(mDEX >= reajust){
            
        mDEX -= reajust;
    }
    else if(mCON >= reajust){
            
        mCON -= reajust;
    }        
    else if(mSTR >= reajust){
            
        mSTR -= reajust;
    }
}

void Character::setSpeed(int pSpeed){
    
    mSPD = pSpeed;
        
    int reajust = 100 - (mCON + mDEX + mSTR + mSPD);
        
    if(mSTR >= reajust){
            
        mSTR -= reajust;
    }
    else if(mCON >= reajust){
            
        mCON -= reajust;
    }        
    else if(mDEX >= reajust){
            
        mDEX -= reajust;
    }
    else if(mSPD >= reajust){
           
        mSPD -= reajust;
    }    
}

void Character::setDexterity(int pDexterity){
    
    mDEX = pDexterity;
        
    int reajust = 100 - (mCON + mDEX + mSTR + mSPD);

    if(mCON >= reajust){
            
        mCON -= reajust;
    }
    else if(mSTR >= reajust){
            
        mSTR -= reajust;
    }
    else if(mSPD >= reajust){
           
        mSPD -= reajust;
    }
    else if(mDEX >= reajust){
            
        mDEX -= reajust;
    }
}

void Character::setConstitution(int pConstitution){
    
    mCON = pConstitution;
        
    int reajust = 100 - (mCON + mDEX + mSTR + mSPD);
    if(mDEX >= reajust){
            
        mDEX -= reajust;
    }
    else if(mSPD >= reajust){
           
        mSPD -= reajust;
    }
    else if(mSTR >= reajust){
            
        mSTR -= reajust;
    }
    else if(mCON >= reajust){
            
        mCON -= reajust;
    }
}

void Character::dropItem(int pKey){
    
    delete mInventory[pKey];
    mInventory.erase(pKey);
}

Item* Character::giveItem(int pKey){
    
    Item* aux;
    aux = mInventory[pKey];
    mInventory.erase(pKey);
    
    return aux;
}

void Character::setConsumable(Consumable* pConsumable){
    
    delete mConsumable;
    
    mConsumable = pConsumable;
}

void Character::useConsumable(Character* pCharacter){
    
    if(mConsumable != NULL){
        
        mConsumable->Consume(pCharacter);
        
        delete mConsumable;
        
        mConsumable = NULL;
    }
}

int Character::getWeaponRange(){
    
    return mEquippedWeapon->getRange();
}

Character::~Character() {
    
    delete mConsumable;  
    
    for(map<int, Item*>::iterator it = mInventory.begin(); it != mInventory.end(); it++){
        
       delete (*it).second;
    }
    
    delete mEquippedArmor;
    delete mEquippedWeapon;
}

