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

            arr.push_back(val);

        }
    }


    BSTree n;
    std::string temp;

    for (int i = 0; i < arr.size(); i++) {

        temp = arr[i];

        n.insert(temp);

    }

    n.DOT("out");

    return 0;

}

