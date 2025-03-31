#include "fractal_generator.h"
#include <omp.h>

void generatePattern(cv::Mat& surface, int posX, int posY, int blockSize, int currentStep) {
    if (currentStep == 0) return;
    
    int unit = blockSize / 3;
    cv::rectangle(surface, 
        cv::Point(posX + unit, posY + unit),
        cv::Point(posX + 2 * unit, posY + 2 * unit),
        cv::Scalar(0, 0, 0), 
        cv::FILLED
    );

    #pragma omp parallel for collapse(2)
    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            if (dx == 1 && dy == 1) continue;
            generatePattern(
                surface,
                posX + dx * unit,
                posY + dy * unit,
                unit,
                currentStep - 1
            );
        }
    }
}

void visualizeResult(const cv::Mat& output) {
    cv::imshow("Fractal Visualization", output);
    cv::waitKey(0);
}