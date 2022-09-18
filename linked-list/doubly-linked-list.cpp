#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node* previous;
};

Node* listHeadAddress = nullptr;
Node* listTailAddress = nullptr;

void addNodeAtEnd(int val){
    Node* newNode = new Node();
    newNode->value = val;

    if(listHeadAddress == nullptr){
        newNode->next = nullptr;
        newNode->previous = nullptr;
        listHeadAddress = newNode;
        listTailAddress = newNode;
        return;
    }

    listTailAddress->next = newNode;
    newNode->next = nullptr;
    newNode->previous = listTailAddress;
    listTailAddress = newNode;
}

void addNodeAtFront(int val){
    Node* newNode = new Node();
    newNode->value = val;

    if(listHeadAddress == nullptr){
        newNode->next = nullptr;
        newNode->previous = nullptr;
        listHeadAddress = newNode;
        listTailAddress = newNode;
        return;
    }

    newNode->next = listHeadAddress;
    newNode->previous = nullptr;
    listHeadAddress->previous = newNode;
    listHeadAddress = newNode;
}

void deleteNodeAtEnd(){
    Node* toBeDeleted = listTailAddress;

    listTailAddress->previous->next = nullptr;
    listTailAddress = listTailAddress->previous;
    delete toBeDeleted;
    toBeDeleted = nullptr;
}

void deleteNodeAtFront(){
    Node* toBeDeleted = listHeadAddress;

    listHeadAddress->next->previous = nullptr;
    listHeadAddress = listHeadAddress->next;
    delete toBeDeleted;
    toBeDeleted = nullptr;
}

void searchValue(int val){

    Node* forwardTraverser = listHeadAddress;
    Node* backwardTraverser = listTailAddress;

    while(forwardTraverser != nullptr || backwardTraverser != nullptr){
        if(forwardTraverser->value == val || backwardTraverser->value == val){
            cout << val << " is in the list" << endl;
            return;
        }
        forwardTraverser = forwardTraverser->next;
        backwardTraverser = backwardTraverser->previous;
    }

    cout << val << " is not in the list" << endl;    
}

void printForward(){
    Node* trav = listHeadAddress;

    while(trav != nullptr){
        cout << trav->value << " ";
        trav = trav->next;
    }
}

void printBackward(){
    Node* trav = listTailAddress;

    while(trav != nullptr){
        cout << trav->value << " ";
        trav = trav->previous;
    }
}

int main()
{
    // Node* firstNode = new Node();
    // firstNode->value = 4;
    // firstNode->next = nullptr;
    // firstNode->previous = nullptr;
    // listHeadAddress = firstNode;
    // listTailAddress = firstNode;

    // Node* secondNode = new Node();
    // secondNode->value = 6;
    // secondNode->next = nullptr;
    // secondNode->previous = firstNode;

    // Node* thirdNode = new Node();
    // thirdNode->value = 7;
    // thirdNode->next = nullptr;
    // thirdNode->previous = secondNode;


    addNodeAtEnd(3);
    addNodeAtEnd(6);
    addNodeAtFront(5);
    addNodeAtEnd(1);
    // deleteNodeAtEnd();
    // deleteNodeAtFront();
    searchValue(9);

    printForward();
    cout << endl;
    printBackward();

    return 0;
}
