
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <filesystem>
#include <opencv2/opencv.hpp>
#include "image_processor.hpp"
#include "model_loader.hpp"

namespace fs = std::filesystem;

int main() {
    std::cout << "
--- Deep Learning Image Recognition System ---
" << std::endl;

    std::string input_image_path = "input_image.jpg";
    std::string output_image_path = "processed_image.jpg";
    std::string model_path = "model.onnx";

    std::cout << "Creating dummy input image..." << std::endl;
    cv::Mat dummy_image(400, 600, CV_8UC3, cv::Scalar(100, 150, 200));
    cv::imwrite(input_image_path, dummy_image);
    std::cout << "Dummy image '" << input_image_path << "' created." << std::endl;

    std::cout << "Loading image '" << input_image_path << "'..." << std::endl;
    cv::Mat image = cv::imread(input_image_path);
    if (image.empty()) {
        std::cerr << "Error: Could not open or find the image '" << input_image_path << "'." << std::endl;
        return -1;
    }
    std::cout << "Image loaded successfully. Dimensions: " << image.cols << "x" << image.rows << std::endl;

    std::cout << "Preprocessing image..." << std::endl;
    ImageProcessor processor;
    cv::Mat preprocessed_img = processor.preprocess_image(image);
    std::cout << "Image preprocessing complete. New dimensions: " << preprocessed_img.cols << "x" << preprocessed_img.rows << std::endl;
    cv::imwrite(output_image_path, preprocessed_img);
    std::cout << "Processed image saved to '" << output_image_path << "'." << std::endl;

    std::cout << "Loading deep learning model from '" << model_path << "'..." << std::endl;
    ModelLoader model_loader;
    if (model_loader.simulate_load(model_path)) {
        std::cout << "Model simulated loaded successfully." << std::endl;
    } else {
        std::cerr << "Error: Failed to simulate model load." << std::endl;
        return -1;
    }

    std::cout << "Simulating image classification..." << std::endl;
    std::vector<std::string> classes = {"cat", "dog", "bird", "car", "truck"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, classes.size() - 1);
    int class_idx = distrib(gen);
    std::uniform_real_distribution<> conf_distrib(0.7, 0.99);
    double confidence = conf_distrib(gen);

    char buffer[256];
    sprintf(buffer, "Classified: %s (Confidence: %.2f%%)", classes[class_idx].c_str(), confidence * 100);
    std::string result = buffer;
    std::cout << "Classification Result: " << result << std::endl;

    std::cout << "
--- Demonstration Complete ---
" << std::endl;

    std::cout << "Cleaning up dummy files..." << std::endl;
    if (fs::remove(input_image_path)) {
        std::cout << "Removed '" << input_image_path << "'." << std::endl;
    }
    if (fs::remove(output_image_path)) {
        std::cout << "Removed '" << output_image_path << "'." << std::endl;
    }

    return 0;
}
