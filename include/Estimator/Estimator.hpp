#ifndef ESTIMATOR_HPP_INCLUDE
#define ESTIMATOR_HPP_INCLUDE

#include <vector>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp> // For essential matrix/pnp/etc

#include "Utils/Camera.hpp" // Find a better way than to pass the camera around?
#include "Utils/Feature.hpp"
#include "Utils/Map.hpp"

class Estimator {
  public:
    Estimator();
    Estimator(Camera cam);

    // Main function for this object
    // Different behavior based on:
    // * If map is initialized
    // * If a new keyframe is needed
    bool process_image(Camera cam, std::vector<Feature> features); // note: this actually only takes in the features

  private:
    // Estimator needs to compare features to previously triangulated points,
    // so needs to store a map
    
    // Owned Objects
    Map map_;
    Camera cam_;

    // Functions
    
    // Data
    cv::Mat rvec_, tvec_; // Store current pose?



};

#endif
