#ifndef FRACTAL_GENERATOR_H
#define FRACTAL_GENERATOR_H

#include <opencv2/opencv.hpp>

struct GeneratorConfig {
    int frameSize;
    int maxSteps;
};

void generatePattern(cv::Mat& surface, int posX, int posY, int blockSize, int currentStep);
void visualizeResult(const cv::Mat& output);

#endif