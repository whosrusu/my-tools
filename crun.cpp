#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

int main(){
    std::cout << "auto run" << std::endl;

    fs::path CurentPath = fs::current_path();
    fs::path crunPath = CurentPath / ".crun";

    std::ifstream FileRead(crunPath);

    if(!FileRead){
        std::cerr << "You need file .crun" << std::endl;
    }

    std::string command;

    while (std::getline(FileRead, command))
    {
        if(!command.empty()){
            system(command.c_str());
        }
    };
    

    FileRead.close();

    return 0;
}