#include <string>
#include <iostream>

#include "bst.h"

int main(int argc, char **argv) {
    
    std::string in_fname = argv[1];
    
    std::ifstream in_file(in_fname);

    while(std::getline(in_file, line)) {

        std::vector <std::string> arr;
        std::istringstream word(line);
        
        while (word >> val) {

            arr.push_back(val);

        }
        
    }
    
    return 0;
    
}