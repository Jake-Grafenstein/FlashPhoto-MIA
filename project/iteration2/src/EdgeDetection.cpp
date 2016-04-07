//
// EdgeDetection.cpp
// Created by Jacob Grafenstein
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include "ConvolutionFilter.h"
#include "EdgeDetection.h"

using namespace std;


EdgeDetection::EdgeDetection() {
  kernelSize = 3;
  kernel = (float**) malloc(kernelSize*sizeof(float *));
  for (int i = 0; i < kernelSize; i++) {
    kernel[i] = (float *) malloc(kernelSize * sizeof(float));
  }

  int midPoint = floor(kernelSize/2);

  kernel[midPoint][midPoint] = 8.0;
  for (int j = 0; j < kernelSize; j++) {
    for (int k = 0; k < kernelSize; k++) {
      if ((j == k) == midPoint) {
        // Do Nothing
      } else if (((j == 0) || (j== kernelSize-1)) && ((k == 0) || (k == kernelSize-1))) {
        kernel[j][k] = 0.0;
      } else {
        kernel[j][k] = -1.0;
      }
    }
  }
}

EdgeDetection::~EdgeDetection() {
  for (int i = 0; i < kernelSize; i++) {
    free(kernel[i]);
  }
  free(kernel);
}
