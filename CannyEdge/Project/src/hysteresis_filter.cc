/**
 * @file hysteresis_filter.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "hysteresis_filter.h"
#include "image.h"
#include <iostream>
#include <vector>

//constructor
HysteresisFilter::HysteresisFilter(){}

//Destructor
HysteresisFilter::~HysteresisFilter(){}


void HysteresisFilter::Apply(vector<Image*>& original, vector<Image*>& filtered)
{
    *filtered[0] = *original[0];
    unsigned char* currPixel = {0};
    float newPixel[] = {0,0,0,255};
    int strongPixelCount = 0;

    //loops through main image
    for (int x = 1; x < filtered[0]->GetWidth()-1; x++) {
        for (int y = 1; y < filtered[0]->GetHeight()-1; y++) {

            //loops through pixels around the current pixel
            for (int i = x-1; i < x+1; i++)
            {
                for(int j = y-1; j<y+1;j++)
                {
                    currPixel = original[0]->GetPixel(i,j);
                    //if a strong pixel is found, increment
                    if(currPixel[0] == 255)
                    {
                        strongPixelCount++;
                    }
                    
                }
            }
            //if the pixel is weak
            if(currPixel[0] == 25)
            {
                //and has a nearby strong pixel, make it strong
                if(strongPixelCount > 0)
                {
                    newPixel[0] = 255;
                    newPixel[1] = 255;
                    newPixel[2] = 255;
                    newPixel[3] = 255;
                    filtered[0]->SetPixel(x,y,newPixel);
                }
                else{//if there are no nearby strong pixels, make it black
                    newPixel[0] = 0;
                    newPixel[1] = 0;
                    newPixel[2] = 0;
                    newPixel[3] = 255;
                    filtered[0]->SetPixel(x,y,newPixel);
                }
            }
            
            strongPixelCount = 0;


        }
    }


}