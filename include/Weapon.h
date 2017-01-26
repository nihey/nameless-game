/* 
 * File:   Item.h
 * Author: Nihey nihey.takizawa@gmail.com
 *
 * Created on 18 April 2012, 13:40
 * 
 * An specific kind of item to be used by a character
 */

#ifndef WEAPON_H
#define	WEAPON_H

#include "Item.h"

using namespace std;

class Weapon : public Item {
    
    protected:
        
        int mRange;
        
    public:
        /**
        *  @brief Sets item basic characteristics
        * 
        * Sets item Rank to F and apply additional characteristics
        * 
        * @param pName Name to be applied to the weapon
        * @param pPrice Price to be applied to the weapon
        * @param pAttackpts Attack points to be applied to the weapon, must be set between 5 and 50
        * @param pDefensepts Defense points to be applied to the weapon, must be lower than 5
        * @param pRange Range to be applied to the weapon, must be greater than 1
        */
        
        Weapon(string pName, double pPrice, int pAttackpts, int pDefensepts, int pRange);
        
        /**
        * @brief Sets item basic characteristics
        * 
        * @param pName Name to be applied to the weapon
        * @param pPrice Price to be applied to the weapon
        * @param pAttackpts Attack points to be applied to the weapon, must be set between 5 and 50
        * @param pDefensepts Defense points to be applied to the weapon, must be lower than 5
        * @param pRank Rank to be set for the weapon
        * @param pRange Range to be applied to the weapon, must be greater than 1
        */
        
        Weapon(string pName, double pPrice, int pAttackpts, int pDefensepts, char pRank, int pRange);
    
        /**
        * @brief Clones a weapon based on a pre-existent one
        * 
        * @param pWeapon Weapon to be cloned
        */
        
        Weapon(const Weapon* pWeapon);
        
        /**
        * @brief Returns weapon's Range
        * 
        * @return Weapon's Range
        */
        
        int getRange();
        
        /**
         * @brief Destroys this
         * 
         */
        
        virtual ~Weapon();
        

};

#endif	/* WEAPON_H */

