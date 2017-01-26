/* 
 * File:   DrawStream.h
 * Author: Nihey
 *
 * Created on 7 de Junho de 2012, 15:41
 */

#ifndef DRAWSTREAM_H
#define	DRAWSTREAM_H

#include <vector>
#include <algorithm>

#include "Entity.h"

using namespace std;

class DrawStream {
    
    vector<Entity*> mDrawableEntities;
    
public:
    
    /**
     * Instantiates a DrawStream, very useful when drawing multiple Entities
     */
    
    DrawStream();
    
    /**
     * Add an entity to be drawn
     * 
     * @param pEntity Entity to be drawn
     */
    
    void addEntity(Entity* pEntity);
    
    /**
     * Draw all entities on the screen
     */
    
    void Draw();
    
    virtual ~DrawStream();
private:

};

#endif	/* DRAWSTREAM_H */

