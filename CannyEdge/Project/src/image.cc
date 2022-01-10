#include <iostream>
#include "image.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

Image::Image() {
    width = 0;
    height = 0;
    components = 4;
    image = new unsigned char[width*height*components];
}

Image::Image(int width_, int height_) {
    width = width_;
    height = height_;
    components = 4;
    image = new unsigned char[width*height*components];
}

Image::Image(std::string imageName_) {
    const char *imageName = imageName_.c_str();
    fileName = stbi_load(imageName, &width, &height, &components, STBI_rgb_alpha);
    components = 4;
    image = new unsigned char[width*height*components];
    std::copy(fileName, fileName + width*height*components, image);
    stbi_image_free(fileName);
}

void Image::SaveAs(std::string fileName_){
    const char *load = fileName_.c_str();
    stbi_write_png(load, width, height, components, image, width*4);
}

int Image::GetHeight(){
    return height;
}

int Image::GetWidth(){
    return width;
}

int Image::GetComponentNum() {
    return components;
}

unsigned char* Image::GetPixel(int x, int y) {
    unsigned char* pixel = &image[(x+width*y)*4];
    //std::cout << "Pixel0: " << pixel[0] << "Pixel 1: " << pixel[1] << "Pixel 2: " << pixel[2] << std::endl;
    return pixel;
}

float Image::GetPixelFloat(int x, int y) const {
  unsigned char* pixel = &image[(x+width*y)*4];
  return *reinterpret_cast<float*>(pixel);
}

void Image::SetPixel(int x, int y, unsigned char* pixel) {
    unsigned char* pixelChange = &image[(x+width*y)*4]; //used to be &image, didn't work&image[(y*width + height)*4];;
    pixelChange[0] = pixel[0];
    pixelChange[1] = pixel[1];
    pixelChange[2] = pixel[2];
    pixelChange[3] = pixel[3];
}

void Image::SetPixel(const int x,const int y, const float pixel[]) {
  //const float pixel[]
 unsigned char* old_pixel = &image[(y*width + x)*4];
  old_pixel[0] = pixel[0];
  old_pixel[1] = pixel[1];
  old_pixel[2] = pixel[2];
  old_pixel[3] = pixel[3];
}

void Image::SetPixelFloat(int x, int y, float value) {
  unsigned char* pixel = &image[(x+width*y)*4];
  *reinterpret_cast<float*>(pixel) = value;
}


Image& Image::operator=(const Image& image_) {
    image = NULL;
    delete[] image;
    height = image_.height;
    width = image_.width;
    components = 4;
    image = new unsigned char[width*components*height];
    memcpy(image, image_.image, width*height*components);
    return *this;
}

Image::~Image() {
    //delete[] image;
}
