/* 
 * File:   Particle.cpp
 * Author: Nihey
 * 
 * Created on 11 de Maio de 2012, 16:24
 */

#include "Particle.h"

Particle::Particle(string pImagePath, unsigned int pLifetime) : Entity(pImagePath){
    
    mLifetime = SDL_GetTicks() + pLifetime;
}

bool Particle::isAlive(){
    
    if(SDL_GetTicks() > mLifetime){
        
        return false;
    }
    return true;
}

void Particle::setSpeed(double pX, double pY){
    
    mSpeed->x = pX;
    mSpeed->y = pY;
}

Vector2D* Particle::getSpeed(){
    
    return mSpeed;
}

void Particle::Draw(){
    
    RefreshPhysics();
    
    DrawImage();
}

void Particle::Reset(int pLifetime){
    
    mLifetime = SDL_GetTicks() + pLifetime;
}

Particle::~Particle() {
}

