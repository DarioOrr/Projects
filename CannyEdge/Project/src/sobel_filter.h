/**
 * @file sobel_filter.h
 */

#ifndef SOBEL_FILTER_H_
#define SOBEL_FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "image.h"
#include "filter.h"
#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The sobel filter that intakes a gaussian blur image.  Initially convolves two different kernels over the image to extract
 * horizontal and vertical lines.  From these two convolutions are two images representing the convolutions of the x and y direction of
 * the inputted image.  With the two convolved images, the intensity and direction images are created.  The intensity image
 * is created by taking the hypotenuse between each of the same pixels within the x and y convolved images.  The new image is the direction
 * image which is used in the non-max-suppression filter.  Then the intensity image is created using the same x and convolved images.
 * To create the intensity image, the arctan of the y pixel divided by the x pixel at the same location is then converted to degrees.
 * With this, the intensity image is created which is also used in non-max-suppresion.
 */

class SobelFilter : public Filter {
    public:
        /**
        * @brief Takes an image and applies the sobel filter to the image.
        */
        void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
        /**
        * @brief Convolves the original image using the sobel kernel dependent on the direction, x or y.
        */
        void Convolve(Image& image, Image* original, const float kernel[3][3]);
        /**
        * @brief  Calculates the intensity image using the hypotenuse of the pixels at the same place in the x and y convolved images.
         */
        void Intensity(Image& image1, Image& image2, Image& intensity);
        /**
        * @brief Calculates the direction image using the arctangent of the pixels at the same place in the x and y convolved images.
         */
        void Direction(Image& image1, Image& image2, Image& direction);
        /**
        * @brief Converts the float image to an unsigned char* image.
        */
        void FloatToPixel(Image& image);

};
#endif