/* 
 * File:   Rectangle.h
 * Author: Nihey
 *
 * Created on 9 de Maio de 2012, 17:07
 */

#ifndef RECTANGLE_H
#define	RECTANGLE_H

#include <cstdlib>
#include <SDL.h>

class Rectangle {
public:
    
    double x;
    double y;
    double w;
    double h;
    
    /**
     * Instantiates a Rectangle
     * 
     * @param pX Rectangle X position
     * @param pY Rectangle Y position
     * @param pW Rectangle Width
     * @param pH Rectangle Height
     */
    
    Rectangle(double pX, double pY, double pW, double pH);
    
    /**
     * Tests if this rectangle collides with another one
     * 
     * @param pRect Rectangle to do the test
     * @return True if this rectangle collides with pRect
     */
    
    bool Collides(Rectangle* pRect);
    
    /**
     * Fills this rectangle with the given color
     * 
     * @param pR Color Red Component
     * @param pG Color Green Component
     * @param pB Color Blue Component
     */
    
    void FillRectangle(Uint8 pR, Uint8 pG, Uint8 pB);
    
    /**
     * Tests if the Coordinate (x, y) is inside this rectangle
     * 
     * @param pX Coordinate x component
     * @param pY Coordinate y component
     * @return True is the coordinate is inside this rectangle
     */
    
    bool isInside(int pX, int pY);
    
    /**
     * @return SDL version of the rectangle
     */
    
    SDL_Rect getSDLRect();
    
    /**
     * Makes rectangle be filled with glowish color
     */
    
    void Mutate();
    
    virtual ~Rectangle();

};

#endif	/* RECTANGLE_H */

