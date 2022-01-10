#include "mean_blur_filter.h"
#include "image.h"
#include <iostream>
#include <vector>

double filter;
float ratio = 1.0/9.0;

MeanBlurFilter::MeanBlurFilter::MeanBlurFilter() {
    filter = 0;
}

MeanBlurFilter::MeanBlurFilter(double filter_) {
    filter = filter_;
}

float r;
float g;
float b;

void MeanBlurFilter::Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) {
    *filtered[0] = *original[0];
    unsigned char pixel[4] = {0, 0, 0, 0};
    unsigned char* neighbors = {0};
    unsigned char* temp = {0};
    float r = 0.0;
    float g = 0.0;
    float b = 0.0;
    float count = 0.0;
    for(int i = 0; i < original[0]->GetWidth(); i++) {
        for(int j = 0; j < original[0]->GetHeight(); j++) {
            r = 0.0;
            g = 0.0;
            b = 0.0;
            for(int x = i-1; x <= i+1; x++) {
                for(int y = j-1; y <= j+1; y++) {
                    if(x < 0 || y < 0) {
                        continue;
                    }
                    else {
                        temp = original[0]->GetPixel(x,y);
                        r += temp[0];
                        g += temp[1];
                        b += temp[2];
                        count++;
                    }
                }
            }
            pixel[0] = (1.0/count)*r;
            pixel[1] = (1.0/count)*g;
            pixel[2] = (1.0/count)*b;
            pixel[3] = 255;
            filtered[0]->SetPixel(i, j, pixel);
            count = 0.0;
        }
    }
}
