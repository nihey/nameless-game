/* 
 * File:   BoardPosition.cpp
 * Author: Nihey
 * 
 * Created on 6 de Junho de 2012, 15:16
 */

#include "BoardPosition.h"

BoardPosition::BoardPosition(Character* pCharacter, int pX, int pY){
    
    mPosition = new Coordinate2D(pX, pY);
    
    mOccupied = pCharacter;
}

Coordinate2D *BoardPosition::getPosition(){
    
    return mPosition;
}

void BoardPosition::setPosition(int pX, int pY){
    
    mPosition->x = pX;
    mPosition->y = pY;
}



Character *BoardPosition::getOccup(){
    
    return mOccupied;
}

BoardPosition::~BoardPosition() {
    
    delete mPosition;
}

