/* 
 * File:   MainMenu.cpp
 * Author: NLT
 * 
 * Created on June 4, 2012, 10:16 PM
 */

#include "MainMenu.h"
#include "Player.h"
#include "Ranger.h"
#include "HealthPotion.h"

MainMenu::MainMenu(bool pPauseMenu) {
    
    mBackground = new Image(BACKGROUND_PATH);
    mTopLevel = new Image(TOPLEVELPATH);
    
    mMainChar = new NPC(MAINCHARPATH);
    mStrangeChar = new NPC(STRANGEPATH);
    
    mTravellingChar = new NPC(TRAVELLERPATH);
    
    mRandomChar01 = new NPC(RANDOM01PATH);
    mRandomChar02 = new NPC(RANDOM02PATH);
    
    mRandomSoldier01 = new NPC(RANDOM03PATH);
    mRandomSoldier02 = new NPC(RANDOM04PATH);
    mRandomSoldier03 = new NPC(RANDOM05PATH);
    
    mGeneral = new NPC(GENERALPATH);
    
    mNUM2 = new Button(NUM02PATH, BUTTONCOORDX, BUTTONCOORDY);
    mNUM3 = new Button(NUM03PATH, BUTTONCOORDX, BUTTONCOORDY + BUTTONJUMP);
    mNUM4 = new Button(NUM04PATH, BUTTONCOORDX, BUTTONCOORDY + (2*BUTTONJUMP));
    mBackMulti = new Button(EXITCREDITSPATH, BUTTONCOORDX, BUTTONCOORDY + (3*BUTTONJUMP));
    
    mButtonPlay = new Button(PLAYPATH, BUTTONCOORDX, BUTTONCOORDY);
    mSettings = new Button(SETTINGSPATH, BUTTONCOORDX, BUTTONCOORDY + BUTTONJUMP);
    mCredits = new Button(CREDITSPATH, BUTTONCOORDX, BUTTONCOORDY + (2*BUTTONJUMP));
    mExit = new Button(EXITPATH, BUTTONCOORDX, BUTTONCOORDY + (3*BUTTONJUMP));
    
    mSinglePlayer = new Button(SINGLEPATH, BUTTONCOORDX, BUTTONCOORDY);
    mMultiplayer = new Button(MULTIPATH, BUTTONCOORDX, BUTTONCOORDY + BUTTONJUMP);
    mExitMode = new Button(EXITMODESELECTPATH, BUTTONCOORDX, BUTTONCOORDY + (2*BUTTONJUMP));
    
    mSoundON = new Button(SOUNDONPATH, BUTTONCOORDX, BUTTONCOORDY);
    mSoundOFF = new Button(SOUNDOFFPATH, BUTTONCOORDX, BUTTONCOORDY);
    mExitSettings = new Button(EXITSETTINGSPATH, BUTTONCOORDX, BUTTONCOORDY + BUTTONJUMP);
    
    mCreditsImage = new Image(CREDITSIMGPATH);
    mExitCredits = new Button(EXITCREDITSPATH, BUTTONCOORDX, BUTTONCOORDY + (3*BUTTONJUMP));
    
    mContinue = new Button(CONTINUEPATH, BUTTONCOORDX, BUTTONCOORDY);
    
    mMusic = Mix_LoadMUS(MUSIC01PATH);
    
    mMainChar->setSpeedChangeAMT(0.5);
    mMainChar->setCycleWaypoints(false);
    mMainChar->setWandererMode(false);
    mMainChar->setPosition(400, 340);
    mMainChar->addWayPoint(new Coordinate2D(400, 200));
    
    mStrangeChar->setSpeedChangeAMT(0.5);
    mStrangeChar->setCycleWaypoints(false);
    mStrangeChar->setWandererMode(false);
    mStrangeChar->setPosition(-500, 340);
    mStrangeChar->addWayPoint(new Coordinate2D(100, 340));
    mStrangeChar->addWayPoint(new Coordinate2D(100, 390));
    
    mTravellingChar->setSpeedChangeAMT(0.6);
    mTravellingChar->setCycleWaypoints(true);
    mTravellingChar->setWandererMode(false);
    mTravellingChar->setPosition(-100, 240);
    mTravellingChar->addWayPoint(new Coordinate2D(850, 240));
    mTravellingChar->addWayPoint(new Coordinate2D(-50, 240));
    
    mRandomChar01->setSpeedChangeAMT(0.6);
    mRandomChar01->setCycleWaypoints(true);
    mRandomChar01->setWandererMode(false);
    mRandomChar01->setPosition(-10, 280);
    mRandomChar01->addWayPoint(new Coordinate2D(2800, 280));
    mRandomChar01->addWayPoint(new Coordinate2D(-2000, 280));
    
    mRandomChar02->setSpeedChangeAMT(0.5);
    mRandomChar02->setCycleWaypoints(true);
    mRandomChar02->setWandererMode(false);
    mRandomChar02->setPosition(900, 300);
    mRandomChar02->addWayPoint(new Coordinate2D(-2000, 300));
    mRandomChar02->addWayPoint(new Coordinate2D(2800, 300));
    
    mRandomSoldier01->setSpeedChangeAMT(0.7);
    mRandomSoldier01->setCycleWaypoints(false);
    mRandomSoldier01->setWandererMode(false);
    mRandomSoldier01->setPosition(-100, 280);
    
    mRandomSoldier02->setSpeedChangeAMT(0.7);
    mRandomSoldier02->setCycleWaypoints(false);
    mRandomSoldier02->setWandererMode(false);
    mRandomSoldier02->setPosition(-120, 260);
    
    mRandomSoldier03->setSpeedChangeAMT(0.7);
    mRandomSoldier03->setCycleWaypoints(false);
    mRandomSoldier03->setWandererMode(false);
    mRandomSoldier03->setPosition(-120, 300);
    
    mGeneral->setSpeedChangeAMT(0.8);
    mGeneral->setCycleWaypoints(false);
    mGeneral->setWandererMode(false);
    mGeneral->setPosition(-100, 280);
    
    mPauseMenu = pPauseMenu;
}

ScenarioResult MainMenu::Draw(ScenarioResult pResult){
    
    SDL_Event event;
    
    Timer eventtimer;
    
    ScenarioResult result = pResult;
    
    MainMenuState state = MAIN;
    
    mMainChar->Resume();
    mStrangeChar->Resume();
        
    mTravellingChar->Resume();
        
    mRandomChar01->Resume();
    mRandomChar02->Resume();
        
    mRandomSoldier01->Resume();
    mRandomSoldier02->Resume();
    mRandomSoldier03->Resume();
        
    mGeneral->Resume();
    
    if(mPauseMenu){
        
        state = PAUSE;
    }
    
    DrawStream drawer;
    drawer.addEntity(mMainChar);
    drawer.addEntity(mStrangeChar);
    drawer.addEntity(mTravellingChar);
    drawer.addEntity(mRandomChar01);
    drawer.addEntity(mRandomChar02);
    drawer.addEntity(mRandomSoldier01);
    drawer.addEntity(mRandomSoldier02);
    drawer.addEntity(mRandomSoldier03);
    drawer.addEntity(mGeneral);
    
    while(state != EXIT){
        
        if((!Mix_PlayingMusic()) && (!result.mute)){
            
            Mix_PlayMusic(mMusic, -1);
        }
        if((eventtimer.getElapsed() > 29700) && (eventtimer.getElapsed() < 31700)){
            
            mRandomSoldier01->addWayPoint(new Coordinate2D(900, 280));
            mRandomSoldier02->addWayPoint(new Coordinate2D(900, 260));
            mRandomSoldier03->addWayPoint(new Coordinate2D(900, 300));
        }
        if((eventtimer.getElapsed() > 50260)&&(eventtimer.getElapsed() < 52260)){
            
            mGeneral->addWayPoint(new Coordinate2D(900, 280));
        }
        if((eventtimer.getElapsed() > 55150)&&(eventtimer.getElapsed() < 57150)){
            
            mMainChar->addWayPoint(new Coordinate2D(400, 370));
        }
        
        mBackground->Draw();
        
        drawer.Draw();
        
        if(state == PAUSE){
            
            mContinue->Draw();
            mSettings->Draw();
            mCredits->Draw();
            mExit->Draw();
        }
        if(state == MULTI){
            
            mNUM2->Draw();
            mNUM3->Draw();
            mNUM4->Draw();
            mBackMulti->Draw();
        }
        if(state == MAIN){
            
            mButtonPlay->Draw();
            mSettings->Draw();
            mCredits->Draw();
            mExit->Draw();
        }
        if(state == MODESELECT){
            
            mSinglePlayer->Draw();
            mMultiplayer->Draw();
            mExitMode->Draw();
        }
        if(state == SETTINGS){
            
            mSoundON->Draw();
            mExitSettings->Draw();
        }
        if(state == SETTINGSMUTE){
            
            mSoundOFF->Draw();    
            mExitSettings->Draw();
        }
        if(state == CREDITS){
            
            mCreditsImage->Draw(BUTTONCOORDX, BUTTONCOORDY);
            mExitCredits->Draw();
        }
        
        mTopLevel->Draw();
        
        SDL_Delay(10);
        
        SDL_Flip(SDL_GetVideoSurface());
        
        while(SDL_PollEvent(&event)){
            if(state == MULTI){
                
                mNUM2->HandleEvent(&event);
                mNUM3->HandleEvent(&event);
                mNUM4->HandleEvent(&event);
                mBackMulti->HandleEvent(&event);
            }
            if(state == PAUSE){
                
                mContinue->HandleEvent(&event);
                mSettings->HandleEvent(&event);
                mCredits->HandleEvent(&event);
                mExit->HandleEvent(&event);
            }
            if(state == MAIN){
                
                mButtonPlay->HandleEvent(&event);
                mSettings->HandleEvent(&event);
                mCredits->HandleEvent(&event);
                mExit->HandleEvent(&event);
            }
            if(state == MODESELECT){
                
                mSinglePlayer->HandleEvent(&event);
                mMultiplayer->HandleEvent(&event);
                mExitMode->HandleEvent(&event);
            }
            if(state == SETTINGS){
                
                mSoundON->HandleEvent(&event);
                mExitSettings->HandleEvent(&event);
            }
            if(state == SETTINGSMUTE){
                
                mSoundOFF->HandleEvent(&event);
                mExitSettings->HandleEvent(&event);
            }
            if(state == CREDITS){
                
                mExitCredits->HandleEvent(&event);
            }
            
            // Verificação de clique de cada botão
            
            if(mNUM2->WasClicked()){
                
                mNUM2->Reset();
                
                state = EXIT;
                
                result.numplayers = 2;
            }
            if(mNUM3->WasClicked()){
                
                mNUM3->Reset();
                
                state = EXIT;
                
                result.numplayers = 3;
            }
            if(mNUM4->WasClicked()){
                
                mNUM4->Reset();
                
                state = EXIT;
                
                result.numplayers = 4;
            }
            if(mBackMulti->WasClicked()){
                
                mBackMulti->Reset();
                
                state = MODESELECT;
                
            }
            
            if(mContinue->WasClicked()){
                
                mContinue->Reset();
                
                state = EXIT;
            }
            if(mButtonPlay->WasClicked()){
                
                mButtonPlay->Reset();
                
                state = MODESELECT;
            }
            if(mSettings->WasClicked()){
                
                mSettings->Reset();
                
                if(result.mute){
                    
                    state = SETTINGSMUTE;
                }
                else{
                    
                    state = SETTINGS;
                }
            }
            if(mCredits->WasClicked()){
                
                mCredits->Reset();
                
                state = CREDITS;
            }
            if(mExit->WasClicked()){
                
                mExit->Reset();
                
                result.quit = true;
                
                state = EXIT;
            }
            if(mSinglePlayer->WasClicked()){
                
                mSinglePlayer->Reset();
                
                result.singleplayer = true;
                
                result.maptag = 0;
                
                state = EXIT;
            }
            if(mMultiplayer->WasClicked()){
                
                mMultiplayer->Reset();
                
                result.singleplayer = false;
                
                result.maptag = 99;
                
                state = MULTI;
            }
            if(mExitMode->WasClicked()){
                
                mExitMode->Reset();
                
                state = MAIN;
                
            }
            if(mSoundON->WasClicked()){
                
                mSoundON->Reset();
                
                result.mute = true;
                
                Mix_PauseMusic();
                
                state = SETTINGSMUTE;
            }
            if(mSoundOFF->WasClicked()){
                
                mSoundOFF->Reset();
                
                result.mute = false;
                
                Mix_ResumeMusic();
                
                state = SETTINGS;
            }
            if(mExitSettings->WasClicked()){
                
                mExitSettings->Reset();
                
                state = MAIN;
                
                if(mPauseMenu){
                    
                    state = PAUSE;
                }
            }
            if(mExitCredits->WasClicked()){
                
                mExitCredits->Reset();
                
                state = MAIN;
                
                if(mPauseMenu){
                    
                    state = PAUSE;
                }
            }
            
            if(event.type ==  SDL_QUIT){
                
                result.quit = true;
                
                state = EXIT;
            }
            if(event.type == SDL_KEYDOWN){
                
                switch(event.key.keysym.sym){
                    
                    case SDLK_ESCAPE:
                        
                        if(!mPauseMenu){
                         
                            result.quit = true;
                        }
                        
                        state = EXIT;
                        
                    break;
                }
            }
        }
    }
    
    if(!mPauseMenu){
        
        Mix_HaltMusic();
    }
    
    return result;
}

MainMenu::~MainMenu() {
    
    delete mBackground;
    delete mTopLevel;
    
    delete mMainChar;
    delete mStrangeChar;
    
    delete mTravellingChar;
    
    delete mRandomSoldier01;
    delete mRandomSoldier02;
    delete mRandomSoldier03;
    
    delete mGeneral;
    
    delete mRandomChar01;
    delete mRandomChar02;
    
    delete mButtonPlay;
    delete mSettings;
    delete mCredits;
    delete mExit;
    
    delete mSinglePlayer;
    delete mMultiplayer;
    delete mExitMode;
    
    delete mSoundON;
    delete mSoundOFF;
    delete mExitSettings;
    
    delete mCreditsImage;
    delete mExitCredits;
    
    Mix_FreeMusic(mMusic);
}

