#include "threshold_filter.h"
#include "image.h"
#include <iostream>
#include <vector>

using namespace std;

float threshold;


ThresholdFilter::ThresholdFilter() {
    threshold = 0.0;
}

ThresholdFilter::ThresholdFilter(float threshold_) {
    threshold = threshold_;
}

float ThresholdFilter::GetLuminance(unsigned char* pixel) {
    return 0.2126*pixel[0] + 0.7152*pixel[1] + 0.0722*pixel[2];
}

void ThresholdFilter::Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) {
    unsigned char* pixel = {0};
    float lum = 0.0;
    *filtered[0] = *original[0];
    for(int i = 0; i < filtered[0]->GetWidth(); i++) {
        for(int j = 0; j < filtered[0]->GetHeight(); j++) {
            pixel = filtered[0]->GetPixel(i,j);
            lum = GetLuminance(pixel)/255;
            if(lum < threshold) {
                pixel[0] = 0;
                pixel[1] = 0;
                pixel[2] = 0;
                pixel[3] = 255;
            }
            else {
                pixel[0] = 255;
                pixel[1] = 255;
                pixel[2] = 255;
                pixel[3] = 255;
            }
            filtered[0]->SetPixel(i, j, pixel);
        }
    }
}