
/**
 * @file gaussian_blur.h
 */

#ifndef GAUSSIAN_BLUR_H_
#define GAUSSIAN_BLUR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "image.h"
#include "filter.h"
#include <vector>

/**
 * @brief The gaussian blur filter that convolves a 5x5 kernel with a sigma value of 2.
 */

class GaussianBlur : public Filter {
    public:
        /**
        * @brief Takes an image and applies the gaussian blur filter to the image.
        */
        void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
        /**
        * @brief Convolves the original image using the a 5x5 kernel using the gaussian formula with a sigma value of 2.
        */
        void Convolve(Image& image, Image* original);
        /**
        * @brief Converts the newly created image which is currently made of floats back to unsigned char* representation.
        */
        void FloatToPixel(Image& image);
};
#endif