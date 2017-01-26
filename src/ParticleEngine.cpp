/* 
 * File:   ParticleEngine.cpp
 * Author: Nihey
 * 
 * Created on 11 de Maio de 2012, 16:51
 */

#include "ParticleEngine.h"

ParticleEngine::ParticleEngine(string pImagePath, unsigned int pMaxParticles, unsigned int pLifetime){
    
    srand(time(NULL));
    
    mGravityTimer = new Timer();
    
    mImagePath = pImagePath;
    
    mMaxParticles = pMaxParticles;

    mOrigin = new Coordinate2D(0.0, 0.0);
    
    mConvergentPoint = new Coordinate2D(0.0, 0.0);
    
    mDivergentPoint = new Coordinate2D(0.0, 0.0);
    
    mConvergenceStrenght = 0.0;
    
    mDivergenceStrenght = 0.0;
    
    mConverge = false;
    
    mDiverge = false;
    
    mEfficient = false;
    
    mOriginSpeed = new Vector2D(0.0, 0.0);
    mGravity = new Vector2D(0.0, 0.0);
    
    mLifetime = pLifetime;
    
    mRandLifetime = 0;
    
    mRandOriginX = 0;
    mRandOriginY = 0;
    
    mRandOriginSPDX = 0;
    mRandOriginSPDY = 0;
    
    int trlife = 0;
    
    if(mRandLifetime != 0){
        
        trlife = (rand()%(2*mRandLifetime)) - mRandLifetime;
    }
    
    double trorx = (((double)((rand()%2000)/(1000.0)))*mRandOriginX) - mRandOriginX;
    double trory = (((double)((rand()%2000)/(1000.0)))*mRandOriginY) - mRandOriginY;
    
    double trorspdx = (((double)((rand()%2000)/(1000.0)))*mRandOriginSPDX) - mRandOriginSPDX;
    double trorspdy = (((double)((rand()%2000)/(1000.0)))*mRandOriginSPDY) - mRandOriginSPDY;
    
    for(int i = 0; i < mMaxParticles; i++){
        
        mParticles.push_back(new Particle(mImagePath, mLifetime + trlife));
        
        mParticles.at(i)->setPosition(mOrigin->x + trorx, mOrigin->y + trory);
        mParticles.at(i)->setSpeed(mOriginSpeed->x + trorspdx, mOriginSpeed->y + trorspdy);
    }
}

void ParticleEngine::Draw(){
    
    int elapsed = mGravityTimer->getElapsed();
    
    elapsed /= 10;
    
    double xplusamt = mGravity->x * elapsed;
    double yplusamt = mGravity->y * elapsed;
    
    int trlife = 0;
    
    double trorx = (((double)((rand()%2000)/(1000.0)))*mRandOriginX) - mRandOriginX;
    double trory = (((double)((rand()%2000)/(1000.0)))*mRandOriginY) - mRandOriginY;

    double trorspdx = (((double)((rand()%2000)/(1000.0)))*mRandOriginSPDX) - mRandOriginSPDX;
    double trorspdy = (((double)((rand()%2000)/(1000.0)))*mRandOriginSPDY) - mRandOriginSPDY;
            
    
    for(int i = 0; i < mMaxParticles; i++){
        
        if(mParticles.at(i)->isAlive()){
            if(mConverge){
                
                Vector2D convergentvec(0, 0);
                
                convergentvec.x = mConvergentPoint->x - mParticles.at(i)->mPosition->x;
                convergentvec.y = mConvergentPoint->y - mParticles.at(i)->mPosition->y;
                
                double module = convergentvec.getModule();
                
                convergentvec.x /= module;
                convergentvec.y /= module;
                
                convergentvec.x *= mConvergenceStrenght;
                convergentvec.y *= mConvergenceStrenght;
                
                mParticles.at(i)->getSpeed()->x += convergentvec.x;
                mParticles.at(i)->getSpeed()->y += convergentvec.y;
            }
            if(mDiverge){
                
                Vector2D divergentvec(0, 0);
                
                divergentvec.x = mDivergentPoint->x - mParticles.at(i)->mPosition->x;
                divergentvec.y = mDivergentPoint->y - mParticles.at(i)->mPosition->y;
                
                double module = divergentvec.getModule();
                
                divergentvec.x /= module;
                divergentvec.y /= module;
                
                divergentvec.x *= -mDivergenceStrenght;
                divergentvec.y *= -mDivergenceStrenght;
                
                mParticles.at(i)->getSpeed()->x += divergentvec.x;
                mParticles.at(i)->getSpeed()->y += divergentvec.y;
            }
            
            mParticles.at(i)->getSpeed()->x += xplusamt;
            mParticles.at(i)->getSpeed()->y += yplusamt;
            mParticles.at(i)->Draw();
        }
        else{
            
            if(mRandLifetime != 0){
        
                trlife = (rand()%(2*mRandLifetime)) - mRandLifetime;
            }
            
            trorx = (((double)((rand()%2000)/(1000.0)))*mRandOriginX) - mRandOriginX;
            trory = (((double)((rand()%2000)/(1000.0)))*mRandOriginY) - mRandOriginY;

            trorspdx = (((double)((rand()%2000)/(1000.0)))*mRandOriginSPDX) - mRandOriginSPDX;
            trorspdy = (((double)((rand()%2000)/(1000.0)))*mRandOriginSPDY) - mRandOriginSPDY;            
            
            if(!mEfficient){
             
                delete mParticles.at(i);
                mParticles.at(i) = new Particle(mImagePath, mLifetime + trlife);
            }
            else{
                
                mParticles.at(i)->Reset(mLifetime + trlife);
            }
                mParticles.at(i)->setPosition(mOrigin->x + trorx, mOrigin->y + trory);
                mParticles.at(i)->setSpeed(mOriginSpeed->x + trorspdx, mOriginSpeed->y + trorspdy);
            
        }
    }
    
    mGravityTimer->Refresh();
}

void ParticleEngine::setLifetime(int pLifetime){
    
    mLifetime = pLifetime;
}

void ParticleEngine::setGravity(double pX, double pY){
    
    mGravity->x = pX;
    mGravity->y = pY;
}

void ParticleEngine::setOrigin(double pX, double pY){
    
    mOrigin->x = pX;
    mOrigin->y = pY;
    
    for(int i = 0; i < mMaxParticles; i++){
     
        mParticles.at(i)->setPosition(pX, pY);        
    }
    
}

void ParticleEngine::setSpeed(double pX, double pY){
    
    mOriginSpeed->x = pX;
    mOriginSpeed->y = pY;

    for(int i = 0; i < mMaxParticles; i++){
        
        mParticles.at(i)->setSpeed(pX, pY);
    }
}

void ParticleEngine::setRandLifetime(int pRandLifetime){
    
    mRandLifetime = pRandLifetime;
}

void ParticleEngine::setRandOrigin(double pX, double pY){

    mRandOriginX = pX;
    mRandOriginY = pY;
}

void ParticleEngine::setRandSPD(double pX, double pY){

    mRandOriginSPDX = pX;
    mRandOriginSPDY = pY;
}

void ParticleEngine::setImagePath(string pImagePath){
    
    mImagePath = pImagePath;
}

void ParticleEngine::setConvergentPoint(double pX, double pY){
    
    mConvergentPoint->x = pX;
    mConvergentPoint->y = pY;
}

void ParticleEngine::setConvergible(bool pConvergible){
    
    mConverge = pConvergible;
}

void ParticleEngine::setConvergenceStrenght(double pStrenght){
    
    mConvergenceStrenght = pStrenght;
}

void ParticleEngine::setDivergentPoint(double pX, double pY){
    
    mDivergentPoint->x = pX;
    mDivergentPoint->y = pY;
}

void ParticleEngine::setDivergible(bool pDivergible){
    
    mDiverge = pDivergible;
}

void ParticleEngine::setDivergenceStrenght(double pStrenght){
    
    mDivergenceStrenght = pStrenght;
}

double ParticleEngine::getRandOriginX(){
    
    return mRandOriginX;
}

double ParticleEngine::getRandOriginY(){
    
    return mRandOriginY;
}

double ParticleEngine::getRandSPDX(){
    
    return mRandOriginSPDX;
}

double ParticleEngine::getRandSPDY(){
    
    return mRandOriginSPDY;
}

int ParticleEngine::getRandLifetime(){
    
    return mRandLifetime;
}

bool ParticleEngine::Converge(){
    
    return mConverge;
}

bool ParticleEngine::Diverge(){
    
    return mDiverge;
}

void ParticleEngine::setEfficientMode(bool pEfficient){
    
    mEfficient = pEfficient;
}

bool ParticleEngine::getEfficientMode(){
    
    return mEfficient;
}

void ParticleEngine::ResumeAll(){
    
    for(int i = 0; i < mMaxParticles; i++){
        
        mParticles.at(i)->Resume();
    }
}

ParticleEngine::~ParticleEngine() {
    
    delete mGravityTimer;
    delete mOrigin;
    delete mConvergentPoint;
    delete mDivergentPoint;
    delete mOriginSpeed;
    delete mGravity;
    
    for(int i = 0; i < mMaxParticles; i++){
        
        delete mParticles.at(i);
    }
    mParticles.clear();
}

