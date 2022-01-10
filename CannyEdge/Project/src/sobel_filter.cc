#include "sobel_filter.h"
#include "image.h"
#include <vector>
#include <cmath>
#include <iostream>


void SobelFilter::Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) {
    Image x_image(original[0]->GetWidth(), original[0]->GetHeight());
    Image y_image(original[0]->GetWidth(), original[0]->GetHeight());
    Image intensity(original[0]->GetWidth(), original[0]->GetHeight());
    Image direction(original[0]->GetWidth(), original[0]->GetHeight());
    float x_kernel[3][3] = {{-1.0, 0.0, 1.0}, {-2.0, 0.0, 2.0}, {-1.0, 0.0, 1.0}}; //x kernel
    float y_kernel[3][3] = {{1.0, 2.0, 1.0}, {0.0, 0.0, 0.0}, {-1.0, -2.0, -1.0}}; //y kernel
    Convolve(x_image, original[0], x_kernel);
    Convolve(y_image, original[0], y_kernel);
    Intensity(x_image, y_image, intensity);
    Direction(x_image, y_image, direction);
    FloatToPixel(direction);
    FloatToPixel(intensity);
    *filtered[0] = direction;
    *filtered[1] = intensity;
}

void SobelFilter::Convolve(Image& image, Image* original, const float kernel[3][3]) {
    int x_kernel_count = 0;  //location of where we are in kernel matrix, second index
    int y_kernel_count = 0;  //locaiton of where we are in kernel matrix, first index
    float sum = 0.0;  //Stores convolution total
    float val = 0.0;



    for(int i = 0; i < image.GetWidth(); i++) {
        for(int j = 0; j < image.GetHeight(); j++) {
            for(int x = i-1; x <= i+1; x++) {
                for(int y = j-1; y <= j+1; y++) {
                    if(x < 0 || y < 0) {
                        y_kernel_count++; //increase column although we are out of bounds
                        continue;
                    }
                    else {
                        val = original->GetPixel(x,y)[0];

                        sum += (val*kernel[y_kernel_count][x_kernel_count]);
                        y_kernel_count++; //increase column
                    }
                }
                y_kernel_count = 0;
                x_kernel_count++;  //increase since we have passed through first column, have to increase row location
            }
            image.SetPixelFloat(i, j, sum);
            sum = 0.0;  //reset sum since we are moving to next pixel
            x_kernel_count = 0;  //reset kernel location
            y_kernel_count = 0;  //reset kernel location
        }
    }
}

void SobelFilter::Intensity(Image& image1, Image& image2, Image& intensity) {
    float hyp = 0.0;
    float image1_pixel = 0.0;
    float image2_pixel = 0.0;
    float max = 0.0;



    for(int i = 0; i < image1.GetWidth(); i ++) {
        for(int j = 0; j < image1.GetHeight(); j++) {
            image1_pixel = image1.GetPixelFloat(i,j);
            image2_pixel = image2.GetPixelFloat(i,j);
            hyp = hypot(image1_pixel, image2_pixel);
            intensity.SetPixelFloat(i, j, hyp);
        }
    }

    max = 0.0; //determine pixel with max value
    for(int i = 0; i < image1.GetWidth(); i++) {
        for(int j = 0; j < image1.GetHeight(); j++) {
            if(max < intensity.GetPixelFloat(i, j)) {
                max = intensity.GetPixelFloat(i,j);
            }
            else {
                continue;
            }
        }
    }

    for(int i = 0; i < image1.GetWidth(); i++) { //normalize photo
        for(int j = 0; j < image1.GetHeight(); j++) {
            float val = intensity.GetPixelFloat(i, j);
            intensity.SetPixelFloat(i, j, val);
        }
    }
}

void SobelFilter::Direction(Image& image1, Image& image2, Image& direction) {
    float result = 0.0;
    for(int i = 0; i < image1.GetWidth(); i++) {
        for(int j = 0; j < image1.GetHeight(); j++) {
            result = atan2(image2.GetPixelFloat(i, j), image1.GetPixelFloat(i, j));
            result*=(180/M_PI);
            direction.SetPixelFloat(i, j, result);
        }
    }
}

void SobelFilter::FloatToPixel(Image& image) {
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
