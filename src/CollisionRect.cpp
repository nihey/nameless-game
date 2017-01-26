/* 
 * File:   CollisionRect.cpp
 * Author: Nihey
 * 
 * Created on 10 de Junho de 2012, 17:16
 */

#include "CollisionRect.h"

CollisionRect::CollisionRect(double pX, double pY, double pW, double pH){
    
    mCollidableRect = new Rectangle(pX, pY, pW, pH);
    mRealRectPos = new Rectangle(pX, pY, pW, pH);
}

CollisionRect::~CollisionRect() {
}

