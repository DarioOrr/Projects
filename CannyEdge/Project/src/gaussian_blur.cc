#include "gaussian_blur.h"

#include "image.h"
#include <vector>
#include <cmath>
#include <iostream>

void GaussianBlur::Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) {
    Image blur_image(original[0]->GetWidth(), original[0]->GetHeight());
    Convolve(blur_image, original[0]);
    FloatToPixel(blur_image);
    *filtered[0] = blur_image;
}

void GaussianBlur::Convolve(Image& image, Image* original) {
    float kernel[5][5];  //kernel for the calculation
    float sum = 0.0;  //sum of the surrounding pixels
    float val = 0.0;  //holds value of pixels surrounding the targetted pixel
    float count = 0.0;  //counts how many pixels have been examined
    int x_kernel_count = 0;  //keeps track of where we are in the kernel
    int y_kernel_count = 0;  //keeps track of where we are in the kernel
    float sigma = 2.0;
    float kernel_sum = 0.0;  //used to calculate sum of kernel for normilization



    

    for(int i = -2; i <= 2; i++) {  //creates the kernel for calculations, start at -2 since we are going 2 pixels behind the original
        for(int j = -2; j <= 2; j++) {
            float expon = (-(pow(i, 2) + pow(j, 2))) / (2*pow(sigma, 2));
            val = (exp(expon) / (2 * M_PI * pow(sigma, 2)));
            kernel[i+2][j+2] = val;
            kernel_sum += val;
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            kernel[i][j] /= kernel_sum;  //normalize kernel so all values add to 1
        }
    }

    for(int i = 0; i < image.GetWidth(); i++) {
        for(int j = 0; j < image.GetHeight(); j++) {
            for(int x = i-2; x <= i+2; x++) {
                for(int y = j-2; y <= j+2; y++) {
                    if(x < 0 || y < 0) {
                        y_kernel_count++;  //if we are out of bounds, continue
                        continue;
                    }
                    else {
                        val = original->GetPixel(x, y)[0];
                        val *= kernel[y_kernel_count][x_kernel_count];
                        sum += val;  //sum of current pixel being convolved
                        count++;
                        y_kernel_count++;
                    }
                }
                y_kernel_count = 0;
                x_kernel_count++;
            }

            image.SetPixelFloat(i, j, sum);  //sets the pixel as a float
            sum = 0;  //reset sum before moving to next pixel
            count = 0;  //reset count before moving to next pixel
            y_kernel_count = 0;
            x_kernel_count = 0;
        }
    }
}

void GaussianBlur::FloatToPixel(Image& image) {  //converts the float pixels to unsigned char* pixels via a function in image.cc
    float val = 0;
    float pixel[4] = {0, 0, 0, 0};
    for(int i = 0; i < image.GetWidth(); i++) {
        for(int j = 0; j < image.GetHeight(); j++) {
            val = image.GetPixelFloat(i, j);
            pixel[0] = val;
            pixel[1] = val;
            pixel[2] = val;
            pixel[3] = 255.0;
            image.SetPixel(i, j, pixel); //Different SetPixel which takes in float array and converts to unsigned char in image.cc
        }
    }
}
