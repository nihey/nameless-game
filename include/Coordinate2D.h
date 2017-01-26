/* 
 * File:   Coordinate2D.h
 * Author: Nihey
 *
 * Created on 4 de Maio de 2012, 11:02
 */

#ifndef COORDINATE2D_H
#define	COORDINATE2D_H

#include <iostream>

class Coordinate2D {
    
    public:
        
        double x;
        double y;
        
        /**
         * A 2D Coordinate
         * 
         * @param pX X component
         * @param pY Y component
         */
        
        Coordinate2D(double pX, double pY);
        
        virtual ~Coordinate2D();
        
        bool operator==(const Coordinate2D *pA) const;
        bool operator==(const Coordinate2D pA) const;
        bool equals(const Coordinate2D *pA) const;
};

#endif	/* COORDINATE2D_H */

