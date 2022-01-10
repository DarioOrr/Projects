/**
 * @file filter.h
 */

#ifndef FILTER_H_
#define FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "image.h"
#include <string>
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

class Filter {
    public:

      /**
      * @brief destructor for the filter class.
      */
        virtual ~Filter() {}

      /**
      * @brief Takes an image as an input, then applies the filter to it
      *
      * @return void
      */
        virtual void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) = 0;
};

#endif
