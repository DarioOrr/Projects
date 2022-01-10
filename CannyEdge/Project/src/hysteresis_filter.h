/**
 * @file hysteresis_filter.h
 */
#ifndef HYSTERESIS_FILTER_H_
#define HYSTERESIS_FILTER_H_

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
class HysteresisFilter : public Filter {
public:

  /**
  * @brief default constructor for the hysteresis class.
  */
  HysteresisFilter();

  /**
  * @brief destructor for the hysteresis class.
  */
  ~HysteresisFilter();

  /**
  * @brief Takes an image as an input, then applies the hysteresis filter to it
  *
  * @return void
  */
  void Apply(std::vector<Image*>& original,std::vector<Image*>& filtered);
};



#endif
