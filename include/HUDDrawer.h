/* 
 * File:   HUDDrawer.h
 * Author: Nihey
 *
 * Created on 16 de Junho de 2012, 11:48
 */

#ifndef HUDDRAWER_H
#define	HUDDRAWER_H

#include <vector>
#include "Hero.h"

using namespace std;

class HUDDrawer {

    private:
    
        vector<Hero *> mHeroes;

    public:

        /**
        * Instantiates a HUD drawer, this will handle Hero HUD draw
        */

        HUDDrawer();

        /**
        * Draw current unfreeze hero HUD
        */

        void Draw();

        /**
        * Add a hero to be handled
        * 
        * @param pHero Hero to be handled on HUD draw
        */

        void addHero(Hero* pHero);

        virtual ~HUDDrawer();

};

#endif	/* HUDDRAWER_H */

