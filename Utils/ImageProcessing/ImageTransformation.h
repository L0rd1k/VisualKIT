/* 
 * File:   ImageTransformation.h
 * Author: ilya petrikov
 *
 * Created on November 28, 2019, 1:03 PM
 */

#ifndef IMAGETRANSFORMATION_H
#define IMAGETRANSFORMATION_H

#include "Utils/ImagesColor/FalseColor.h"
#include "Utils/ImagesColor/LutTables.h"

#ifndef OPENCV_INCLUDE
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/features2d.hpp"
#endif

#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

class ImageTransformation {
public:
    ImageTransformation();
    virtual ~ImageTransformation();
private:
    void drawRectanglePoints(cv::Mat image);
    void getImageTranslation();
    void overlayImages();
    void drawPoints(Mat image, int x, int y);
    void getSiftFeatures();
    vector<vector<cv::Point2f> > getFeaturePoints();
};

#endif /* IMAGETRANSFORMATION_H */

