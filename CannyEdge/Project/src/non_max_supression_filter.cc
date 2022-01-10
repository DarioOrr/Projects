#include "non_max_supression_filter.h"
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

void NonMaxSupressionFilter::Apply(std::vector<Image*>& original,std::vector<Image*>& filtered) {
  //original[0] is direction; original[1] is intensity
  int M = original[0]->GetWidth();
  int N = original[0]->GetHeight();
  Image output(M,N);
  for(int x = 0; x < M; x++) {
    for(int y = 0; y < N; y++) {
      unsigned char* q;
      unsigned char* r;
      float angle = (original[0]->GetPixel(x,y)[2] * 180.0 / M_PI);    //angle using direction filter
      if((0 <= angle || (157.5 <= angle <= 180.0))) {
        q = original[1]->GetPixel(x, y+1);
        r = original[1]->GetPixel(x, y-1);
      }
      else if(22.5 <= angle < 67.5) {
        q = original[1]->GetPixel(x+1, y-1);
        r = original[1]->GetPixel(x-1, y+1);
      }
      else if(67.5 <= angle < 112.5) {
        q = original[1]->GetPixel(x+1, y);
        r = original[1]->GetPixel(x-1, y);
      }
      else if(112.5 <= angle < 157.5) {
        q = original[1]->GetPixel(x-1, y-1);
        r = original[1]->GetPixel(x+1, y+1);
      }
      if(original[1]->GetPixel(x,y)[2] >= q[2] && original[1]->GetPixel(x,y)[2] >= r[2]) {
        unsigned char* pixel = original[1]->GetPixel(x,y);
        float p[] = {(float)(pixel[0]), (float)(pixel[1]), (float)(pixel[2]), (float)(pixel[3])};
        output.SetPixel(x,y,p);
        output.SetPixel(x,y,pixel);
      } else {
        float newPixel[] = {0,0,0,255};  //newPixel will be black
        output.SetPixel(x,y,newPixel);
      }
    }
  }
  *filtered[0] = output;
}
