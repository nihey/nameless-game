/* 
 * File:   CollisionMatrix.h
 * Author: Nihey
 *
 * Created on 15 de Junho de 2012, 23:16
 */

#ifndef COLLISIONMATRIX_H
#define	COLLISIONMATRIX_H

#include <fstream>
#include <vector>

#include "CollisionRect.h"

#define TILESIZE 32

using namespace std;

class CollisionMatrix {
    
    vector<CollisionRect *> mRects;
    
public:
    
    /**
     * Load a collision matrix from a matrix file.
     * 
     * Matrix file must contain width and height in order, sepatated by a ',' character, and following by it's
     * matrix containing 0 (No collision) or any other number(collision of 32x32)
     * 
     * @param pFilepath Matrix file path to be loaded
     */
    
    CollisionMatrix(string pFilepath);
    
    /**
     * Get begin matrix iterator
     * 
     * @return Begin matrix iterator
     */
    
    vector<CollisionRect *>::iterator begin();
    
    /**
     * Get end matrix iterator
     * 
     * @return End iterator
     */
    
    vector<CollisionRect *>::iterator end();
    
    virtual ~CollisionMatrix();
private:

};

#endif	/* COLLISIONMATRIX_H */

