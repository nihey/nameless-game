/* 
 * File:   Vector2D.cpp
 * Author: Nihey
 * 
 * Created on 22 de Abril de 2012, 15:13
 */

#include "Vector2D.h"

Vector2D::Vector2D(double pX, double pY){
    
    x = pX;
    y = pY;
   
}

double Vector2D::getModule(){
    
    return sqrt((x * x) + (y * y));
}

Vector2D::~Vector2D() {

}

