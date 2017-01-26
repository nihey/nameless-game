/* 
 * File:   Circle.cpp
 * Author: Nihey
 * 
 * Created on 28 de Maio de 2012, 15:56
 */

#include "Circle.h"
#include "Vector2D.h"

Circle::Circle(double pX, double pY, double pR){
    
    x = pX;
    y = pY;
    r = pR;
}

bool Circle::isInside(int pX, int pY){
    
    Vector2D tvec(x - pX, y - pY);
    
    if(tvec.getModule() <= r){
        
        return true;
    }
    return false;
}

Circle::~Circle() {
}

