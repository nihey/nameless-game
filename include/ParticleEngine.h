/* 
 * File:   ParticleEngine.h
 * Author: Nihey
 *
 * Created on 11 de Maio de 2012, 16:51
 */

#ifndef PARTICLEENGINE_H
#define	PARTICLEENGINE_H

#include <vector>
#include <ctime>
#include "Particle.h"

using namespace std;

class ParticleEngine {
    
    private:
        
        string mImagePath;

        vector<Particle *> mParticles;
        
        Timer* mGravityTimer;
        
        Coordinate2D* mOrigin;
        
        Coordinate2D* mConvergentPoint;
        
        Coordinate2D* mDivergentPoint;
        
        Vector2D* mOriginSpeed;
        
        Vector2D* mGravity;
        
        unsigned int mLifetime;
        
        unsigned int mMaxParticles;
        
        int mRandLifetime;
        
        double mRandOriginX;
        double mRandOriginY;
        
        double mRandOriginSPDX;
        double mRandOriginSPDY;
        
        double mConvergenceStrenght;
        
        double mDivergenceStrenght;
        
        bool mConverge;
        
        bool mDiverge;
        
        bool mEfficient;
        
    public:
        
        /**
         * Instantiates a particle engine
         * 
         * @param pImagePath Particle image path
         * @param pMaxParticles Max number of particles
         * @param pLifetima Particle average lifetime in ms
         */
        
        ParticleEngine(string pImagePath, unsigned int pMaxParticles, unsigned int pLifetime);

        /**
         * Set avg particle lifetime
         * 
         * @param pLifetime Lifetime to be set in ms
         */
        
        void setLifetime(int pLifetime);
        
        /**
         * Set gravity vector
         * 
         * @param pX X component
         * @param pY Y component
         */
        
        void setGravity(double pX, double pY);
        
        /**
         * Set particle engine origin
         * 
         * @param pX X component
         * @param pY Y component
         */
        
        void setOrigin(double pX, double pY);
        
        /**
         * Set particle engine origin speed
         * 
         * @param pX Speed X component
         * @param pY Speed Y component
         */
        
        void setSpeed(double pX, double pY);
        
        /**
         * Set particle image path (New particles will born as new imagepath's image) :D
         * 
         * @param pImagePath Image path to be set
         */
        
        void setImagePath(string pImagePath);
        
        /**
         * Set lifetime randomicity
         * 
         * @param pLifetimeRand Lifetime randomicity
         */
        
        void setRandLifetime(int pRandLifetime);
        
        /**
         * Sets Particle Engine Efficient mode.
         * On efficient mode particles may not change imagepath
         * 
         * @param pEfficient True if efficient mode is enabled
         */
        
        void setEfficientMode(bool pEfficient);
        
        /**
         * Set origin randomicity
         * 
         * @param pX X randomicity
         * @param pY Y randomicity
         */
        
        void setRandOrigin(double pX, double pY);
        
        /**
         * Set launch speed randomicity
         * 
         * @param pX X randomicity
         * @param pY Y randomicity
         */
        
        void setRandSPD(double pX, double pY);
        
        /**
         * Set particle engine convergent point to (pX, pY)
         * 
         * @param pX Convergent X component
         * @param pY Convergent Y component
         */
        
        void setConvergentPoint(double pX, double pY);
        
        /**
         * Set convergence of the particle engine;
         * 
         * @param pConvergible Will the particle engine converge to any point?
         */
        
        void setConvergible(bool pConvergible);
        
        /**
         * Set convergence strenght
         * 
         * @param pStrenght Strenght to be set
         */
        
        void setConvergenceStrenght(double pStrenght);
        
        /**
         * Set particle engine divergent point to (pX, pY)
         * 
         * @param pX Divergent X component
         * @param pY Divergent Y component
         */
        
        void setDivergentPoint(double pX, double pY);
        
        /**
         * Set convergence of the particle engine;
         * 
         * @param pConvergible Will the particle engine converge to any point?
         */
        
        void setDivergible(bool pDivergible);
        
        /**
         * Set Divergence strenght
         * 
         * @param pStrenght Strenght to be set
         */
        
        void setDivergenceStrenght(double pStrenght);
        
        /**
         * Draw the image and apply further physical properties;
         */
        
        virtual void Draw();
        
        /**
         * @return Origin X component randomicity
         */
        
        double getRandOriginX();
        
        /**
         * @return Origin Y component randomicity
         */
        
        double getRandOriginY();
        
        /**
         * @return Speed X component randomicity
         */
        
        double getRandSPDX();
        
        /**
         * @return Speed Y component randomicity
         */
        
        double getRandSPDY();
        
        /**
         * @return Lifetime randomicity
         */
        
        int getRandLifetime();
        
        /**
         * Get Efficient mode state
         * 
         * @return Efficient mode state
         */
        
        bool getEfficientMode();
        
        /**
         * @return True if the particle engine is converging to any point
         */
        
        bool Converge();
        
        /**
         * @return True if the particle engine is Diverging to any point
         */
        
        bool Diverge();
        
        /**
         * Resume all particles in this particle engine
         */
        
        void ResumeAll();
        
        virtual ~ParticleEngine();

};

#endif	/* PARTICLEENGINE_H */

