/* 
 * File:   MainMenu.h
 * Author: NLT
 *
 * Created on June 4, 2012, 10:16 PM
 */

#ifndef MAINMENU_H
#define	MAINMENU_H

#include <SDL.h>
#include <SDL_mixer.h>

#include "Image.h"
#include "Button.h"
#include "NPC.h"
#include "DrawStream.h"

#define BACKGROUND_PATH "res/background/mainmenu.png"
#define TOPLEVELPATH "res/toplevel/flashback.png"

#define MAINCHARPATH "res/npc/mmchar.png"

#define STRANGEPATH "res/npc/mmstrange.png"

#define TRAVELLERPATH "res/npc/mmtraveller.png"

#define RANDOM01PATH "res/npc/mmchar1.png"
#define RANDOM02PATH "res/npc/mmchar2.png"

#define RANDOM03PATH "res/npc/mmchar3.png"
#define RANDOM04PATH "res/npc/mmchar4.png"
#define RANDOM05PATH "res/npc/mmchar5.png"

#define GENERALPATH "res/npc/mmchar6.png"

#define CONTINUEPATH "res/button/continue.png"

#define PLAYPATH "res/button/play.png"

#define SETTINGSPATH "res/button/settings.png"

#define CREDITSPATH "res/button/credits.png"

#define EXITPATH "res/button/exit.png"

#define SOUNDONPATH "res/button/soundon.png"

#define SOUNDOFFPATH "res/button/soundoff.png"

#define EXITSETTINGSPATH "res/button/back.png"

#define CREDITSIMGPATH "res/button/creditsimg.png"
#define EXITCREDITSPATH "res/button/back.png"

#define SINGLEPATH "res/button/single.png"
#define MULTIPATH "res/button/multi.png"

#define EXITMODESELECTPATH "res/button/back.png"

#define BUTTONCOORDX (SDL_GetVideoSurface()->w/2) - (BUTTON_WIDTH/2)
#define BUTTONCOORDY (SDL_GetVideoSurface()->h/2) - (BUTTON_HEIGHT/2) - 100

#define BUTTONJUMP 38

#define MUSIC01PATH "res/music/ywt.ogg"

#define NUM02PATH "res/button/2.png"
#define NUM03PATH "res/button/3.png"
#define NUM04PATH "res/button/4.png"

enum MainMenuState {MAIN = 123321, SETTINGS, SETTINGSMUTE, CREDITS, EXIT, SINGLE, MULTI, MODESELECT, PAUSE};

// Scenario returns a scenario result to upper class after drawing

class ScenarioResult{
    
    public:
        
        int maptag; // Must be handled in an upper level, this will be used to change game zone
        int numplayers;
        
        bool singleplayer;
        bool mute;
        bool quit;
        bool gameover;
        
        ScenarioResult(){

            maptag = -1;
            
            mute = false;
            quit = false;
            gameover = false;
            
            numplayers = 2;
        }
};

class MainMenu {
    
    Image* mBackground;
    
    Image* mTopLevel;
    
    NPC* mMainChar;
    
    NPC* mStrangeChar;
    
    NPC* mTravellingChar;
    
    NPC* mRandomChar01;
    
    NPC* mRandomChar02;
    
    NPC* mRandomSoldier01;
    NPC* mRandomSoldier02;
    NPC* mRandomSoldier03;
    
    NPC* mGeneral;
    
    Button* mContinue;
    
    Button* mNUM2;
    Button* mNUM3;
    Button* mNUM4;
    Button* mBackMulti;
    
    Button* mButtonPlay;
    Button* mSettings;
    Button* mCredits;
    Button* mExit;
    
    Button* mSinglePlayer;
    Button* mMultiplayer;
    Button* mExitMode;
    
    Button* mSoundON;
    Button* mSoundOFF;
    Button* mExitSettings;
    
    Image* mCreditsImage;
    Button* mExitCredits;
    
    Mix_Music* mMusic;
    
    bool mPauseMenu;
    
    public:

        /**
         * Instantiates a main menu
         */
        
        MainMenu(bool pPauseMenu);
        
        /**
         * Draw this menu
         * 
         * @param pResult This previous result will be processed to create this scenario.
         * 
         * @return Menu Result
         */
        
        ScenarioResult Draw(ScenarioResult pResult);
        
        virtual ~MainMenu();

};

#endif	/* MAINMENU_H */

