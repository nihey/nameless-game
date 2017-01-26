/* 
 * File:   Player.h
 * Author: Nihey
 *
 * Created on 4 de Julho de 2012, 14:48
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <sstream>

#include "NPC.h"
#include "HeroHUD.h"
#include "Hero.h"
#include "Button.h"
#include "Character.h"

#define TILESIZE 32

#define WRECTCOLOR 0, 0, 255

#define WALKPATH "res/button/walk.png"
#define ATKPATH "res/button/attack.png"
#define CONSPATH "res/button/consume.png"

#define DEATHPATH "res/death/skull.png"

#define DAMAGETIME 3000

#define ATTACKCOLOR 241, 41, 56 // PANTONE LIBRARY
#define CONSUMECOLOR 0, 173, 104 // PANTONE LIBRARY
#define BLACK 0, 0, 0

enum PlayerStatus { MENU = 999, WALK, ATTACK, CONSUME };

class Player : public NPC {
    
    private:
        
        Character* mCharacter;
        
        TTF_Font *mFont;
        
        Coordinate2D* mWayPosition;
        
        Image* mDeathImage;
        
        bool mFinishedMovement;
        
        MiniButton* mWalk;
        MiniButton* mAttack;
        MiniButton* mConsume;
        
        Arrow *mArrow;
        
        Rectangle* mWalkableRect;
        
        Rectangle* mHitBox;
        
        Rectangle* mConsumeBox;
        
        bool mWalkable;
    
        bool mFinished;
        
        bool mActive;
        
        PlayerStatus mStatus;
        
        Timer *mDamageTimer;
        
        SDL_Surface* mDamageImg;
        
        int mRange;
        
        vector<Player*> mEntities;
        
        /**
         * Attacks another player
         * 
         * @param pPlayer Player to be attacked
         */
        
        void Attack(Player *pPlayer);
        
        /**
         * Makes another player consume an item
         * 
         * @param pPlayer Player to have an item consumed
         */
        
        void Consume(Player *pPlayer);
        
    public:
        
        /**
         * Instantiates a player
         * 
         * @param pImagePath ImagePath from the player sprite
         */
        
        Player(string pImagePath, Character *pChar);
        
        /**
         * Handles the player event
         * 
         * @param pEvent Event to be handled
         */
        
        void HandleEvent(SDL_Event *pEvent);
        
        // Same as before, just kicking it to an upper level
        
        void setWeapon(Weapon* pWeapon){
            
            mCharacter->EquipWeapon(pWeapon);
            
            mRange = pWeapon->getRange();
            
            mHitBox->w = TILESIZE*((mRange*2) + 1);
            mHitBox->h = TILESIZE*((mRange*2) + 1);
        }
        void setArmor(Armor* pArmor){
            
            mCharacter->EquipArmor(pArmor);
        }
        void setConsumable(Consumable* pCons){
            
            mCharacter->setConsumable(pCons);
        }
        
        /**
         * Resets the player to be used again
         */
        
        void Reset();
        
        /**
         * Draw the player on the screen
         */
        
        void Draw();
        
        /**
         * Draw rectangles if player is active
         */
        
        void DrawWRect();
        
        /**
         * Draw button in case they are necessary
         */
        
        void DrawButtons();
        
        /**
         * Tells about player life situation
         * 
         * @return True if the player is alive
         */
        
        bool isAlive();
        
        void addEntity(Player* pPlayer);
        
        /**
         * Draw damage animation on character
         * 
         * @param pDamage damage to be dealt
         */
        
        void Damage(int pDamage);
        
        /**
         * Animation for HP gain
         * 
         * @param pGain Amount of HP that he will receive
         */
        
        void HPGain(int pGain);
        
        /**
         * Finish this player turn
         */
        
        void Finish();
        
        /**
         * Set Entity position
         * 
         * @param pX Position x component
         * @param pY Position y component
         */
        
        void setPosition(int pX, int pY);
        
        virtual ~Player();

};

#endif	/* PLAYER_H */

