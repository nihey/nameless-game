/* 
 * File:   Item.h
 * Author: Nihey nihey.takizawa@gmail.com
 *
 * Created on 18 April 2012, 12:46
 * 
 * An item to be used by a character
 */

#include "Item.h"

Item::Item(string pName, double pPrice, int pAttackpts, int pDefensepts) {
    
    mName = pName;
    mPrice = pPrice;
        
    if(pAttackpts < 5){
            
        pAttackpts =  5;
    }
    if(pAttackpts > 50){
            
        pAttackpts = 50;
    }
    mAttackpts = pAttackpts;
        
    if(pDefensepts < 1){
            
        pDefensepts = 1;
    }
    if(pDefensepts > 30){
         
        pDefensepts = 30;
    }
       
    mDefensepts = pDefensepts;
    mRank = 'F';   
}

Item::Item(string pName, double pPrice, int pAttackpts, int pDefensepts, char pRank){
    
    mName = pName;
    mPrice = pPrice;
        
    if(pAttackpts < 5){
            
        pAttackpts =  5;
    }
    if(pAttackpts > 50){
            
        pAttackpts = 50;
    }
    mAttackpts = pAttackpts;
        
    if(pDefensepts < 1){
            
        pDefensepts = 1;
    }
    if(pDefensepts > 30){
         
        pDefensepts = 30;
    }
       
    mDefensepts = pDefensepts;
    mRank = pRank;  
    
}

Item::Item(const Item* pItem){
    
    mName = pItem->mName;
    mPrice = pItem->mPrice;
    mAttackpts = pItem->mAttackpts;
    mDefensepts = pItem->mDefensepts;
    mRank = pItem->mRank;
    
}

string Item::getName(){
    
    return mName;
}

double Item::getPrice(){
    
    return mPrice;
}

int Item::getAttackpts(){
    
    return mAttackpts;
}

int Item::getDefensepts(){
    
    return mDefensepts;
}

char Item::getRank(){
    
    return mRank;
}

Item::~Item() {
    
}

