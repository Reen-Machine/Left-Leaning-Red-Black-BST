#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "bst.h"

int main(int argc, char **argv) {

    std::string in_fname = argv[1];

    std::ifstream in_file(argv[1]);

    std::vector <std::string> arr;
    std::string line;
    std::string val;

    while(std::getline(in_file, line)) {

        std::istringstream word(line);

        while (word >> val) {

            for (int i = 0; i < val.size(); i++) {

                if (val[i] > 122 || (val[i] < 97 && val[i] > 90) || val[i] < 65) {

                    val.erase(i);

                }

                if (val[i] <= 90 && val[i] >= 65) {

                    val[i] += 32;

                }

            }

            if (val.size() > 0) {

                arr.push_back(val);

            }

        }
    }

    BSTree n;
    std::string temp;

    for (int i = 0; i < arr.size(); i++) {
        
        temp = arr[i];
        
        n.insert(temp); 

    }
    
    std::cout << n.count_helper("bee") << std::endl;

    n.DOT("out");

    return 0;

}