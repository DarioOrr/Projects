/**
 * @file dobule_threshold_filter.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/

#include "double_threshold_filter.h"
#include "image.h"
#include <iostream>
#include <vector>



using namespace std;

float upper_threshold, lower_threshold;


DoubleThresholdFilter::DoubleThresholdFilter() {
    upper_threshold = 0.3;
    lower_threshold = 0.05;
}

DoubleThresholdFilter::DoubleThresholdFilter(float low_threshold, float high_threshold) {
    lower_threshold = low_threshold;
    upper_threshold = high_threshold;
}

DoubleThresholdFilter::~DoubleThresholdFilter(){}

float DoubleThresholdFilter::GetLuminance(unsigned char* pixel) {
    return 0.2126*pixel[0] + 0.7152*pixel[1] + 0.0722*pixel[2];
}

void DoubleThresholdFilter::Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) {
    unsigned char* pixel = {0};
    float lum = 0.0;
    *filtered[0] = *original[0];

    //loop through pixels in the image
    for(int i = 0; i < filtered[0]->GetWidth(); i++) {
        for(int j = 0; j < filtered[0]->GetHeight(); j++) {
            pixel = filtered[0]->GetPixel(i,j);
            lum = GetLuminance(pixel)/255;
            float newPixel[] = {0,0,0,255};
            if(lum < lower_threshold) {//set pixel to black
                newPixel[0] = 0;
                newPixel[1] = 0;
                newPixel[2] = 0;
                newPixel[3] = 255;
            }
            else if(lum > upper_threshold) {//set pixel to high intensity or white
                newPixel[0] = 255;
                newPixel[1] = 255;
                newPixel[2] = 255;
                newPixel[3] = 255;
            }
            else {//set pixel to low intensity or gray
                newPixel[0] = 25;
                newPixel[1] = 25;
                newPixel[2] = 25;
                newPixel[3] = 255;

            }
            filtered[0]->SetPixel(i, j, newPixel);
        }
    }
}
