#include "fractal_generator.h"

int main() {
    GeneratorConfig settings = {729, 5};
    cv::Mat canvas(settings.frameSize, settings.frameSize, CV_8UC3, cv::Scalar(255, 255, 255));
    
    generatePattern(canvas, 0, 0, settings.frameSize, settings.maxSteps);
    visualizeResult(canvas);
    
    return 0;
}