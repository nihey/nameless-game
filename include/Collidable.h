/* 
 * File:   Collidable.h
 * Author: Nihey
 *
 * Created on 6 de Junho de 2012, 10:25
 */

#ifndef COLLIDABLE_H
#define	COLLIDABLE_H

#include <cstdlib>
#include <vector>

#include "Rectangle.h"

using namespace std;

class Collidable {
    
    protected:
        
        friend class WarpZone;
        
        vector<Collidable *> mCollidables;
        
        Rectangle *mCollidableRect;
        
        Rectangle *mRealRectPos;
        
    public:
        
        /**
         * Tests if this collidable collides another collidable
         * 
         * @param pCollidable Collidable to be tested
         * @return True if collision ocurred
         */
        
        virtual bool Collides(Collidable *pCollidable);
        
        /**
         * Adds a collidable to his list
         * 
         * @param pCollidable Collidable to be added
         */
        
        void addCollidable(Collidable* pCollidable);
        
        virtual ~Collidable();

};

#endif	/* COLLIDABLE_H */

