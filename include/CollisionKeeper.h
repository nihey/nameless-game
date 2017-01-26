/* 
 * File:   CollisionKeeper.h
 * Author: Nihey
 *
 * Created on 7 de Junho de 2012, 16:17
 */

#ifndef COLLISIONKeeper_H
#define	COLLISIONKeeper_H

#include <vector>

#include "Collidable.h"


class CollisionKeeper {
    
    private:
    
        vector<Collidable*> mKeeper;
        
    public:

        /**
         * Instantiates a collision Keeper
         */
        
        CollisionKeeper();
        
        /**
         * Add an element to the Keeper, collidables list may be updated.
         * 
         * @param pCollidable
         */
        
        void addCollidable(Collidable* pCollidable);

        virtual ~CollisionKeeper();

};

#endif	/* COLLISIONKeeper_H */

