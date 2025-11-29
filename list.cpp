#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    
    std::string path = ".";

    for(const auto&dr:fs::directory_iterator(path)){
        if(dr.is_directory())
        {
            std::cout << "\033[33m" << dr.path().filename().string() << "\033[0m" << std::endl;
        }
        else 
        {
            std::cout << "\033[34m" << dr.path().filename().string() << "\033[0m" << std::endl;
        }

    };

    return 0;

}