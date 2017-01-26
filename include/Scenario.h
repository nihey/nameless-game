/* 
 * File:   Scenario.h
 * Author: Nihey
 *
 * Created on 16 de Junho de 2012, 11:45
 */

#ifndef SCENARIO_H
#define	SCENARIO_H

#include <vector>
#include <SDL_mixer.h>

#include "DrawStream.h"
#include "CollisionKeeper.h"
#include "ParticleEngine.h"
#include "Hero.h"
#include "NPC.h"
#include "CollisionMatrix.h"
#include "HUDDrawer.h"
#include "MainMenu.h"

#define BACKCOLOR 108, 111, 112

using namespace std;

// Every scenario has WarpZones!

class WarpZone{
    
    private:
    
        Rectangle *mWarpRectangle;
        Coordinate2D *mSetCoordinate; // Coordinate hero will be teleported in case this warpzone
        
        int mMaptag;
        
    public:
    
        /**
         * Instantiates a WarpZone, WarpZones may handle world transitions easier, by verifying entrance in the WarpZone and obtaining maptags.
         * 
         * @param pX WarpZone X component
         * @param pY WarpZone Y component
         * @param pWidth WarpZone Width
         * @param pHeight WarpZone Height
         * @param pX WarpZone Teleport X component
         * @param pY WarpZone Teleport Y component
         * @param pMaptag maptag associated to this warpzone
         */
        
        WarpZone(int pX, int pY, int pWidth, int pHeight, int pXTele, int pYTele,int pMaptag){
            
            mWarpRectangle = new Rectangle(pX, pY, pWidth, pHeight);
            mSetCoordinate = new Coordinate2D(pXTele, pYTele);
            
            mMaptag = pMaptag;
        }
        
        /**
         * Tests if hero is inside WarpZone
         * 
         * @param pHero Hero to be tested
         * @return True if hero is inside warp zone
         */
        
        bool isInside(Hero *pHero){
            
            return mWarpRectangle->Collides(pHero->mRealRectPos);
        }
        
        /**
         * Return maptag associated to this warpzone
         * 
         * @return Map Tag
         */
        
        int getMapTag(){
            
            return mMaptag;
        }
        /**
         * @return Teleport Coordinate X component
         */
        int getXT(){
            
            return mSetCoordinate->x;
        }
        /**
         * @return Teleport Coordinate Y component
         */
        int getYT(){
            
            return mSetCoordinate->y;
        }
        
        virtual ~WarpZone(){
            
            delete mWarpRectangle;
            delete mSetCoordinate;
        }
};

class Scenario {
    
    private:
    
        bool mPaused;
        
        vector<Hero*> mHeroes;
        vector<NPC *> mNPCs;

        vector<Entity*> mOtherVisibleEntities;

        HUDDrawer mHUDHandler;

        CollisionMatrix *mColMat;

        DrawStream mEntityDrawer;
        CollisionKeeper mCollidablesRefresher;

        Image *mBackground;

        Image *mTopground;
        
        vector<ParticleEngine *> mParticles;
        vector<Image *> mTopLevels;
        
        vector<WarpZone *> mWarpZones;
        
        MainMenu *mPauseMenu;
        
    public:
        
        /**
         * Instantiate a Scenario
         * 
         * @param pBackgroundpath Background image path
         * @param pToppath Top image path
         * @param pMatrixpath Collision Matrix imagepath
         */
        
        Scenario(string pBackgroundpath, string pToppath, string pMatrixpath);

        /**
         * Add a entity to be visible
         * 
         * @param pEntity Entity to be added
         */
        
        void addEntity(Entity *pEntity);
        
        /**
         * Add a Hero to the scenario
         * 
         * @param pHero Hero to be added
         */
        
        void addHero(Hero *pHero);
        
        /**
         * Add a NPC to the scenario
         * 
         * @param pNPC NPC to be added
         */
        
        void addNPC(NPC *pNPC);
        
        /**
         * Add a particle engine to the scenario
         * 
         * @param pEngine ParticleEngine to be added
         */
        
        void addParticleEngine(ParticleEngine *pEngine);
        
        /**
         * Add a toplevel image to the scenario
         * 
         * BE CAREFUL images will be displayed in the added order
         * So, the top level image should be added after all other ones
         * 
         * @param pImage Image to be added
         */
        
        void addTopLevel(Image *pImage);
        
        /**
         * Add a WarpZone to this map, WarpZones will be destroyed in the destructor
         * 
         * @param pWarpZone WarpZone to be added
         */
        
        void addWarpZone(WarpZone *pWarpZone);
        
        /**
         * Draw the entire scenario on the screen
         * 
         * @param pResult This previous result will be processed to create this scenario.
         * @param pMusic sound that will be played during this Scenario
         * 
         * @return Result of the scenario;
         */
        
        ScenarioResult Draw(ScenarioResult pResult, Mix_Music *pMusic);
        
        /**
         * Delete all entities, except the heroes, that may be used in other battles, in other scenarios
         */
        
        virtual ~Scenario();

};

#endif	/* SCENARIO_H */

