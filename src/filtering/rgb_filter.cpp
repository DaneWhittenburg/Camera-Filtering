#include <opencv2/opencv.hpp>
#include <iostream>
#include "rgb_filter.hpp"

cv::Mat rgb_filter(cv::Mat& frame, cv::Mat& initFrame) {
    for (int j = 0; j < frame.rows; j++) {
        for (int i = 0; i < frame.cols; i++) {
            // Pull BGR values
            cv::Vec3b BGR = frame.at<cv::Vec3b>(j, i);
            cv::Vec3b BGR0 = initFrame.at<cv::Vec3b>(j, i);
            
            // Access individual RGB values
            int blue = BGR[0];
            int green = BGR[1];
            int red = BGR[2];
            int blue0 = BGR0[0];
            int green0 = BGR0[1];
            int red0 = BGR0[2];

            // Filter out old pixels
            frame.at<cv::Vec3b>(j, i) = frame.at<cv::Vec3b>(j, i) - initFrame.at<cv::Vec3b>(j, i);
        }
    }
    return frame;
}