/**
 * @file canny_edge_detector.h
 */

#ifndef CANNY_EDGE_H_
#define CANNY_EDGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "image.h"
#include <string>
#include <vector>
#include "greyscale_filter.h"
#include "double_threshold_filter.h"
#include "gaussian_blur.h"
#include "non_max_supression_filter.h"
#include "sobel_filter.h"
#include "hysteresis_filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of entities.
 *
 *  The canny edge filter takes an image and applies the greyscale, gaussian blur,
 *  sobel, non max supression, double threshold, and hysteresis filters to it to detect
 *  the edges in the image.
 */


class CannyEdge : public Filter {
    public:
      /**
      * @brief Takes an image as an input, then applies other filters in seq to get edge detection
      *
      * @return void
      */
        void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
    };

#endif
