/* 
 * File:   Fighter.h
 * Author: Nihey
 *
 * Created on 5 de Maio de 2012, 16:33
 */

#ifndef FIGHTER_H
#define	FIGHTER_H

#include <cstdlib>

#include "Character.h"

class Fighter : public Character {
    
    protected:
        
        int mPower;
    
        /**
        * Returns Hero's attack points
        * 
        * @return Hero's attack points
        */        
        
        int getAttackPoints();
        
        /**
        * Returns Hero's defense points
        * 
        * @return Hero's defense points
        */

        int getDefensePoints();
    
    public:
        
        /**
        * Sets an alias to the hero, sets HP as 100, XP as 1 and other atributes as 25
        * 
        * @param pAlias Alias to be set to the Hero
        * @param pPower Power to be set to the hero, must be between 30 and 100
        */
        Fighter(string pAlias, int pPower);
        
        /**
        * Sets an alias to the hero, as well as STR, SPD, DEX and CON, HP is set as 100 and XP as 1
        * 
        * @param pAlias Alias to be set to the Hero
        * 
        * @param pSTR STR to be set to the Hero
        * @param pSPD SPD to be set to the Hero
        * @param pDEX DEX to be set to the Hero
        * @param pCON CON to be set to the Hero
        * @param pPower Power to be set to the hero, must be between 30 and 100
        */
        
        Fighter(string pAlias, int pSTR, int pSPD, int pDEX, int pCON, int pPower);
        
        /**
         * Attacks a character
         * 
         * @param pChartr Character to be attacked
         */
        
        int attackChartr(Character* pChartr);
        
        /***
         * Destroys this
         */
        
        virtual ~Fighter();
};


#endif	/* FIGHTER_H */

