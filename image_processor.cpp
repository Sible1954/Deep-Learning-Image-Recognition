
#include "image_processor.hpp"

ImageProcessor::ImageProcessor() {
    std::cout << "ImageProcessor initialized." << std::endl;
}

cv::Mat ImageProcessor::preprocess_image(const cv::Mat& input_image, int size) const {
    cv::Mat processed_image;
    cv::resize(input_image, processed_image, cv::Size(size, size));
    processed_image.convertTo(processed_image, CV_32FC3, 1.0 / 255.0);
    std::cout << "  - Image resized to " << size << "x" << size << " and normalized." << std::endl;
    return processed_image;
}

cv::Mat ImageProcessor::convert_to_grayscale(const cv::Mat& input_image) const {
    cv::Mat grayscale_image;
    if (input_image.channels() == 3) {
        cv::cvtColor(input_image, grayscale_image, cv::COLOR_BGR2GRAY);
        std::cout << "  - Image converted to grayscale." << std::endl;
    } else {
        grayscale_image = input_image.clone();
        std::cout << "  - Image is already grayscale or single channel, no conversion needed." << std::endl;
    }
    return grayscale_image;
}

cv::Mat ImageProcessor::apply_gaussian_blur(const cv::Mat& input_image, int kernel_size) const {
    cv::Mat blurred_image;
    if (kernel_size % 2 == 0) {
        kernel_size += 1;
    }
    cv::GaussianBlur(input_image, blurred_image, cv::Size(kernel_size, kernel_size), 0);
    std::cout << "  - Gaussian blur applied with kernel size " << kernel_size << "." << std::endl;
    return blurred_image;
}

cv::Mat ImageProcessor::detect_edges(const cv::Mat& input_image, double low_threshold, double high_threshold) const {
    cv::Mat edges;
    cv::Mat gray_image = convert_to_grayscale(input_image);
    cv::Canny(gray_image, edges, low_threshold, high_threshold);
    std::cout << "  - Edges detected using Canny algorithm." << std::endl;
    return edges;
}
