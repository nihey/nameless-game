/* 
 * File:   CollisionMatrix.cpp
 * Author: Nihey
 * 
 * Created on 15 de Junho de 2012, 23:16
 */

#include "CollisionMatrix.h"

CollisionMatrix::CollisionMatrix(string pFilepath) {
    
    fstream input;
    
    int w, h, val;
    string in;
    
    input.open(pFilepath.c_str(), ifstream::in);
    
    getline(input, in, ',');
    
    w = atoi(in.c_str());
    
    getline(input, in, ',');
    
    h = atoi(in.c_str());
    
    // Setando o boundary externo
    mRects.push_back(new CollisionRect(0, 0, 1, h*TILESIZE));
    mRects.push_back(new CollisionRect(0, 0, w*TILESIZE, 1));
    mRects.push_back(new CollisionRect(0, h*TILESIZE, w*TILESIZE, 1));
    mRects.push_back(new CollisionRect(w*TILESIZE, 0, 1, h*TILESIZE));
    
    int k = 0;
    
    for(int i = 0; i < h; i++){
        
        for(int j = 0; j < w; j++){
            
            getline(input, in, ',');
            
            val = atoi(in.c_str());
            if(val != 0){
                
                k++;
            }
            else{
                
                if(k != 0){
                
                    mRects.push_back(new CollisionRect((j-k)*TILESIZE, i*TILESIZE, k*TILESIZE, TILESIZE));
                }
                
                k = 0;
            }
            
        }
        if(k != 0){
                
            mRects.push_back(new CollisionRect((w-k)*TILESIZE, i*TILESIZE, k*TILESIZE, TILESIZE));
            k = 0;
        }
    }
    
    input.close();
    
}

vector<CollisionRect *>::iterator CollisionMatrix::begin(){
    
    return mRects.begin();
}

vector<CollisionRect *>::iterator CollisionMatrix::end(){
    
    return mRects.end();
}

CollisionMatrix::~CollisionMatrix() {
    
    for(vector<CollisionRect *>::iterator it = mRects.begin(); it != mRects.end(); it++){
        
        delete *it;
    }
    mRects.clear();
}

