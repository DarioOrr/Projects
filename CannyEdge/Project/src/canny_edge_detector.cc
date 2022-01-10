#include "canny_edge_detector.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>

void CannyEdge::Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) {
  //order: greyscale, gaussian, sobel, non-max, double, hysteresis
  std::map<std::string, unique_ptr<Filter>> filters;
  filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
  filters["gaussian"] = unique_ptr<Filter>(new GaussianBlur());
  filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
  filters["non_max"] = unique_ptr<Filter>(new NonMaxSupressionFilter());
  filters["double_thresh"] = unique_ptr<Filter>(new DoubleThresholdFilter());
  filters["hysteresis"] = unique_ptr<Filter>(new HysteresisFilter());

  filters["greyscale"] -> Apply(original, filtered); //apply greyscale
  std::vector<Image*> out;
  Image empty_img;
  out.push_back(&empty_img);
  filters["gaussian"] -> Apply(filtered, out); //aply gaussian
  std::vector<Image*> sobel_out;
  Image sobel_inp1;
  Image sobel_inp2;
  sobel_out.push_back(&sobel_inp1);
  sobel_out.push_back(&sobel_inp2); //sobel results in 2 filters
  filters["sobel"] -> Apply(out, sobel_out);  //sobel_out[0] is direction, sobel_out[1] is intensity
  filters["non_max"] -> Apply(sobel_out, out); //apply non-max filter
  Image empty_img2;
  std::vector<Image*> double_thresh;
  double_thresh.push_back(&empty_img2);
  filters["double_thresh"] -> Apply(out, double_thresh); //apply double threshold
  filters["hysteresis"] -> Apply(double_thresh, filtered);  //puts image back into filtered
}
