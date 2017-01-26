/* 
 * File:   RevivePotion.h
 * Author: Nihey
 *
 * Created on 6 de Junho de 2012, 16:26
 */

#ifndef REVIVEPOTION_H
#define	REVIVEPOTION_H

#include <cstdlib>

#include "Consumable.h"
#include "Character.h"
#include "Item.h"


class RevivePotion : public Item, public Consumable {
    
    private:
        
        int mRevivePts;
    
    public:
        
        /**
         * Instantiate a Revive Potion with random 
         */
        
        RevivePotion();

        /**
         * This potions does not restore points
         * 
         * @return 0
         */
        
        int Restore();
        
        /**
         * Returns the number of points this potion restore
         * 
         * @return Number of points this potion will restore
         */
        
        int Revive();
        
        /**
         * Tests if pChar is able to use this potion
         * 
         * @param pChar Char to be tested
         * @return true if pChar is able to use this potion
         */
        
        bool ConsumableBy(Character* pChar);
        
        /**
         * Apply this item effects to pChar
         * 
         * @param pChar Char affected by this item
         */
        
        void Consume(Character* pChar);
        
        virtual ~RevivePotion();
        
private:

};

#endif	/* REVIVEPOTION_H */

