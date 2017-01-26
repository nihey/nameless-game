/* 
 * File:   Coordinate2D.cpp
 * Author: Nihey
 * 
 * Created on 4 de Maio de 2012, 11:02
 */

#include <stdlib.h>

#include "Coordinate2D.h"

Coordinate2D::Coordinate2D(double pX, double pY) {
    
    x = pX;
    y = pY;
}

inline double ABS(double pABS){
    
    if(pABS < 0){
        
        return -pABS;
    }
    return pABS;
}

bool Coordinate2D::operator ==(const Coordinate2D *pA) const{

    double xdist = ABS(x - pA->x);
    double ydist = ABS(y - pA->y);
    
    return ((xdist < 20) && (ydist < 20));
}

bool Coordinate2D::operator ==(const Coordinate2D pA) const{

    double xdist = ABS(x - pA.x);
    double ydist = ABS(y - pA.y);
    
    return ((xdist < 20) && (ydist < 20));
}

bool Coordinate2D::equals(const Coordinate2D *pA) const{

    double xdist = ABS(x - pA->x);
    double ydist = ABS(y - pA->y);
    
    return ((xdist < 3) && (ydist < 3));
}

Coordinate2D::~Coordinate2D() {
}

