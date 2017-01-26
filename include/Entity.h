/* 
 * File:   Entity.h
 * Author: Nihey
 *
 * Created on 5 de Maio de 2012, 14:44
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include <cstdlib>
#include <string.h>
#include <vector>

#include "SpriteSheet.h"
#include "Coordinate2D.h"
#include "Vector2D.h"
#include "Timer.h"
#include "Rectangle.h"

using namespace std;

class Entity {
    
    protected:

        SpriteSheet *mImage;
        
        Coordinate2D *mPosition;
        
        Vector2D *mSpeed;
        
        Timer *mMovementTimer;
        
        double mSpeedChangeAMT;
        
        Timer *mSpriteTimer;
        
        /**
         * @brief Draw the object's image on the screen; 
         */
        
        virtual void DrawImage();
        
        virtual void RefreshPhysics();
        
    public:
        
        /**
         * Instatiates an object of this class
         * 
         * @param pImagePath Image path to represent the Entity
         */
        
        Entity(string pImagePath);
        
        /**
         * Set Entity position
         * 
         * @param pX Position x component
         * @param pY Position y component
         */
        
        virtual void setPosition(double pX, double pY);
        
        /**
         * Changes Speed Change amount
         * 
         * @param pAMT Speed Change AMT to be set
         */
        
        void setSpeedChangeAMT(double pAMT);
        
        /**
         * Usable when go from paused to unpaused, reset character movement timer and other properties.
         */
        
        virtual void Resume();
        
        /**
         * Draw the image on the screen and apply further physical operations
         */
        
        virtual void Draw() = 0;
        
        virtual ~Entity();

        friend bool CompareY(Entity* pEntity1, Entity* pEntity2);
};

#endif	/* ENTITY_H */

