/* 
 * File:   Button.h
 * Author: NLT
 *
 * Created on June 3, 2012, 9:52 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "SDL.h"
#include "SpriteSheet.h"
#include "Rectangle.h"

#define BUTTON_HEIGHT 30
#define BUTTON_WIDTH 200

class Button {
   
protected:    
    SpriteSheet* mImage; 
    Rectangle* mClickRect;
    bool mClicked;
    bool mClickDown;
    
    int mButton_height;
    
public:
    
    /**
     * Instantiate a Button given a SpriteSheet an the position (pX, pY)
     * 
     * @param pImagePath SpriteSheet Path
     * @param pX Button X position on the screen
     * @param pY Button Y position on the screen
     */
    
    Button(string pImagePath, int pX, int pY);
    
    /**
     * Draw the button at the screen
     */
    
    void Draw();
    
    /**
     * Handle Button events
     * 
     * @param pEvent Event to be handled
     */
    
    void HandleEvent(SDL_Event *pEvent);
    
    /**
     * Reset this button, resetting will result to his clicked state to be turned into false
     */
    
    void Reset();
    
    /**
     * Verifies if this button was clicked
     * 
     * @return True is this button was clicked
     */
    
    bool WasClicked();
    
    /**
     * Destroy the button
     */
    
    virtual ~Button();
private:

};

// MiniButton que acompanha o personagem

class MiniButton : public Button {

public:
    
    /**
     * Instantiate a Button given a SpriteSheet an the position (pX, pY)
     * 
     * @param pImagePath SpriteSheet Path
     */

    MiniButton(string pImagePath) : Button(pImagePath, 0, 0){
        
        mButton_height = BUTTON_HEIGHT/2;
        
        mImage->setSpriteWidth(BUTTON_WIDTH/2);
        mImage->setSpriteHeight(BUTTON_HEIGHT/2);
        
        mClickRect->w = BUTTON_WIDTH/2;
        mClickRect->h = BUTTON_HEIGHT/2;
    }
        
    /**
     * Update button position
     * 
     * @param pX X component
     * @param pY Y component
     */
    
    void Update(int pX, int pY){
        
        mClickRect->x = pX;
        mClickRect->y = pY;
    }
};

#endif	/* BUTTON_H */

