#include<iostream>
using namespace std;

struct Node{
    
    int value;
    Node* next;
};

// Note: We could implement stack using linked list in two different ways:
// 1) Making top the first node
// 2) Making top the last node
// We choose option one because then the functions will have a time complexity of O(1) rather than O(n) in 2) because we would have to traverse
// the whole linked list first in that

// top initally assigned to null which will be modified later and will be reflected throughout the program as it is a global variable
Node* top = nullptr;

void push(int val){

    // Creating a new node and assigning it the value passed as the parameter
    Node* newNode = new Node();
    newNode->value = val;

    // Making the next variable of the newNode to point to (store the address of) the top node  
    newNode->next = top;
    // Making the top pointer store the address of the newNode hence making it the top node
    top = newNode;
}

void pop(){

    // Storing the address of the current top in a seperate pointer 
    Node* currentTop = top;
    // Making the top pointer point to(store address of) the next variable of the current top hence making it the new top node
    top = currentTop->next;
    // Deleting(deallocating memory of) the current(now previous) top node
    delete currentTop;
}

int topVal(){
    // Printing the value stored in the top node
    cout << "Top Value: " << top->value << endl;
    return top->value;
}

bool isEmpty(){
    // Condition to check if top points to null which it will eventually when the pop method is invoked many times
    if(top == nullptr){
        cout << "Stack is Empty" << endl;
        return true;
    }

    else{
        cout << "Stack is NOT Empty" << endl;
        return false;
    }
}

void printStack(){

    // Making a traverser pointer so that we do not lose the address of the first node stored in top
    Node* stackTraverser = top;

    // Condition to check if the address stored is not null / does not point to null
    while (stackTraverser != nullptr)
    {
        // cout << "Address: " << stackTraverser << endl;
        // Print value at the current node
        cout << stackTraverser->value << " ";
        // Store the address of the next node / point to the next node 
        stackTraverser = stackTraverser->next;
    }
}

int main()
{
    push(3);
    push(6);
    push(9);
    push(4);
    pop();
    pop();
    pop();
    pop();
    isEmpty();
    // topVal();
    printStack();

    return 0;
}