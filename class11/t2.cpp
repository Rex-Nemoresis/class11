#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;

int main(int argc, const char* argv[])
{
    Mat image = imread("D:/c11p2.jpg");
    Mat gray;
    if (image.empty())
    {
        std::cout << "Í¼Æ¬´ò¿ªÊ§°Ü" << std::endl;
        return -1;
    }
    imshow("yuan", image);
    waitKey();

    cvtColor(image, gray, CV_RGB2GRAY);
    int bins = 256;
    int hist_size[] = { bins };
    float range[] = { 0,256 };
    const float* ranges[] = { range };
    MatND hist;
    int channels[] = { 0 };

    calcHist(&gray, 1, channels, Mat(), hist, 1, hist_size, ranges, true, false);
    double max_val;
    minMaxLoc(hist, 0, &max_val, 0, 0);
    int scale = 2;
    int hist_height = 256;
    Mat hist_img = Mat::zeros(hist_height, bins * scale, CV_8UC3);
    for (int i = 1;i < bins;i++)
    {
        float bin_val = hist.at<float>(i);
        int intensity = cvRound(bin_val * hist_height / max_val);
        rectangle(hist_img, Point(i * scale, hist_height - 1), Point((i + 1) * scale - 1, hist_height - intensity), CV_RGB(255, 255, 255));
    }
    imshow("yuanzhifang", hist_img);;
    waitKey();

    Mat gray1, imageRGB[3];
    split(image, imageRGB);
    for (int i = 0;i < 3;i++)
    {
        equalizeHist(imageRGB[i], imageRGB[i]);
    }
    merge(imageRGB, 3, image);
    imshow("junheng", image);
    waitKey();

    cvtColor(image, gray1, CV_RGB2GRAY);
    calcHist(&gray1, 1, channels, Mat(), hist, 1, hist_size, ranges, true, false);
    minMaxLoc(hist, 0, &max_val, 0, 0);
    for (int i = 1;i < bins;i++)
    {
        float bin_val = hist.at<float>(i);
        int intensity = cvRound(bin_val * hist_height / max_val);
        rectangle(hist_img, Point(i * scale, hist_height - 1), Point((i + 1) * scale - 1, hist_height - intensity), CV_RGB(255, 255, 255));
    }
    imshow("zhifangtu", hist_img);
    waitKey();

    return 0;
}