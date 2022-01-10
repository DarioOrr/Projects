/**
 * @file double_threshold_filter.h
 */

#ifndef DOUBLE_THRESHOLD_FILTER_H_
#define DOUBLE_THRESHOLD_FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "filter.h"
#include <vector>


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of entities.
 *
 *  Calls to \ref Generate function to get a new instance of an entity.
 *  This is a static call, not requiring an instance to invoke the method.
 */
class DoubleThresholdFilter : public Filter {
public:

    /**
    * @brief default constructor for the doublethresholdfilter class.
    */
    DoubleThresholdFilter();

    /**
    * @brief parameterized constructor for the doublethresholdfilter class.
    */
    DoubleThresholdFilter(float lower_threshold, float upper_threshold);

    /**
    * @brief destructor for the hysteresis class.
    */
    ~DoubleThresholdFilter();

    /**
    * @brief Takes in a pixel then does a calculation for luminance based on the pixel's values.
    *
    * @return The luminance value that was calculated.
    */
    float GetLuminance(unsigned char* pixel);

    /**
    * @brief Takes an image as an input, then applies the double threshold filter to it
    *
    * @return void
    */
    void Apply(std::vector<Image*>& original,std::vector<Image*>& filtered);

private:
    float upper_threshold, lower_threshold;
};



#endif
