/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FalseColor.h
 * Author: ilya
 *
 * Created on April 15, 2019, 2:32 PM
 */

#ifndef FALSECOLOR_H
#define FALSECOLOR_H
#include <opencv/cv.h>

class FalseColor {
public:
    FalseColor();
    virtual ~FalseColor();
private:

};

enum OESFalseColorPalette { HotIron, HotMetal, Pet , Pet20Step };

bool OESFalseColor(const cv::Mat& inputArray, cv::Mat& outputArray, 
        OESFalseColorPalette palette);

#endif /* FALSECOLOR_H */

