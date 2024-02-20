//
// Created by Eric Bravo on 1/24/24.
//

#include "tree.h"
#include <cstring>
#include <string.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>

int main(int argc, char **argv){


    std::string orgchartPath = argv[1];
    std::string testFile = argv[2];

    //std::string orgchartPath = "/Users/ericbravo/Desktop/orgchart copy.txt";
    //std::string testFile = "/Users/ericbravo/Desktop/testfile.txt";



    Tree tree;

    std::string filePath1 = orgchartPath;
    std::string filePath2 = testFile;




    std::ifstream file1(filePath1);
    if (!file1.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }


    std::string line;
    // Read the first line to get the number of levels
    if (getline(file1, line)) {
        std::istringstream iss(line);
        std::string temp;
        if (getline(iss, temp, '=')) { // Extract the part before '='
            if (getline(iss, temp)) { // Extract the part after '='
                tree.managerLevels = std::stoi(temp); // Convert string to int
                //levels = std::stoi(temp);
            }
        }
    }






    std::string secondLine;
    std::getline(file1,secondLine);

    vector<int> maxChildCount;

    std::istringstream iss(secondLine);
    int num;
    while (iss >> num) {
        tree.maxChildCount.push_back(num);

    }

    tree.maxChildCount.push_back(0);

    //add one more push (zero) back to allocate an empty space for add



    tree.rootNode = new employeeNode(tree.maxChildCount[0]);


    std::string line2;
    while(std::getline(file1,line2)){

        const char* input;
        input = line2.c_str();
        //std::cout << input << std::endl;

        tree.addEmployees(input);


    }

    //std::cout << "FILE 1 HAS BEEN READ" << std::endl;

    file1.close();


    // READS IN SECOND FILE: CALL FIND AND COUNT OPERATIONS
    std::ifstream file2(filePath2);

    while(getline(file2,testFile)){

        const char* input2;
        input2 = testFile.c_str();


        //stores found pointer node
        employeeNode* foundEmployee = tree.findEmployee(input2);


        if(foundEmployee == nullptr){
            unsigned int zero = 0;
            std::cout << input2 << " " << zero << std::endl;
        }else{
            unsigned int count = 0;
            tree.countNumOfEmployeesInOrgchart(foundEmployee,count);
            std::cout << input2 << " " << count << std::endl;
        }


    }
    return 0;

}
