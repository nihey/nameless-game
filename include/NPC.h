/* 
 * File:   NPC.h
 * Author: Nihey
 *
 * Created on 7 de Maio de 2012, 15:45
 */

#ifndef NPC_H
#define	NPC_H

#include <cstdlib>
#include <vector>
#include <ctime>

#include "HUDBar.h" // Apenas para obter a fonte e o tamanho
#include "Entity.h"
#include "Collidable.h"

#define TALKTIME 3000

#define SIZE 10

#define PHRASESOUNDPATH "res/chunk/phrase.mp3"

using namespace std;

class NPC : public Entity, public Collidable{

    protected:
        
        vector<Coordinate2D *> mWaypoints;
        
        Coordinate2D* mLastPosition;
        
        int mCurrentWaypoint;
        
        bool mCycleWaypoints;
        
        bool mWanderer;
        
        bool mTalkable;
        
        bool mTalking;
        
        int talktime;
        
        Timer *mTalktimer;
        
        vector<Image *>::iterator mPhraseIndex;
        
        vector<Image *> mPhrases;
        
        /**
         * Forces NPC to follow waypoints in mWaypoints
         */
        
        void FollowWaypoints();        
        
        /**
         * Forces NPC to wander
         */
        
        void Wander();
        
    public:
    
        /**
         * Instantiates an object of this class
         * 
         * @param pImagePath Image path to represent the NPC
         */
        
        NPC(string pImagePath);

        /**
         * Instantiates a NPC with all these atributes at once
         * 
         * @param pImagePath Image path to represent the NPC
         * @param pX NPC x position on the screen
         * @param pY NPC y position on the screen
         * @param pAMT NPC speed change amount
         * @param pWander NPC wander mode
         * @param pCycle NPC cycle waypoints mode
         * @param pTalkable True in case of NPC is talkable
         * @param pPhrase Talk Phrase
         * @param pColor Color of the Phrase that will be drawn
         */
        
        NPC(string pImagePath, int pX, int pY, double pAMT, bool pWander, bool pCycle, string pPhrase, SDL_Color pColor);
        
        /**
         * Instantiates a NPC with all these atributes at once
         * 
         * @param pImagePath Image path to represent the NPC
         * @param pX NPC x position on the screen
         * @param pY NPC y position on the screen
         * @param pAMT NPC speed change amount
         * @param pWander NPC wander mode
         * @param pCycle NPC cycle waypoints mode
         */
        
        NPC(string pImagePath, int pX, int pY, double pAMT, bool pWander, bool pCycle);
        
        /**
         * Adds a waypoint to be followed
         * 
         * @param pWaypoint Waypoint to follow
         */
        
        void addWayPoint(Coordinate2D *pWaypoint);
        
        /**
         * Draw the image on the screen and update character physics
         */
        
        void Draw();
        
        /**
         * Sets whether the NPC should Wander through the screen or not
         * 
         * @param pWander Wanderer Mode
         */
        
        void setWandererMode(bool pWander);
        
        /**
         * Sets whether the NPC must cycle the waypoints or not
         * 
         * @param pCycle Must cycle waypoints
         */
        
        void setCycleWaypoints(bool pCycle);
        
        /**
         * Tests if this NPC collides another one and apply further properties
         * 
         * @param pCollidable Collidable to test
         * @return This NPC collides pCollidable
         */
        
        bool Collides(Collidable* pCollidable);
        
        /**
         * Add a Phrase to be said by this NPC
         * 
         * NOTE: This may work only on talkable NPCs
         * 
         * @param pPhrase Phrase to be said
         * @param pColor Color to be displayed
         */
        
        void addPhrase(string pPhrase, SDL_Color pColor);
        
        /**
         * Draw NPC's Phrase on the screen
         */
        
        void DrawPhrase();
        
        virtual ~NPC();

};

#endif	/* NPC_H */

