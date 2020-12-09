/*#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace cv;
using namespace std;

// Normalizes a given image into a value range between 0 and 255.
Mat norm_0_255(const Mat& src) {
    // Create and return normalized image:
    Mat dst;
    switch (src.channels()) {
    case 1:
        cv::normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
        break;
    case 3:
        cv::normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
        break;
    default:
        src.copyTo(dst);
        break;
    }
    return dst;
}

int main(int argc, const char* argv[]) {
    // Get filename to the source image:
    // Load image & get skin proportions:
    Mat image = imread("D:/c11p1.jpg");
    // Convert to floating point:
    Mat X;
    image.convertTo(X, CV_32FC1);
    //image.convertTo(X, CV_32F);
    // Start preprocessing:
    Mat I;
    float gamma = 0.5;
    pow(X, gamma, I);


    // Draw it on screen:
    imshow("Original Image", image);
    waitKey();
    imshow("Gamma correction image", norm_0_255(I));
    // Show the images:
    waitKey();
    // Success!
    return 0;
}*/