/* 
 * File:   ScenarioEntity.h
 * Author: Nihey
 *
 * Created on 12 de Junho de 2012, 16:42
 */

#ifndef SCENARIOENTITY_H
#define	SCENARIOENTITY_H

#include "Entity.h"


class ScenarioEntity : public Entity {
    
    public:
        
        /**
         * Instantiates a Scenario Entity (Could be something like a tree, same level as all other entities, that need some kind of image interaction)
         * 
         * @param pImagePath Entity Image to be applies, it's height should be trimmed
         * @param pX Entity eternal X component
         * @param pY Entity eternal Y component
         */
        
        ScenarioEntity(string pImagePath, int pX, int pY);
        
        /**
         * Draw the image on the Screen
         */
        
        void Draw();
        
        virtual ~ScenarioEntity();

};

#endif	/* SCENARIOENTITY_H */

