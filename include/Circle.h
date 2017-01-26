/* 
 * File:   Circle.h
 * Author: Nihey
 *
 * Created on 28 de Maio de 2012, 15:56
 */

#ifndef CIRCLE_H
#define	CIRCLE_H

class Circle {
public:
    
    double x;
    double y;
    double r;
    
    /**
     * Instantiares a Circle
     * 
     * @param pX Circle x position
     * @param pY Circle y position
     * @param pR Circle radius
     */
    
    Circle(double pX, double pY, double pR);
    
    /**
     * Tests if coordinate (x, y) is inside this circle
     * 
     * @param pX coordinate x component
     * @param pY coordinate y component
     * @return True if the coordinate is inside this circle
     */
    
    bool isInside(int pX, int pY);
    
    virtual ~Circle();
private:

};

#endif	/* CIRCLE_H */

