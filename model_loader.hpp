
#ifndef MODEL_LOADER_HPP
#define MODEL_LOADER_HPP

#include <string>
#include <iostream>
#include <vector>

class ModelLoader {
public:
    ModelLoader();
    bool load_model(const std::string& model_path);
    bool simulate_load(const std::string& model_path);
    std::string get_model_name() const;
    std::string get_model_version() const;

private:
    std::string loaded_model_path_;
    std::string model_name_;
    std::string model_version_;
    bool is_model_loaded_;
};

#endif // MODEL_LOADER_HPP
