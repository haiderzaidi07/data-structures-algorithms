#include<iostream>
using namespace std;

struct Node{

    int value;
    Node* next;
};

// Pointer to store address of the first node of the queue 
Node* front = nullptr;
// Pointer to store address of the last node of the queue
Node* rear = nullptr;
// Q. Why do we need this pointer when we can traverse the whole queue with the front pointer?
// Ans: Because we want our functions/methods to have a time complexity of O(1) rather than O(n) as it would be with just the front pointer

void enqueue(int val){

    // Creating a new node, assigning it the value passed and making it point to null as it is at the end of the queue
    Node* newNode = new Node();
    newNode->value = val;
    newNode->next = nullptr;

    // Condition to check if front and rear points to null i.e whether the queue is empty or not
    // If true, store address of the new node in front as well as rear i.e make it the front and end of the queue
    if(front == nullptr && rear == nullptr){
        front = newNode;
        rear = newNode;
        return;
    }

    // If queue is not empty, store the address of the new node in the current last node's next property  
    rear->next = newNode;
    // Store address of the newNode in the rear pointer hence making it the new last node 
    rear = newNode;
}

void dequeue(){

    // Copying the address of the front node into frontNode
    Node* frontNode = front;
    // Making front point to(store address of) the second node in the queue therefore making it the new front node
    front = front->next;
    // Deleting/Deallocating the memory of the original front node
    delete frontNode;

    // cout << "Front Node: " << frontNode << endl;
    
    // Making frontNode point to null so it no longer has address of the deleted node
    frontNode = nullptr;
    
    // cout << "Front Node: " << frontNode << endl;
}

int frontVal(){
    // Printing the value stored in the front node
    return front->value;
}

bool isEmpty(){
    
    // Condition to check if top points to null which it will eventually when the pop method is invoked many times
    if(front == nullptr){
        cout << "Queue is Empty" << endl;
        return true;
    }

    else{
        cout << "Queue is NOT Empty" << endl;
        return false;
    }
}

void printQueue(){

    // Making a traverser pointer so that we do not lose the address of the front node stored in front
    Node* queueTraverser = front;

    // Condition to check if the address stored is not null / does not point to null
    while (queueTraverser != nullptr){
        // Print value at the current node
        cout << queueTraverser->value << " ";
        // Store the address of the next node / point to the next node 
        queueTraverser = queueTraverser->next;
    }
    
}

int main()
{
    enqueue(3);
    enqueue(5);
    enqueue(7);
    // enqueue(1);
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    cout << "Front Value: " << frontVal() << endl;
    isEmpty();
    printQueue();

    return 0;
}