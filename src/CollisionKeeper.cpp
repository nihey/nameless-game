/* 
 * File:   CollisionKeeper.cpp
 * Author: Nihey
 * 
 * Created on 7 de Junho de 2012, 16:17
 */

#include "CollisionKeeper.h"

CollisionKeeper::CollisionKeeper() {
}

void CollisionKeeper::addCollidable(Collidable* pCollidable){
    
    for(vector<Collidable*>::iterator it = mKeeper.begin(); it != mKeeper.end(); it++){
        
        (*it)->addCollidable(pCollidable);
        pCollidable->addCollidable(*it);
    }
    mKeeper.push_back(pCollidable);
}

CollisionKeeper::~CollisionKeeper() {
}

