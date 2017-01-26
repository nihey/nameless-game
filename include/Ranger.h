/* 
 * File:   Ranger.h
 * Author: Nihey
 *
 * Created on 5 de Maio de 2012, 17:08
 */

#ifndef RANGER_H
#define	RANGER_H

#include <cstdlib>
#include <string>

#include "Character.h"

using namespace std;

class Ranger : public Character {
    
    protected:

        int mAccurracy;
        
        /**
        * Returns Hero's defense points
        * 
        * @return Hero's defense points
        */

        int getDefensePoints();

        /**
        * Returns Hero's attack points
        * 
        * @return Hero's attack points
        */

        int getAttackPoints();
        
    public:
        
         /**
         * Attacks a character
         * 
         * @param pChartr Character to be attacked
         */
        
        int attackChartr(Character* pChartr);
        
        /**
        * Sets an alias to the hero, sets HP as 100, XP as 1 and other atributes as 25
        * 
        * @param pAlias Alias to be set to the Hero
        * @param pAccurracy Accurracy to be set to the hero, must be between 30 and 100
        */
        Ranger(string pAlias, int pAccurracy);

        /**
        * Sets an alias to the hero, as well as STR, SPD, DEX and CON, HP is set as 100 and XP as 1
        * 
        * @param pAlias Alias to be set to the Hero
        * 
        * @param pSTR STR to be set to the Hero
        * @param pSPD SPD to be set to the Hero
        * @param pDEX DEX to be set to the Hero
        * @param pCON CON to be set to the Hero
        * @param pAccurracy Accurracy to be set to the hero, must be between 30 and 100
        */

        Ranger(string pAlias, int pSTR, int pSPD, int pDEX, int pCON, int pAccurracy);

        virtual ~Ranger();

};

#endif	/* RANGER_H */

