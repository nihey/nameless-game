/* 
 * File:   ScenarioEntity.cpp
 * Author: Nihey
 * 
 * Created on 12 de Junho de 2012, 16:42
 */

#include "ScenarioEntity.h"

ScenarioEntity::ScenarioEntity(string pImagePath, int pX, int pY) : Entity(pImagePath){
    
    mPosition->x = pX;
    mPosition->y = pY;
    
    RefreshPhysics();
}

void ScenarioEntity::Draw(){
    
    DrawImage();
}

ScenarioEntity::~ScenarioEntity() {
}

