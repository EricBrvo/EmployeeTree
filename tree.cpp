//
// Created by Eric Bravo on 1/24/24.
//

#include "tree.h"


employeeNode::employeeNode(int maxChild){

    this->maxChild = maxChild;

    children = new employeeNode * [maxChild];
    for(int i=0; i<maxChild; i++){
        children[i] = nullptr;
    }

}



Tree::Tree() {
    //rootNode = new employeeNode(copyVector[0]);  //rootNode initialized with first value of
    //rootNode = new employeeNode(10);
    rootNode = nullptr;
}

bool Tree::addEmployees(const char *employeeIDPath) {

    employeeNode *currentNode = rootNode;
    int currentLevel = 0;


    for (unsigned int i = 0; i < strlen(employeeIDPath); i++) {   //iterates thru e_0_0_6_2

        char c = employeeIDPath[i];                    //stores each char in c

        // currentLevel > copyVector.size()
        if (currentLevel > managerLevels) {      //checks to see if we exceeded managerLevels
            return false;
        }
        //e_0_0_6_2
        if (isdigit(c)) {                                 // checks if digit then convert to int

            int insertionIndex = (c - '0');               //values of employeeID

            // e_0_0_6_4     <  8 6 9 5 7
            if (insertionIndex < maxChildCount[currentLevel]) {  //checks if index exceeds allowed childs

                if (currentNode->children[insertionIndex] == nullptr) {  //checks if the pointer at our insertion index is null

                    //if pointer at index is null, insert a node at that index
                    // CREATES NEW NODE WITH AMOUNT OF CHILDREN FOR THE NEXT LEVEL: HENCE +1
                    currentNode->children[insertionIndex] = new employeeNode(maxChildCount[currentLevel+1]);

                    //COME BACK TO THIS LINE: CAUSED SEG FAULT!!!!!

                }

                //move to next node at insertionIndex
                currentNode = currentNode->children[insertionIndex];
                currentLevel++;

                //insert new node at insertion index
            } else {

                //we want to stop inserting if insertionIndex is higher than allowed children
                return false;  //could be wrong?? double check
            }

        } else {
            continue;
        }

    }

    return true;

}


//find method: traverse given employeeP

//just like add function except for where we create new employee - just return false instead

employeeNode* Tree::findEmployee(const char *employeeIDPath){


    employeeNode *currentNode = rootNode;
    int currLevel = 0;



    for (unsigned int i = 0; i < strlen(employeeIDPath); i++){

        char c = employeeIDPath[i];


        //e_0_0_6_4
        if(isdigit(c)){

            int nodeIndex = (c-'0');

            if (currentNode->children[nodeIndex] == nullptr || nodeIndex >= maxChildCount[currLevel]){
                return nullptr;
            }else{
                currentNode = currentNode->children[nodeIndex];
            }

            currLevel++;

        }

    }

    return currentNode;

}

void Tree::countNumOfEmployeesInOrgchart(employeeNode* Node, unsigned int &count){

    count++;


    for(int i=0; i< Node->maxChild;i++){

        if(Node->children[i] == nullptr){
            continue;
        }

        countNumOfEmployeesInOrgchart(Node->children[i], count);


    }



}






