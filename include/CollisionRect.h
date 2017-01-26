/* 
 * File:   CollisionRect.h
 * Author: Nihey
 *
 * Created on 10 de Junho de 2012, 17:16
 * 
 * This rectangle should keep collidables out of a way
 */

#ifndef COLLISIONRECT_H
#define	COLLISIONRECT_H

#include "Rectangle.h"
#include "Collidable.h"


class CollisionRect : public Collidable {
    
    public:
     /**
     * Instantiates a Collision Rectangle
     * 
     * @param pX Rectangle X position
     * @param pY Rectangle Y position
     * @param pW Rectangle Width
     * @param pH Rectangle Height
     */
    
    CollisionRect(double pX, double pY, double pW, double pH);
    
    virtual ~CollisionRect();

};

#endif	/* COLLISIONRECT_H */

