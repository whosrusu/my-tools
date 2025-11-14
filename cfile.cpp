#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]){

    auto fileName = argv[1];

    if(!fileName){
        std::cerr << "You need to specify a name" << std::endl;
        return 1;
    };

    fs::path TerminalPath = fs::current_path();

    fs::path FilePath = TerminalPath / fileName;
    
    if(!fs::exists(FilePath.parent_path())){
        fs::create_directories(FilePath.parent_path());
    }

    std::ofstream File(FilePath);

    if(!File.is_open()){
        std::cout << "Error File Open" << std::endl;

        return 1;
    }

    if(!File){
        std::cout << "error" << std::endl;
        return 1;
    }

    if(argc >= 3 && std::string(argv[2]) == "-w"){
        std::string text = "";
        for(int i = 3; i < argc; i++){
            text += argv[i];
        };

        size_t pos = 0;
        while ((pos = text.find(";", pos)) != std::string::npos) {
            text.replace(pos, 1, ";\n");
            pos += 3;
        }

        
        File << text;
    }

    File.close();

    return 0;
}