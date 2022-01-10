/**
 * @file greyscale_filter.h
 */


#ifndef GREYSCALE_FILTER_H_
#define GREYSCALE_FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/


#include "filter.h"
#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The greyscale filter that intakes a colored image and returns a greyscaled image of the original image.
 */

class GreyScaleFilter : public Filter {
    public:
        /**
        * @brief calculates the luminance by aggregrating each component, 
        * and sets a new output pixel that uses this luminance value for red, green, and blue.
        */
        float GetLuminance(unsigned char* pixel);
        /**
        * @brief Takes an image and applies the greyscale filter to the image.
        */
        void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
};
#endif