#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "bst.h"

void fillArray(std::vector <std::string> &arr, std::string infile) {
    
    std::ifstream in_file(infile);
    
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
    
}

int main() {
    
    ///Start Insert File
    
    std::string infile;
    std::vector <std::string> arr;
    
    bool goodfile = false;
    
    while (!goodfile) {
    
        std::cout << "What file do you want to store in a Left Leaning, Red Black, BST?" << std::endl;
        std::cin >> infile;
        
        std::ifstream fin(infile);
        
        if(!fin) {
            
            std::cout << "Unable to open the file" << std::endl;
            
        } else {
            
            goodfile = true;
            
        }
        
    }
    
    fillArray(arr, infile);
    
    BSTree n;
    std::string temp;

    for (int i = 0; i < arr.size(); i++) {
        
        temp = arr[i];
        
        n.insert(temp); 

    }
    
    bool run = true;
    char command;
    std::string word;
    bool search;
    int size;
    
    while (run) {
        
        ///Select Option
        std::cout << "Please Select a command: \n"
        << "C - Count How many times that word was inserted into the tree." << "\n"
        << "S - See if word is in the tree." << "\n"
        << "H - See how big the tree is." << "\n"
        << "R - Pre order." << "\n"
        << "O - Post order." << "\n"
        << "I - In order." << "\n"
        << "D - Generate Dot File." << "\n"
        << "Q - Quit." << "\n"
        << ":";
        
        std::cin >> command;
    
        if (command == 'C' || command == 'c') {
            
            std::cout << "Please insert the word you wish to check: ";
            
            std::cin >> word;
            
            std::cout << "That word was inserted into the tree " << n.count_helper(word) << " times." << std::endl;
            
        } else if (command == 'S' || command == 's') {
            
            std::cout << "Please insert the word you wish to search for: ";
            
            std::cin >> word;
            
            search = n.search(word);
            
            if (search) {
                
                std::cout << "That word is in the tree" << std::endl;
                
            } else {
                
                std::cout << "That word is not in the tree" << std::endl;
                
            }
            
        } else if (command == 'H' || command == 'h') {
            
            size = n.height();
            
            std::cout << "The tree is " << size << " big." << std::endl;
            
        } else if (command == 'R' || command == 'r') {
            
            std::ofstream of("pre");
            
            n.preorder(of);
            
        } else if (command == 'O' || command == 'o') {
            
            std::ofstream of("post");
            
            n.postorder(of);
            
        } else if (command == 'I' || command == 'i') {
            
            std::ofstream of("in");
            
            n.inorder(of);
            
        } else if (command == 'D' || command == 'd') {
            
            n.DOT("out");
            
        } else if (command == 'Q' || command == 'q') {
            
            run = false;
            
        } else {
            
            std::cout << "Invalid command, please try again. \n";
            
        }
        
    }

    return 0;

}