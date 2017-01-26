/* 
 * File:   Collidable.cpp
 * Author: Nihey
 * 
 * Created on 6 de Junho de 2012, 10:25
 */

#include "Collidable.h"

bool Collidable::Collides(Collidable* pCollidable){
    
    return mRealRectPos->Collides(pCollidable->mRealRectPos);
}

void Collidable::addCollidable(Collidable* pCollidable){
    
    mCollidables.push_back(pCollidable);
}

Collidable::~Collidable() {
    
    delete mCollidableRect;
    delete mRealRectPos;
}

