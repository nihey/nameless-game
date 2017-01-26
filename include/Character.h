/* 
 * File:   Character.h
 * Author: NLT
 *
 * Created on April 19, 2012, 12:38 AM
 * 
 * A Hero that will be used by the player
 */

#ifndef CHARACTER_H
#define	CHARACTER_H

#include <cstdlib>
#include <string.h>
#include <map>
#include <time.h>

#include "Item.h"
#include "Armor.h"
#include "Weapon.h"

#include "Consumable.h"
#include "Coordinate2D.h"

class Consumable;

class Character {
    
    protected:
        
        friend class Fighter;
        friend class Ranger;
        friend class Player;
        
        string mAlias;
        
        map<int ,Item *> mInventory;
        
        Consumable *mConsumable;
        
        int mHP;
        int mMaxHP;
        
        int mXP;
        
        int mSTR;
        int mSPD;
        int mDEX;
        int mCON;
    
        Weapon *mEquippedWeapon;
        Armor *mEquippedArmor;
        
       /**
        * Returns Hero's defense points
        * 
        * @return Hero's defense points
        */
        virtual int getDefensePoints();
        
       /**
        * Returns Hero's attack points
        * 
        * @return Hero's attack points
        */
        
        virtual int getAttackPoints();
            
    public:
        
       /**
        * @brief Sets an alias to the hero, sets HP as 100, XP as 1 and other atributes as 25
        * 
        * @param pAlias Alias to be set to the Hero
        */
        
        Character(string pAlias);
        
       /**
        * @brief Sets an alias to the hero, as well as STR, SPD, DEX and CON, HP is set as 100 and XP as 1
        * 
        * @param pAlias Alias to be set to the Hero
        * 
        * @param pSTR STR to be set to the Hero
        * @param pSPD SPD to be set to the Hero
        * @param pDEX DEX to be set to the Hero
        * @param pCON CON to be set to the Hero
        */
        
        Character(string pAlias, int pSTR, int pSPD, int pDEX, int pCON);

        /**
         * Returns Hero's Max HP
         * 
         * @return Hero's Max HP
         */
        
        int getMaxHP();
        
       /**
        * Returns Hero's HP
        * 
        * @return Hero's HP
        */
        
        int getHP();
        
        /**
        * Returns hero alias
        * 
        * @return Hero alias
        */
        
        string getName();
        
       /**
        * Add an item to Hero's inventory
        * 
        * @param pKey Key Associated to this Item
        * @param pItem Item to be added to Hero's inventory
        */
        
        void AddItem(int pKey, Item *pItem);
        
        /**
         * Drop a item associated with pKey
         * 
         * @param pKey Key associated with the item to be dropped
         */
        
        void dropItem(int pKey);
        
        /**
         * give an Item associated with pKey
         * 
         * @param pKey Key associated with the item
         */
        
        Item* giveItem(int pKey);
        
        /**
         * Set consumable to be used
         * 
         * @param pConsumable Consumable to be set
         */
        
        void setConsumable(Consumable *pConsumable);
        
        /**
         * pChar consumes this item
         * 
         * @param pCharacter Character to use this item
         */
        
        void useConsumable(Character *pCharacter);
        
        /**
        * Equips a weapon
        * 
        * @param pWeapon Weapon to be equipped
        */
        
        void EquipWeapon(Weapon *pWeapon);
        
        /**
        * Equips an armor
        * 
        * @param pArmor Armor to be equipped
        */
        
        void EquipArmor(Armor *pArmor);
        
        /**
        * Attacks another Hero, there is a chance to have a critical hit, miss or normal damage.
        * 
        * @param pHero Hero that will be attacked
         * 
         * @return Amount of damage dealt
        */
        
        virtual int attackChartr(Character *pChartr) = 0;
        
        /**
        * Adds XP to this Hero
        * 
        * @param pXP XP to be added
        */
        
        void AddXP(int pXP);
        
        /**
        * Sets Hero's STR
        * 
        * @param pStrenght STR to be set
        */
        
        void setStrenght(int pStrenght);
        
        /**
        * Sets Hero's SPD
        * 
        * @param pSpeed SPD to be set
        */
        
        void setSpeed(int pSpeed);
        
        /**
        * Sets Hero's DEX
        * 
        * @param pDexterity DEX to be set
        */
        
        void setDexterity(int pDexterity);

        /**
        * Sets Hero's CON
        * 
        * @param pConstitution CON to be set
        */
        
        void setConstitution(int pConstitution);
        
        /**
         * Add a quantity of HP to the Hero
         * 
         * @param pHP HP to be added
         */
        
        void addHP(int pHP);
        
        /**
         * Returns equipped weapon range
         * 
         * @return Equipped weapon range
         */
        
        int getWeaponRange();
        
        /**
         * Destroys this
         * 
         */
        
        virtual ~Character();
        
};

#endif	/* CHARACTER_H */

