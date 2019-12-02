/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FalseColor.cpp
 * Author: ilya
 * 
 * Created on April 15, 2019, 2:32 PM
 */

#include "FalseColor.h"
#include <fstream>
#include <iostream>
#include "LutTables.h"
#include "opencv2/imgproc.hpp"

FalseColor::FalseColor() {
}

FalseColor::~FalseColor() {
}

cv::Mat lutPet;
cv::Mat lutHotMetal;
cv::Mat lutHotIron;
cv::Mat lutPet20Step;

cv::Mat& getLut(OESFalseColorPalette palette) {

    if (lutHotIron.cols == 0)
        lutHotIron = cv::Mat(1, 256, CV_8UC3, (void*) dataHotIron);
    if (lutHotMetal.cols == 0)
        lutHotMetal = cv::Mat(1, 256, CV_8UC3, (void*) dataHotMetal);
    if (lutPet.cols == 0)
        lutPet = cv::Mat(1, 256, CV_8UC3, (void*) dataPet);
    if (lutPet20Step.cols == 0)
        lutPet20Step = cv::Mat(1, 256, CV_8UC3, (void*) dataPet20Step);

    switch (palette) {
        case OESFalseColorPalette::HotIron:
            return lutHotIron;
        case OESFalseColorPalette::HotMetal:
            return lutHotMetal;
        case OESFalseColorPalette::Pet:
            return lutPet;
        case OESFalseColorPalette::Pet20Step:
            return lutPet20Step;
        default:
            assert(true && "Wrong palette");
            break;
    }
    return lutPet;
}

bool OESFalseColor(const cv::Mat& inputArray, cv::Mat& outputArray,
        OESFalseColorPalette palette) {
    cv::Mat& lut = getLut(palette);
    if (inputArray.type() == CV_8U) {
        cv::cvtColor(inputArray, outputArray, CV_GRAY2RGB);
        cv::LUT(outputArray, lut, outputArray);
    } else
        cv::LUT(inputArray, lut, outputArray);
    cv::cvtColor(outputArray, outputArray, CV_RGB2BGR);

    return true;
}
