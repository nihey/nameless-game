/* 
 * File:   HealthPotion.h
 * Author: Nihey
 *
 * Created on 6 de Junho de 2012, 16:59
 */

#ifndef HEALTHPOTION_H
#define	HEALTHPOTION_H

#include <cstdlib>

#include "Consumable.h"
#include "Character.h"
#include "Item.h"


class HealthPotion : public Item, public Consumable {
    
    private:
    
        int mRestorepts;
        
    public:
        
        /**
         * Instantiate a HealthPotion
         */
        
        HealthPotion();
    
        /**
         * Returns the number of points this potion restore
         * 
         * @return Number of points this potion will restore
         */
        
        int Restore();
        
        /**
         * This potion does not revive, so it will return 0
         * 
         * @return 0
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
    
        virtual ~HealthPotion();

};

#endif	/* HEALTHPOTION_H */

