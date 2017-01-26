/* 
 * File:   Particle.h
 * Author: Nihey
 *
 * Created on 11 de Maio de 2012, 16:24
 */

#ifndef PARTICLE_H
#define	PARTICLE_H

#include "Entity.h"


class Particle : public Entity {
    
    protected:

        friend class ParticleEngine; // Particle engine necessica acesso às variaveis de Particle
        
        unsigned int mLifetime;
        
    public:
        
        /**
         * Instantiates a particle
         * 
         * @param pImagePath Particle image path
         * @param pLifetime Particle lifetime
         */
        
        Particle(string pImagePath, unsigned int pLifetime);
        
        /**
         * Tells about particle life state
         * 
         * @return true if particle is alive
         */
        
        bool isAlive();
        
        /**
         * Draw the image and apply further physical operations
         */
        
        void Draw();
        
        /**
         * Set particle speed
         * 
         * @param pX Speed X component
         * @param pY Speed Y component
         */
        
        void setSpeed(double pX, double pY);
        
        /**
         * Return particle's speed
         * 
         * @return Particle's speed vector
         */
        
        Vector2D* getSpeed();
        
        /**
         * Reset this particle
         * 
         * @param pLifetime Particle's new lifetime
         */
        
        void Reset(int pLifetime);
        
        virtual ~Particle();

};

#endif	/* PARTICLE_H */

