#include <iostream>
#include <opencv2/opencv.hpp>

// Returns the cap_port of the video
int checkForVideo() {
    // Initialize Variables
    const int tries = 5; // Set to # of usb devices connected to ensure video capture

    // Loop to find correct video port
    std::cout << "[info] Finding video stream..." << std::endl;
    for (int i = 0; i < tries; i++) {
        std::cout << "[info] Trying port " << i << std::endl;
        cv::VideoCapture cap(i);

        // Check if port worked
        if (cap.isOpened()) {
            std::cout << "[info] Video captured on port " << i << std::endl;
            return i;
        }
        else if ((tries - i) == 1) { // If last iteration
            std::cout << "[fatal] No video found, check if the device is plugged in and shared" << std::endl;
            return -1;
        }
        else {
            std::cout << "[error] Port " << i << " failed" << std::endl;
        }
    }
}

void getInitFrame() {
    
}