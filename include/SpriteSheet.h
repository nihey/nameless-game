/* 
 * File:   SpriteSheet.h
 * Author: Nihey
 *
 * Created on 24 de Abril de 2012, 12:14
 */

#ifndef SPRITESHEET_H
#define	SPRITESHEET_H

#include <cstdlib>


#include "Image.h"

class SpriteSheet : public Image {

    protected:

        int mOffsetXJump;
        int mOffsetYJump;
        
        bool mCycleRight;
        
        SDL_Rect mClipRect;
        
    public:
        
        /**
         * @brief Instantiate an image
         * 
         * @param pImagePath Image's path
         * @param pScreen Screen to apply the image
         */
        
        SpriteSheet(string pImagePath);
        
        /**
         * @brief Sets where will the Sprite start to run on the X axis
         * 
         * @param pOffset X Offset
         */
        
        void setOffsetX(int pOffset);
        
        /**
         * @brief Sets where will the Sprite start to run on the Y axis
         * 
         * @param pOffset Y Offset
         */
        
        void setOffsetY(int pOffset);
        
        /**
         * @brief Set the amount of pixels that the sprite must jump to reach another image on the X axis
         * 
         * @param pOffsetJump X axis jump
         */
        
        void setOffsetXJump(int pOffsetJump);
        
        /**
         * @brief Set the amount of pixels that the sprite must jump to reach another image on the Y axis
         * 
         * @param pOffsetJump Y axis jump
         */
        
        void setOffsetYJump(int pOffsetJump);
        
        /**
         * @brief Set the amount of width our object Spritely has
         * 
         * @param pWidth object's width
         */
        
        void setSpriteWidth(int pWidth);
        
        /**
         * @brief Set the amount of height our object Spritely has
         * 
         * @param pWidth object's height
         */
        
        void setSpriteHeight(int pHeight);
        
        /**
         * @brief Draw the image on the screen at the point (0,0)
         */
        
        void Draw();
        
        /**
         * @brief Draw the image on the screen with an reactangle offset
         * 
         * @param pOffset image's offset from the screen
         */
        
        void Draw(SDL_Rect* pOffset);
        
        /**
         * @brief Draw the image on the screen at (pX,pY)
         * 
         * @param pX X to draw the image
         * @param pY Y to draw the image
         */
        
        void Draw(int pX, int pY);
        
        /**
         * @brief this method is deprecated, it will do nothing;
         */
        
        void Draw(SDL_Rect* pOffset, SDL_Rect* pClip);
        
        /**
         * @brief this method is deprecated, it will do nothing;
         */
        
        void Draw(int pX, int pY, int pClipX, int pClipY, int pClipWidth,  int pClipHeight);
        
        /**
         * @brief return Offset X of the jump
         * 
         * @return Offset X of the jump
         */
        
        int getOffsetXJump();
        
        /**
         * @brief return Offset Y of the jump
         * 
         * @return Offset Y of the jump
         */
        
        int getOffsetYJump();
        
        /**
         * @brief Returns object's Sprite width
         * 
         * @return Object's Sprite width
         */
        
        int getSpriteWidth();
        
        /**
         * @brief Returns objects's Sprite height
         * 
         * @return Object's Sprite height
         */
        
        int getSpriteHeight();
        
        /**
         * @@brief Jumps to the next part of X of the sprite
         */
        
        void JumpRight();
        
        /**
         * Destroys this
         */
        
        virtual ~SpriteSheet();
    private:

};

#endif	/* SPRITESHEET_H */

