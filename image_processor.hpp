
#ifndef IMAGE_PROCESSOR_HPP
#define IMAGE_PROCESSOR_HPP

#include <opencv2/opencv.hpp>
#include <iostream>

class ImageProcessor {
public:
    ImageProcessor();
    cv::Mat preprocess_image(const cv::Mat& input_image, int size = 224) const;
    cv::Mat convert_to_grayscale(const cv::Mat& input_image) const;
    cv::Mat apply_gaussian_blur(const cv::Mat& input_image, int kernel_size = 5) const;
    cv::Mat detect_edges(const cv::Mat& input_image, double low_threshold = 50, double high_threshold = 150) const;
};

#endif // IMAGE_PROCESSOR_HPP
