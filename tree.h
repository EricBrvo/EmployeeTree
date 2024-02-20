#ifndef CS480_ASSIGNMENT1_TREE_H
#define CS480_ASSIGNMENT1_TREE_H



#include <cstring>
#include <string.h>
#include <iostream>
#include <fstream>
#include <queue>


using namespace std;

class employeeNode {
public:
    employeeNode** children;
    employeeNode(int maxChild);
    int maxChild;

};

class Tree {
public:
    Tree();
    vector<int> maxChildCount;
    int managerLevels;
    employeeNode* rootNode;

    bool addEmployees(const char *employeeIDPath);
    employeeNode* findEmployee(const char *employeeIDPath);
    void countNumOfEmployeesInOrgchart(employeeNode* Node, unsigned int &count);
};


#endif //CS480_ASSIGNMENT1_TREE_H