/*
 * File:   main.cpp
 * Author: Nihey
 *
 * Created on 4 de Maio de 2012, 11:01
 */

#include <cstdlib>
#include <ctime>

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "NPC.h"
#include "Particle.h"
#include "ParticleEngine.h"
#include "HUDBar.h"
#include "HeroHUD.h"
#include "Button.h"
#include "MainMenu.h"
#include "Hero.h"
#include "DrawStream.h"
#include "CollisionKeeper.h"
#include "CollisionRect.h"
#include "CollisionMatrix.h"
#include "ScenarioEntity.h"
#include "HUDDrawer.h"
#include "Scenario.h"
#include "BoardContainer.h"
#include "Fighter.h"
#include "Ranger.h"
#include "Board.h"

#define BG1 "res/bgs/bg1.png"
#define BG2 "res/bgs/bg2.png"
#define BG3 "res/bgs/bg3.png"
#define BG4 "res/bgs/bg4.png"

#define SC_WIDTH 800
#define SC_HEIGHT 600
#define SC_BPP 32

#define SOUND01 "res/music/tltr.ogg"

using namespace std;


int main(int argc, char** argv) {

    SDL_Init(SDL_INIT_VIDEO);
    Mix_OpenAudio( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096 );
    Mix_Init(MIX_INIT_OGG);
    TTF_Init();

    srand(time(NULL));

    SDL_Surface* icon = IMG_Load("res/icon/icon.png");

    SDL_WM_SetIcon(icon, NULL);

    SDL_WM_SetCaption("Test project", NULL);

    SDL_Surface* screen = SDL_SetVideoMode(SC_WIDTH, SC_HEIGHT, SC_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);

    Image loading("res/loading/loading.png");

    loading.Draw();

    SDL_Flip(screen);

    MainMenu *menu = new MainMenu(false);

    Scenario *prologue = new Scenario("res/map/prologue/scenario/prologuebg.png", "res/map/prologue/scenario/prologuetop.png", "res/map/prologue/collision/prologue.map");

    prologue->addEntity(new ScenarioEntity("res/map/prologue/scenario/prologuejail01.png", 0, 4*32));
    prologue->addEntity(new ScenarioEntity("res/map/prologue/scenario/prologuejail02.png", 0, 12*32));

    prologue->addNPC(new NPC("res/map/prologue/chars/prisoner01.png", 32, 3*32, 0.5, true, false));
    prologue->addNPC(new NPC("res/map/prologue/chars/prisoner02.png", 17*32, 3*32, 0.5, true, false));
    prologue->addNPC(new NPC("res/map/prologue/chars/prisoner03.png", 5*32, 11*32, 1.2, true, false));
    prologue->addNPC(new NPC("res/map/prologue/chars/prisoner04.png", 4*32, 3*32, 0.5, true, false));
    prologue->addNPC(new NPC("res/map/prologue/chars/prisoner05.png", 6*32, 3*32, 0.5, true, false, "Help!!!", (SDL_Color) {223, 229, 230}));
    prologue->addNPC(new NPC("res/map/prologue/chars/secretguy.png", 6*32, 13*32 + 23, 0.5, false, false, "I was waiting for you, King of The Great Lands", (SDL_Color) {231, 0, 51} ));

    prologue->addNPC(new NPC("res/map/prologue/chars/royalguard.png", 13*32, 13*32, 0.5, false, false, "Your majesty, a strange guy wants to talk to you", (SDL_Color) {223, 229, 230} ));

    NPC* aux = new NPC("res/map/prologue/chars/keeper.png", 32, (5*32) + 16, 0.5, false, true, "I sense a strange atmosphere here...",(SDL_Color) {223, 229, 230});

    aux->addPhrase("...prepare for unforeseen consequences...", (SDL_Color) {223, 229, 230});
    aux->addPhrase("...", (SDL_Color) {223, 229, 230});


    aux->addWayPoint(new Coordinate2D(32, (5*32) + 16));
    aux->addWayPoint(new Coordinate2D(23*32, (5*32) + 16));
    aux->addWayPoint(new Coordinate2D(32, (5*32) + 16));
    aux->addWayPoint(new Coordinate2D(32, 13*32));

    Hero* auxh = new Hero("res/map/prologue/chars/king.png" ,"res/HUD/image/king_hud.png", "res/HUD/mini/king_mini.png");

    auxh->setSpeedChangeAMT(0.7);
    auxh->setPosition(13*32, 15*32);

    prologue->addNPC(aux);
    prologue->addHero(auxh);

    prologue->addTopLevel(new Image("res/toplevel/flashback.png"));

    prologue->addWarpZone(new WarpZone(96 + 64, 416, 32, 96, 4*32, (13*32) + 23,-1));

    ScenarioResult result;

    Mix_Music* prologuesound = Mix_LoadMUS(SOUND01);

    while(!result.quit){

        if(result.maptag == -1){

            result = menu->Draw(result);
        }
        if(result.maptag == 0){

            result = prologue->Draw(result, prologuesound);
        }
        if(result.maptag == 99){

            BoardContainer *board;

            switch(rand()%4){

                case 0:

                    board = new BoardContainer(new Image(BG1));

                break;
                case 1:

                    board = new BoardContainer(new Image(BG2));

                break;
                case 2:

                    board = new BoardContainer(new Image(BG3));

                break;
                case 3:

                    board = new BoardContainer(new Image(BG4));

                break;
            }

            int numteams = result.numplayers;

            for(int i = 0; i < numteams; i++){

                Team *team = new Team("Random Generated Team", (Color) (RED + i));

                Player *p1 = new Player(MAINCHARPATH, new Ranger("MainR", 40, 40, 10, 10, 100));
                Player *p2 = new Player(GENERALPATH, new Fighter("Random MainChar2", 50, 30, 10, 10, 50));
                Player *p3 = new Player("res/map/prologue/chars/royalguard.png", new Fighter("Random MainChar2", 50, 30, 10, 10, 50));

                if((rand()%10) == 0){

                    p1->setArmor(new Armor("Random", 100, 100, 100));
                    p1->setWeapon(new Weapon("Gate of Babylon",100, 1000, 10, 1000));

                    p2->setArmor(new Armor("Random", 100, 100, 100));
                    p2->setWeapon(new Weapon("Gate of Babylon",100, 700, 7, 1000));

                    p1->setArmor(new Armor("Random", 100, 100, 100));
                    p1->setWeapon(new Weapon("Gate of Babylon",100, 400, 4, 1000));
                }
                else{

                    p1->setArmor(new Armor("Random", 10, 10, 10));
                    p1->setWeapon(new Weapon("Gate of Babylon",100, rand()%100, (rand()%10) + 1, 10));

                    p2->setArmor(new Armor("Random", 10, 10, 10));
                    p2->setWeapon(new Weapon("Gate of Babylon",100, rand()%30, (rand()%3) + 1, 10));

                    p1->setArmor(new Armor("Random", 1, 1, 1));
                    p1->setWeapon(new Weapon("Gate of Babylon",100, rand()%100, (rand()%2) + 1, 10));
                }
                switch(i){

                    case 0:

                        p1->setPosition(64, 96);
                        p2->setPosition(96, 96);
                        p3->setPosition(96, 128);

                    break;
                    case 1:

                        p1->setPosition(23*32, 16*32);
                        p2->setPosition(22*32, 16*32);
                        p3->setPosition(23*32, 15*32);

                    break;
                    case 2:

                        p1->setPosition(0, 18*32);
                        p2->setPosition(32, 18*32);
                        p3->setPosition(0, 17*32);

                    break;
                    case 3:

                        p1->setPosition(24*32, 0);
                        p2->setPosition(24*32, 32);
                        p3->setPosition(23*32, 0);

                    break;
                }
                team->addPlayer(p1);
                team->addPlayer(p2);
                team->addPlayer(p3);

                if((rand()%3) == 0){

                    ParticleEngine* eng = new ParticleEngine("res/particles/particle_white.png", 1000, 0);

                    eng->setRandLifetime(5000);
                    eng->setEfficientMode(true);
                    eng->setRandOrigin(1000, 1000);
                    eng->setOrigin(400, 300);
                    eng->setRandSPD(1, 1);
                    eng->setSpeed(1.5, 1.5);

                    board->addParticleEngine(eng);
                }

                board->addTeam(team);
            }

            result = board->Draw(result, prologuesound);

            delete board;

            result.maptag = -1;
        }
    }

    delete auxh;
    delete menu;
    delete prologue;

    SDL_FreeSurface(icon);

    Mix_FreeMusic(prologuesound);

    TTF_Quit();
    Mix_Quit();
    SDL_Quit();

    return 0;
}

