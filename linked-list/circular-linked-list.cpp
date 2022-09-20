#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* listHeadAddress = nullptr;

void addNodeAtEnd(int val){

    Node* newNode = new Node();
    newNode->value = val;

    Node* listTraverser = listHeadAddress;

    if (listHeadAddress == nullptr){
        
        listHeadAddress = newNode;
        newNode->next = listHeadAddress;
        return;
    }
    
    while(listTraverser->next != listHeadAddress){
        listTraverser = listTraverser->next;
    }

    listTraverser->next = newNode;
    newNode->next = listHeadAddress;
}

void addNodeAtFront(int val){

    Node* newNode = new Node();
    newNode->value = val;

    if(listHeadAddress == nullptr){

        listHeadAddress = newNode;
        newNode->next = listHeadAddress;
        return; 
    }

    Node* listTraverser = listHeadAddress;

    while(listTraverser->next != listHeadAddress){
        listTraverser = listTraverser->next;
    }

    listTraverser->next = newNode;
    newNode->next = listHeadAddress;
    listHeadAddress = newNode;
}

void deleteNodeAtEnd(){
    Node* listTraverser = listHeadAddress;
    Node* previous = nullptr;

    while(listTraverser->next != listHeadAddress){
        previous = listTraverser;
        listTraverser = listTraverser->next;
    }

    previous->next = listHeadAddress;
    Node* toBeDeleted = listTraverser;
    delete toBeDeleted;
    toBeDeleted = nullptr;
}

void deleteNodeAtFront(){
    Node* listTraverser = listHeadAddress;

    while(listTraverser->next != listHeadAddress){
        listTraverser = listTraverser->next;
    }

    listTraverser->next = listHeadAddress->next;

    Node* toBeDeleted = listHeadAddress;
    listHeadAddress = listHeadAddress->next;

    delete toBeDeleted;
    toBeDeleted = nullptr;
}

void printList(){

    Node* listTraverser = listHeadAddress;      
    
    do{              
        cout << listTraverser->value << " ";   
        listTraverser = listTraverser->next;    
    }
    while(listTraverser != listHeadAddress);
}

void searchValue(int val){

    Node* listTraverser = listHeadAddress;
    bool found = false;
    int nodeNum = 1;

    do{

        if(listTraverser->value == val){
            found = true;
            break;
        }
        else{
            listTraverser = listTraverser->next;
            nodeNum++;
        }
    }
    while (listTraverser != listHeadAddress);

    if(found){
        cout << val << " is located at Node number " << nodeNum << endl;
    }
    else
        cout << val << " is not located at any Node" << endl;
}

int main()
{
    addNodeAtEnd(4);
    addNodeAtEnd(7);
    addNodeAtEnd(5);
    addNodeAtFront(1);
    addNodeAtFront(8);
    // searchValue(5);
    deleteNodeAtEnd();
    deleteNodeAtFront();
    printList();


    return 0;
}