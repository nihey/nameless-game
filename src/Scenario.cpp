/* 
 * File:   Scenario.cpp
 * Author: Nihey
 * 
 * Created on 16 de Junho de 2012, 11:46
 */

#include "Scenario.h"

Scenario::Scenario(string pBackgroundpath, string pToppath, string pMatrixpath) {
    
    mPaused = false;
    
    mBackground = new Image(pBackgroundpath);
    
    mTopground = new Image(pToppath);
    
    mColMat = new CollisionMatrix(pMatrixpath);
    
    mPauseMenu = new MainMenu(true);
    
    for(vector<CollisionRect*>::iterator it = mColMat->begin(); it != mColMat->end(); it++){
        
        mCollidablesRefresher.addCollidable(*it);
    }
}

void Scenario::addEntity(Entity* pEntity){
    
    mOtherVisibleEntities.push_back(pEntity);
    
    mEntityDrawer.addEntity(pEntity);
}

void Scenario::addHero(Hero* pHero){
    
    mHeroes.push_back(pHero);
    
    mEntityDrawer.addEntity(pHero);
    mHUDHandler.addHero(pHero);
    mCollidablesRefresher.addCollidable(pHero);
}

void Scenario::addNPC(NPC* pNPC){
    
    mNPCs.push_back(pNPC);
    
    mEntityDrawer.addEntity(pNPC);
    mCollidablesRefresher.addCollidable(pNPC);
}

void Scenario::addParticleEngine(ParticleEngine* pEngine){
    
    mParticles.push_back(pEngine);
}

void Scenario::addTopLevel(Image* pImage){
    
    mTopLevels.push_back(pImage);
}

void Scenario::addWarpZone(WarpZone* pWarpZone){
    
    mWarpZones.push_back(pWarpZone);
}

ScenarioResult Scenario::Draw(ScenarioResult pResult, Mix_Music *pMusic){
    
    bool running = (!pResult.quit) && (!pResult.gameover);
    
    SDL_Event event;
    
    ScenarioResult result = pResult;
    
    Rectangle bg(0, 0, SDL_GetVideoSurface()->w, SDL_GetVideoSurface()->h);
    
    for(vector<Hero *>::iterator it = mHeroes.begin(); it != mHeroes.end(); it++){
                
        (*it)->Resume();
    }
    for(vector<NPC *>::iterator it = mNPCs.begin(); it != mNPCs.end(); it++){
                
        (*it)->Resume();
    }
    for(vector<Entity *>::iterator it = mOtherVisibleEntities.begin(); it != mOtherVisibleEntities.end(); it++){
                
        (*it)->Resume();
    }
    for(vector<ParticleEngine *>::iterator it = mParticles.begin(); it != mParticles.end(); it++){
                
        (*it)->ResumeAll();
    }
    
    while(running){
        
        if((!Mix_PlayingMusic()) && (!result.mute)){
            
            Mix_PlayMusic(pMusic, -1);
        }
        
        while(SDL_PollEvent(&event)){
            
            for(vector<Hero *>::iterator it = mHeroes.begin(); it != mHeroes.end(); it++){
                
                (*it)->HandleEvent(&event);
            }
            
            if(event.type == SDL_QUIT){
                
                running = 0;
                result.quit = true;
            }
            if(event.type == SDL_KEYDOWN){
                
                switch(event.key.keysym.sym){
                    
                    case SDLK_ESCAPE:
                    
                        mPaused = !mPaused; // Toggle Pause
                        
                        if(!mPaused){
                            
                            for(vector<Hero *>::iterator it = mHeroes.begin(); it != mHeroes.end(); it++){
                
                                (*it)->Resume();
                            }
                            for(vector<NPC *>::iterator it = mNPCs.begin(); it != mNPCs.end(); it++){
                
                                (*it)->Resume();
                            }
                            for(vector<Entity *>::iterator it = mOtherVisibleEntities.begin(); it != mOtherVisibleEntities.end(); it++){
                
                                (*it)->Resume();
                            }
                            for(vector<ParticleEngine *>::iterator it = mParticles.begin(); it != mParticles.end(); it++){
                
                                (*it)->ResumeAll();
                            }
                        }
                        
                    break;
                }
            }
        }
        
        if(mPaused){
            
            // Pause Menu Here
            
            result = mPauseMenu->Draw(result);
            
            mPaused = false;
            
            if(result.quit){
                
                running = false;
            }
            
            for(vector<Hero *>::iterator it = mHeroes.begin(); it != mHeroes.end(); it++){
                
                (*it)->Resume();
            }
            for(vector<NPC *>::iterator it = mNPCs.begin(); it != mNPCs.end(); it++){
                
                (*it)->Resume();
            }
            for(vector<Entity *>::iterator it = mOtherVisibleEntities.begin(); it != mOtherVisibleEntities.end(); it++){
                
                (*it)->Resume();
            }
            for(vector<ParticleEngine *>::iterator it = mParticles.begin(); it != mParticles.end(); it++){
                
                (*it)->ResumeAll();
            }
            
            continue;
        }
        
        bg.FillRectangle(BACKCOLOR);
        
        mBackground->Draw();
        
        mEntityDrawer.Draw();
        
        mTopground->Draw();
        
        mHUDHandler.Draw();
        
        for(vector<ParticleEngine *>::iterator it = mParticles.begin(); it != mParticles.end(); it++){
                
            (*it)->Draw();
        }
        
        for(vector<NPC *>::iterator it = mNPCs.begin(); it != mNPCs.end(); it++){
                
            (*it)->DrawPhrase();
        }
        
        for(vector<Image *>::iterator it = mTopLevels.begin(); it != mTopLevels.end(); it++){
            
            (*it)->Draw();
        }
        
        SDL_Flip(SDL_GetVideoSurface());
        
        SDL_Delay(10);
        
        for(vector<WarpZone *>::iterator it = mWarpZones.begin(); it != mWarpZones.end(); it++){
            
            
            for(vector<Hero *>::iterator it2 = mHeroes.begin(); it2 != mHeroes.end(); it2++){
                
                if((*it)->isInside(*it2)){
                    
                    running = 0;
                    
                    result.maptag = (*it)->getMapTag();
                    
                    for(vector<Hero *>::iterator it3 = mHeroes.begin(); it3 != mHeroes.end(); it3++){
                        
                        (*it3)->setPosition((*it)->getXT(), (*it)->getYT());
                    }
                }
            }
        }
    }
    
    return result;
}

Scenario::~Scenario() {
    
    delete mBackground;
    delete mTopground;
    delete mColMat;
    
    for(vector<NPC *>::iterator it = mNPCs.begin(); it != mNPCs.end(); it++){
                
        delete *it;
    }
    for(vector<Entity *>::iterator it = mOtherVisibleEntities.begin(); it != mOtherVisibleEntities.end(); it++){
                
        delete *it;
    }
    for(vector<ParticleEngine *>::iterator it = mParticles.begin(); it != mParticles.end(); it++){
                
        delete *it;
    }
    for(vector<Image *>::iterator it = mTopLevels.begin(); it != mTopLevels.end(); it++){
            
        delete *it;
    }
    for(vector<WarpZone *>::iterator it = mWarpZones.begin(); it != mWarpZones.end(); it++){
            
        delete *it;
    }
}

