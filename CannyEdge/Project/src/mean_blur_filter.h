#ifndef MEAN_BLUR_FILTER_H_
#define MEAN_BLUR_FILTER_H_

#include "filter.h"
#include <vector>


class MeanBlurFilter : public Filter {
    public:
        MeanBlurFilter();
        MeanBlurFilter(double filter_);
        void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
    private:
        double filter;
};
#endif
