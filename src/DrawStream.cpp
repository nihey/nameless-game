/* 
 * File:   DrawStream.cpp
 * Author: Nihey
 * 
 * Created on 7 de Junho de 2012, 15:41
 */

#include "DrawStream.h"

DrawStream::DrawStream() {
}

void DrawStream::addEntity(Entity* pEntity){
    
    mDrawableEntities.push_back(pEntity);
}

bool CompareY(Entity* pEntity1, Entity* pEntity2){
    
    if((pEntity1->mPosition->y + pEntity1->mImage->getSpriteHeight()) == (pEntity2->mPosition->y + pEntity2->mImage->getSpriteHeight())){
        
        return ((pEntity1->mPosition->x + pEntity1->mImage->getSpriteWidth()) < (pEntity2->mPosition->x + pEntity2->mImage->getSpriteWidth()));
    }
    return ((pEntity1->mPosition->y + pEntity1->mImage->getSpriteHeight()) < (pEntity2->mPosition->y + pEntity2->mImage->getSpriteHeight()));
}

void DrawStream::Draw(){
    
    sort(mDrawableEntities.begin(), mDrawableEntities.end(), CompareY);
    for(vector<Entity*>::iterator it = mDrawableEntities.begin(); it != mDrawableEntities.end(); it++){
        
        (*it)->Draw();
    }
}

DrawStream::~DrawStream() {
}

