/* 
 * File:   BoardContainer.cpp
 * Author: Nihey
 * 
 * Created on 4 de Julho de 2012, 14:45
 */

#include "BoardContainer.h"

BoardContainer::BoardContainer(Image* pBackground) {
    
    mBackground = pBackground;
    
    mNextTurn = new Button(NEXTBUTTONPATH, 10, 10);
    
    mPauseMenu = new MainMenu(true);
}

void BoardContainer::addParticleEngine(ParticleEngine* pEngine){
    
    mParticles.push_back(pEngine);
}

void BoardContainer::addTeam(Team* pTeam){
    
    for(vector<Player *>::iterator it = pTeam->begin(); it != pTeam->end(); it++){
        
        mEntityDrawer.addEntity(*it);
        
        for(vector<Player *>::iterator it2 = mPlayers.begin(); it2 != mPlayers.end(); it2++){
            
            (*it)->addEntity(*it2);
            (*it2)->addEntity(*it);
        }
    }
    for(vector<Player *>::iterator it = pTeam->begin(); it != pTeam->end(); it++){
        
        mPlayers.push_back(*it);
    }
    
    mTeams.push_back(pTeam);
}

ScenarioResult BoardContainer::Draw(ScenarioResult pResult, Mix_Music *pMusic){
    
    for(vector<Player *>::iterator it = mPlayers.begin(); it != mPlayers.end(); it++){
            
            (*it)->Finish();
    }
    
    mCurrentTeam = mTeams.begin();
    
    for(vector<Player *>::iterator it = (*mCurrentTeam)->begin(); it != (*mCurrentTeam)->end(); it++){
                
        (*it)->Reset();
    }
    
    bool running = (!pResult.quit) && (!pResult.gameover);
    
    SDL_Event event;
    
    ScenarioResult result = pResult;
    
    Rectangle bg(0, 0, SDL_GetVideoSurface()->w, SDL_GetVideoSurface()->h);
    
    bool paused = false;
    
    while(running){
        
        if((!Mix_PlayingMusic()) && (!result.mute)){
            
            Mix_PlayMusic(pMusic, -1);
        }
        
        while(SDL_PollEvent(&event)){
            
            mNextTurn->HandleEvent(&event);
            
            if(mNextTurn->WasClicked()){
                
                mNextTurn->Reset();
                
                for(vector<Player *>::iterator it = (*mCurrentTeam)->begin(); it != (*mCurrentTeam)->end(); it++){
                
                    (*it)->Finish();
                }
                
                mCurrentTeam++;
                
                if(mCurrentTeam == mTeams.end()){
                    
                    mCurrentTeam = mTeams.begin();
                }
                
                for(vector<Player *>::iterator it = (*mCurrentTeam)->begin(); it != (*mCurrentTeam)->end(); it++){
                
                    (*it)->Reset();
                }
            }
            
            for(vector<Player *>::iterator it = (*mCurrentTeam)->begin(); it != (*mCurrentTeam)->end(); it++){
                
                (*it)->HandleEvent(&event);
            }
            
            if(event.type == SDL_QUIT){
                
                running = 0;
                result.quit = true;
            }
            if(event.type == SDL_KEYDOWN){
                
                switch(event.key.keysym.sym){
                    
                    case SDLK_ESCAPE:
                    
                        paused = !paused; // Toggle Pause
                        
                    break;
                }
            }
        }
        
        if(paused){
            
            // Pause Menu Here
            
            result = mPauseMenu->Draw(result);
            
            paused = false;
            
            if(result.quit){
                
                running = false;
            }
            
            for(vector<Player *>::iterator it = (*mCurrentTeam)->begin(); it != (*mCurrentTeam)->end(); it++){
                
                (*it)->Resume();
            }
            
            continue;
        }
        
        bg.FillRectangle(BACKCOLOR);
        
        mBackground->Draw();
        
        for(vector<Player *>::iterator it = (*mCurrentTeam)->begin(); it != (*mCurrentTeam)->end(); it++){
                
            (*it)->DrawWRect();
        }
        
        mEntityDrawer.Draw();
        
        for(vector<Player *>::iterator it = (*mCurrentTeam)->begin(); it != (*mCurrentTeam)->end(); it++){
                
            (*it)->DrawButtons();
        }
        
        mNextTurn->Draw();
        
        for(vector<ParticleEngine *>::iterator it = mParticles.begin(); it != mParticles.end(); it++){
                
            (*it)->Draw();
        }
        
        SDL_Flip(SDL_GetVideoSurface());
        
        SDL_Delay(10);
        
    }   
    
    return result;
}

BoardContainer::~BoardContainer() {
    
    for(vector<Team* >::iterator it = mTeams.begin(); it != mTeams.end(); it++){
        
        delete (*it);
    }
    
    for(vector<ParticleEngine *>::iterator it = mParticles.begin(); it != mParticles.end(); it++){
                
        delete *it;
    }
    
    delete mBackground;
    delete mNextTurn;
}

