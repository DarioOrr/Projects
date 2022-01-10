#ifndef IMAGE_H_
#define IMAGE_H_
#include <string>

using namespace std;

class Image {
    public:
        Image();
        Image(int width_, int height_);
        Image(std::string imageName_);
        void SaveAs(std::string filename_);
        int GetHeight();
        int GetWidth();
        int GetComponentNum();
        unsigned char* GetPixel(int x, int y);
        float GetPixelFloat(int x, int y) const;
        void SetPixel(int x, int y, unsigned char* pixel);
        void SetPixel(const int x,const int y,const float pixel[]);
        void SetPixelFloat(int x, int y, float value);
        Image& operator=(const Image& image);
        ~Image();
    private:
        int width, height, x, y, components = 4;
        unsigned char *imageName;
        unsigned char *fileName;
        unsigned char *image;
};
#endif
