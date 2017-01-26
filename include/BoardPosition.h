/* 
 * File:   BoardPosition.h
 * Author: Nihey
 *
 * Created on 6 de Junho de 2012, 15:16
 */

#ifndef BOARDPOSITION_H
#define	BOARDPOSITION_H

#include "Character.h"
#include "Coordinate2D.h"


class BoardPosition {
    
    private:
    
        Coordinate2D *mPosition;
        
        Character *mOccupied;
        
    public:

        /**
         * Instantiate a BoardPosition
         * 
         * @param pCharacter Character associated to the position
         * @param pX X board component, should be positive 
         * @param pY Y board component, should be positive
         */
        
        BoardPosition(Character* pCharacter, int pX, int pY);

        
        
        /**
         * Return position
         * 
         * @return Return board position
         */
        
        Coordinate2D* getPosition();
        
        /**
         * Change character position on the scree
         * 
         * @param pX X component
         * @param pY Y component
         */
        
        void setPosition(int pX, int pY);
        
        /**
         * Return character at this position
         * 
         * @return Character associated to this position
         * 
         * *** Altered from the default diagram block ***
         * 
         * Reason: There's only one character associated with this board position
         * therefore, there's no way to return other character if not mOccupied.
         * it must be treated on a higher level class.
         */
        
        Character* getOccup();
        
        virtual ~BoardPosition();

};

#endif	/* BOARDPOSITION_H */

