#include "greyscale_filter.h"
#include "image.h"
#include <iostream>
#include <vector>



float GreyScaleFilter::GetLuminance(unsigned char* pixel) {
    return 0.2126*pixel[0] + 0.7152*pixel[1] + 0.0722*pixel[2];
}

void GreyScaleFilter::Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) {
    unsigned char* pixel = {0};
    float lumin = 0.0;
    *filtered[0] = *original[0];
    for(int i = 0; i < filtered[0]->GetWidth(); i++) {
        for(int j = 0; j < filtered[0]->GetHeight(); j++) {
            pixel = filtered[0]->GetPixel(i,j);
            lumin = GetLuminance(pixel);
            pixel[0] = lumin;
            pixel[1] = lumin;
            pixel[2] = lumin;
            pixel[3] = 255;
            filtered[0]->SetPixel(i, j, pixel);
        }
    }
}
