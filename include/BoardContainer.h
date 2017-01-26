/* 
 * File:   BoardContainer.h
 * Author: Nihey
 *
 * Created on 4 de Julho de 2012, 14:45
 */

#ifndef BOARDCONTAINER_H
#define	BOARDCONTAINER_H

#include <vector>

#include "Image.h"
#include "Team.h"
#include "MainMenu.h"
#include "ParticleEngine.h"

#define BACKCOLOR 108, 111, 112

#define NEXTBUTTONPATH "res/button/nextt.png"

class BoardContainer {
    
    private:
        
        Image* mBackground;

        Button* mNextTurn;

        vector<Team* >::iterator mCurrentTeam;
        
        vector<Player*> mPlayers;
        
        vector<Team* > mTeams;

        vector<ParticleEngine *> mParticles;
        
        DrawStream mEntityDrawer;
        
        MainMenu *mPauseMenu;
        
    public:
        
        /**
         * @param pBackground BackGroundimage to be used
         */
        
        BoardContainer(Image *pBackground);

        /**
         * Add a particle engine to the scenario
         * 
         * @param pEngine ParticleEngine to be added
         */
        
        void addParticleEngine(ParticleEngine *pEngine);
        
        /**
         * Add a team to the Board
         * 
         * @param pTeam Team to be added
         */
        
        void addTeam(Team* pTeam);
        
        /**
         * Draw the Board
         */
        
        ScenarioResult Draw(ScenarioResult pResult, Mix_Music *pMusic);
        
        virtual ~BoardContainer();

};

#endif	/* BOARDCONTAINER_H */

