/* 
 * File:   Armor.h
 * Author: NLT
 *
 * Created on 18 de Abril de 2012, 16:34
 */

#ifndef ARMOR_H

#define	ARMOR_H

#include "Item.h"

class Armor : public Item {
    
    protected:
        
        int mFlexibility;
    
    public:
        
        /**
        * @brief Sets item basic characteristics
        * 
        * Sets item Rank to F and apply additional characteristics
        * 
        * @param pName Name to be applied to the armor
        * @param pPrice Price to be applied to the armor
        * @param pDefensepts Defense points to be applied to the armor, must be set between 1 and 30
        * @param pFlexibility Flexibility to be applied to the armor
        */
    
        Armor(string pName, double pPrice, int pDefensepts, int pFlexibility);
        
        /**
        * @brief Sets item basic characteristics
        * 
        * @param pName Name to be applied to the armor
        * @param pPrice Price to be applied to the armor
        * @param pDefensepts Defense points to be applied to the armor, must be set between 1 and 30
        * @param pRank Rank to be set for the armor
        * @param pFlexibility Flexibility to be applied to the armor
        */
    
        Armor(string pName, double pPrice, int pDefensepts, char pRank, int pFlexibility);
        
        /**
        * @brief Clones an Armor based on a pre-existant one
        * 
        * @param pArmor Armor to be cloned
        */
        
        Armor(Armor* pArmor);
        
        /**
        * @brief Returns armor's flexibility
        * 
        * @return Armor's flexibity
        */
        
        int getFlexibility();      
        
        /**
         * @brief Destroys this
         */
        
        virtual ~Armor();

};

#endif	/* ARMOR_H */

