#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "filter.h"
#include "image.h"
#include "greyscale_filter.h"
#include "mean_blur_filter.h"
#include "threshold_filter.h"
#include "canny_edge_detector.h"
#include "sobel_filter.h"
#include "double_threshold_filter.h"
#include "gaussian_blur.h"
#include "hysteresis_filter.h"
#include "non_max_supression_filter.h"

#include "gaussian_blur.h"

using namespace std;

int main(int argc, const char* argv[]) {
    // Get input file, filter type, and output file from command line
    // argc = # of arguments
    // argv = an array of arguments
    std::string inputFile(argv[1]);
    std::string filterType(argv[2]);
    std::string outputFile(argv[3]);
    //
    // // Create available filters (unique_ptr handles dynamic memory)
    std::map<std::string, unique_ptr<Filter>> filters;
    // filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    // filters["threshold"] = unique_ptr<Filter>(new ThresholdFilter(0.5));
    // filters["threshold-low"] = unique_ptr<Filter>(new ThresholdFilter(0.25));
    // filters["threshold-high"] = unique_ptr<Filter>(new ThresholdFilter(0.75));
    // filters["mean_blur"] = unique_ptr<Filter>(new MeanBlurFilter());
    // filters["non_max"] = unique_ptr<Filter>(new NonMaxSupressionFilter());
    // filters["double_thresh"] = unique_ptr<Filter>(new DoubleThresholdFilter());
    filters["canny_edge"] = unique_ptr<Filter>(new CannyEdge());

    //Create input and output vectors
    Image input(inputFile);
    Image output;
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);



    //Apply filter based on filter type
    filters[filterType]->Apply(inputs, outputs);

    //Save output image
    output.SaveAs(outputFile);
    return 0;
}
