/* 
 * File:   Item.h
 * Author: Nihey nihey.takizawa@gmail.com
 *
 * Created on 18  April  2012, 12:46
 * 
 * An item to be used by a character
 */

#ifndef ITEM_H

#include <cstdlib>
#include <string>
#include <iostream>

#define	ITEM_H

using namespace std;

class Item {

    private:
        
        string mName;
        double mPrice;
        char mRank;
        
    protected:
        
        int mAttackpts;
        int mDefensepts;
        
    public:
        /**
        * @brief Sets item basic characteristics
        * 
        * Sets item Rank to F and apply additional characteristics
        * 
        * @param pName Name to be applied to the item
        * @param pPrice Price to be applied to the item
        * @param pAttackpts Attack points to be applied to the item, must be set between 5 and 50
        * @param pDefensepts Defense points to be applied to the item, must be set between 1 and 30
        */
        Item(string pName, double pPrice, int pAttackpts, int pDefensepts);
        
        /**
        * @brief Sets item basic characteristics
        * 
        * @param pName Name to be applied to the item
        * @param pPrice Price to be applied to the item
        * @param pAttackpts Attack points to be applied to the item, must be set between 5 and 50
        * @param pDefensepts Defense points to be applied to the item, must be set between 1 and 30
        * @param pRank Rank to be set for the item
        */
        
        Item(string pName, double pPrice, int pAttackpts, int pDefensepts, char pRank);
        
        /**
        * @brief Clones an Item based on a pre-exitant one
        * 
        * @param pItem Item to be cloned
        */
        
        Item(const Item* pItem);
        
        /**
        * @brief Returns item's name
        * 
        * @return Item's name
        */
        
        string getName();
        
        /**
        * @brief Returns item's price
        * 
        * @return Item's price
        */
        
        double getPrice();
        
        /**
        * @brief Returns item's Attack points
        * 
        * @return Item's Attack points
        */
        
        int getAttackpts();
        
        /**
        * @brief Returns item's Defense points
        * 
        * @return Item's Defense points
        */
        
        int getDefensepts();
         
        /**
        * @brief Returns item's rank
        * 
        * @return Item's rank
        */
        
        char getRank();
        
        /**
         * @brief Destroys this
         * 
         */
        
        virtual ~Item();
        
};

#endif	/* ITEM_H */

