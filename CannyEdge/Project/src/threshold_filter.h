#ifndef THRESHOLD_FILTER_H_
#define THRESHOLD_FILTER_H_

#include "filter.h"
#include <vector>


class ThresholdFilter : public Filter {
public:
    ThresholdFilter();
    ThresholdFilter(float threshold_);
    float GetLuminance(unsigned char* pixel);
    void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
private:
    double threshold;
};
#endif