/* 
 * File:   Image.h
 * Author: Nihey
 *
 * Created on 20 April 2012, 15:58
 */

#ifndef IMAGE_H
#define	IMAGE_H

#include <cstdlib>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

using namespace std;

/**
 * An Image to be drawn on the screen
 */

class Image {
    
    protected:
    
        int mWidth;
        int mHeight;
        
        SDL_Surface* mImage;
        
    public:
        
        /**
         *  Instantiate an image
         * 
         * @param pImagePath Image's path
         */
        
        Image(string pImagePath);
        
        /**
         *  Instantiate an image from a Surface
         * 
         * @param pSurface Surface to become the image
         */
        
        Image(SDL_Surface* pSurface);
        
        /**
         *  Add a ChromaKey to the Image
         * 
         * @param pChromaRGB ChromaKey's RGB
         */
        
        void setChromakey(Uint32 pChromaRGB);
        
        /**
         *  Add a ChromaKey to the Image
         * 
         * @param pChromaRed ChromaKey's Red
         * @param pChromaGreen ChromaKey's Green
         * @param pChromaBlue ChromaKey's Blue
         */
        
        void setChromakey(int pChromaRed, int pChromaGreen, int pChromaBlue);
        
        /**
         *  Draw the image on the screen at the point (0,0)
         */
        
        virtual void Draw();
        
        /**
         *  Draw the image on the screen with an reactangle offset
         * 
         * @param pOffset image's offset from the screen
         */
        
         virtual void Draw(SDL_Rect* pOffset);
        
        /**
         *  Draw the image on the screen at (pX,pY)
         * 
         * @param pX X to draw the image
         * @param pY Y to draw the image
         */
        
        virtual void Draw(int pX, int pY);
        
        /**
         *  Draw an image on the screen with an offset rectangle and a clip rectangle
         * 
         * @param pOffset Where the image will be applied
         * @param pClip How much of the image will be applied
         */
        
        virtual void Draw(SDL_Rect* pOffset, SDL_Rect* pClip);
        
        /**
         *  Apply the image on the screen with an described offset and an described clip
         * 
         * @param pX X to apply the image
         * @param pY Y to apply the image
         * @param pClipX X to the clip rectangle
         * @param pClipY Y to the clip rectangle
         * @param pClipHeight clip Height
         * @param pClipWidth clip Width
         */
        
        virtual void Draw(int pX, int pY, int pClipX, int pClipY, int pClipWidth,  int pClipHeight);
        
        /**
         *  Returns image's width
         * 
         * @return Image's width
         */
        
        int getWidth();
        
        /**
         *  Returns image's Height
         * 
         * @return Image's height
         */
        
        int getHeight();
        
        /**
         * Returns Image's Surface
         * 
         * @return Image's Surface
         */
        
        SDL_Surface* getSurface();
        
        /**
         * Destroys this
         */
        
        virtual ~Image();

};

#endif	/* IMAGE_H */

