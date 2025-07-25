#include <opencv2/opencv.hpp> // Image processing
#include <iostream> // Text outputting
#include <windows.h>

#include "filtering/rgb_filter.hpp"
#include "camera_functions/camera_functions.hpp"

int main() {
    // Initialize variables
    cv::Mat frame; // Matrix variable to store each frame
    cv::Mat initFrame;

    int cap_port = checkForVideo();
    if ((cap_port == -1)) {
        std::cout << "[error] No video found" << std::endl;
        return -1;
    }

    // Start stream on correct port
    cv::VideoCapture cap(cap_port); 
    int colmns = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int rows = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    const bool filter = true;
    // Grabs an initial image for filter
    if (filter) {
        std::cout << "Grabbing Initial Frame in 5s...";
        Sleep(5000);
        cap >> initFrame;
        std::cout << "Frame gotten" << std::endl;
    }

    // Loop to iterate through whilst accessing video frames
    while (true) {
        cap >> frame; // Assigns the frame to our variable, essentially grabs one image

        // Check for empty frame
        if (frame.empty()) { // Error Code
            std::cout << "[fatal] Empty frame" << std::endl;
            return -1;
        }

        if (filter) {
            rgb_filter(frame, initFrame);
        }
        // Displays Frame
        cv::imshow("Webcam Feed", frame);

        // Active command to end stream on "q"
        if (cv::waitKey(1) == 'q') {
            std::cout << "[Info] Manually Ended Stream" << std::endl;
            return 0;
        }
    }
}

