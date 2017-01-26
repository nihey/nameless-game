/* 
 * File:   Timer.h
 * Author: Nihey
 *
 * Created on 7 de Maio de 2012, 13:46
 */

#ifndef TIMER_H
#define	TIMER_H

#include <SDL.h>

class Timer {
    
    private:

        int mOriginTime;
        int mFinalTime;
        
    public:
        
        /**
         * Instatiates a timer getting OriginTime
         */
        
        Timer();
        
        /**
         * Get how much (in ms) have elapsed since the last Refresh
         * 
         * @return Elapsed time
         */
        
        int getElapsed();
        
        /**
         * Refreshes the timer
         */
        
        void Refresh();
        
        virtual ~Timer();

};

#endif	/* TIMER_H */

