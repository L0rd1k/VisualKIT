/* 
 * File:   ImageTransformation.cpp
 * Author: ilya petrikov
 * Created on November 28, 2019, 1:03 PM
 */

#include "ImageTransformation.h"

void ImageTransformation::getSiftFeatures() {
    cv::Mat imageIK = cv::imread("/home/ilya/test2-tv.png");
    vector<KeyPoint> keypointsD;
    Ptr<FastFeatureDetector> detector = FastFeatureDetector::create();
    detector->detect(imageIK, keypointsD, Mat());
    drawKeypoints(imageIK, keypointsD, imageIK);
    //    imshow("keypoints", imageIK);
}

void ImageTransformation::drawPoints(Mat image, int x, int y) {
    line(image, cv::Point2f(x, y), cv::Point2f(x, y), Scalar(0, 255, 0), 6);
}

vector<vector<cv::Point2f> > ImageTransformation::getFeaturePoints() {
    vector<vector<cv::Point2f> > rectangleVector;
    // IK - points
    rectangleVector.push_back({
        cv::Point2f(405, 219),
        cv::Point2f(657, 203),
        cv::Point2f(184, 216),
        cv::Point2f(92, 96),
    });
    //    rectangleVector.push_back({cv::Point2f(312, 257),
    //        cv::Point2f(453, 202),
    //        cv::Point2f(283, 208),
    //        cv::Point2f(487, 302)});
    //            rectangleVector.push_back({cv::Point2f(261, 149),
    //        cv::Point2f(442, 355),
    //        cv::Point2f(247, 210),
    //        cv::Point2f(222, 190)});
    // TV
    rectangleVector.push_back({
        cv::Point2f(527, 307),
        cv::Point2f(806, 289),
        cv::Point2f(280, 306),
        cv::Point2f(175, 185),
    });
    //    rectangleVector.push_back({cv::Point2f(408, 362),
    //        cv::Point2f(573, 296),
    //        cv::Point2f(383, 303),
    //        cv::Point2f(612, 408)});
    //            rectangleVector.push_back({cv::Point2f(409, 193),
    //        cv::Point2f(662, 485),
    //        cv::Point2f(388, 280),
    //        cv::Point2f(351, 251)});
    return rectangleVector;
}

void ImageTransformation::getImageTranslation() {
    vector<cv::Mat> testImages = {
        //        cv::imread("/home/ilya/test2-ik.png"),
        //        cv::imread("/home/ilya/test2-tv.png")
        cv::imread("/home/ilya/oes2/screenshoots/screenshoot_1_2020-03-05 13:59:18.jpg"),
        cv::imread("/home/ilya/oes2/screenshoots/screenshoot_0_2020-03-05 13:59:18.jpg")
    };
    vector<vector<cv::Point2f> > rectangleVector = getFeaturePoints();
    for (unsigned int iter = 0; iter < rectangleVector.size(); iter++) {
        for (int rectElem = 0; rectElem < 4; rectElem++) {
            drawPoints(testImages[iter], rectangleVector[iter][rectElem].x, rectangleVector[iter][rectElem].y);
        }
        imshow("Image" + to_string(iter), testImages[iter]);
    }
    Mat result = estimateRigidTransform(rectangleVector[1], rectangleVector[0], true);
    std::cout << "Translation matrix :" << endl << result << std::endl;
    warpAffine(testImages[1], testImages[0], result, testImages[0].size());
    imshow("Result of <estimationRigidTransform>", testImages[0]);
}

void ImageTransformation::overlayImages() {
    //    cv::Mat imageIK = cv::imread("/home/ilya/ls_1.png");
    //    cv::Mat imageTV = cv::imread("/home/ilya/ls_2.png");
    cv::Mat imageIK = cv::imread("/home/ilya/oes2/screenshoots2/sdf.png");
    cv::Mat imageTV = cv::imread("/home/ilya/oes2/screenshoots2/a1.png");
    OESFalseColor(imageIK, imageIK, HotMetal);
    Mat added_image;
    addWeighted(imageIK, 0.5, imageTV, 1, 0, added_image);
    imshow("Fused image", added_image);
}

ImageTransformation::ImageTransformation() {
    getImageTranslation();
    overlayImages();
    //    getSiftFeatures();
}

ImageTransformation::~ImageTransformation() {
}

