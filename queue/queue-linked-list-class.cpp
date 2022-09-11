#include<iostream>
using namespace std;

class Queue{

private:

    struct Node{

        int value;
        Node* next;
    };

    Node* front = nullptr;
    Node* rear = nullptr;

public:

    void enqueue(int val){

        Node* newNode = new Node();
        newNode->value = val;
        newNode->next = nullptr;

        if(front == nullptr && rear == nullptr){
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue(){

        Node* frontNode = front;
        front = front->next;
        delete frontNode;
        frontNode = nullptr;
    }

    int frontVal(){
        return front->value;
    }

    bool isEmpty(){
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

        Node* queueTraverser = front;

        while (queueTraverser != nullptr){
            cout << queueTraverser->value << " ";
            queueTraverser = queueTraverser->next;
        }
    }

};

int main()
{
    Queue q1;

    q1.enqueue(5);
    q1.enqueue(3);
    q1.enqueue(8);
    q1.enqueue(1);
    q1.enqueue(7);
    q1.enqueue(9);
    q1.dequeue();
    q1.dequeue();
    // cout << "Front Val: " << q1.frontVal() << endl;
    q1.printQueue();
    // q1.isEmpty();

    return 0;
}