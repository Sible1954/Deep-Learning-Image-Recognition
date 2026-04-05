
#include "model_loader.hpp"
#include <fstream>
#include <thread>
#include <chrono>

ModelLoader::ModelLoader() : is_model_loaded_(false) {
    std::cout << "ModelLoader initialized." << std::endl;
}

bool ModelLoader::load_model(const std::string& model_path) {
    std::cout << "  - Attempting to load model from: " << model_path << std::endl;
    std::ifstream file(model_path);
    if (!file.is_open()) {
        std::cerr << "  - Error: Model file not found at " << model_path << std::endl;
        is_model_loaded_ = false;
        return false;
    }
    file.close();

    loaded_model_path_ = model_path;
    model_name_ = model_path.substr(model_path.find_last_of("/") + 1);
    model_version_ = "1.0";
    is_model_loaded_ = true;
    std::cout << "  - Model '" << model_name_ << "' (version " << model_version_ << ") loaded successfully." << std::endl;
    return true;
}

bool ModelLoader::simulate_load(const std::string& model_path) {
    std::cout << "  - Simulating model load for: " << model_path << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    
    loaded_model_path_ = model_path;
    model_name_ = model_path.substr(model_path.find_last_of("/") + 1);
    model_version_ = "1.0-simulated";
    is_model_loaded_ = true;
    std::cout << "  - Simulated model '" << model_name_ << "' (version " << model_version_ << ") loaded successfully." << std::endl;
    return true;
}

std::string ModelLoader::get_model_name() const {
    return model_name_;
}

std::string ModelLoader::get_model_version() const {
    return model_version_;
}
