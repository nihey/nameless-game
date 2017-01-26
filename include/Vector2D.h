/* 
 * File:   Vector2D.h
 * Author: Nihey
 *
 * Created on 22 de Abril de 2012, 15:13
 */

#ifndef VECTOR2D_H
#define	VECTOR2D_H

#include <cstdlib>
#include <math.h>

class Vector2D {
    
    public:
    
        double x;
        double y;
        
        /**
         * @brief Instantiates a Vector in a 2D inteface with (X,Y)
         * 
         * @param pX Vector's X component
         * @param pY Vector's Y component
         */
        
        Vector2D(double pX, double pY);
        
        /**
         * @brief Returns vector's module
         * 
         * @return Vector's module
         */
        
        double getModule();
        
        /**
         * Destroys this
         */
        
        virtual ~Vector2D();

};

#endif	/* VECTOR2D_H */

