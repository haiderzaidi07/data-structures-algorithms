#include<iostream>
using namespace std;

class Stack{

private:

    struct Node{
        int value;
        Node* next;
    };

    Node* top = nullptr;

public:

    void push(int val){

        Node* newNode = new Node();
        newNode->value = val;
        newNode->next = top;
        top = newNode;
    }

    void pop(){

        Node* currentTop = top;
        top = currentTop->next;
        delete currentTop;
    }

    int topVal(){
        cout << endl << "Top Value: " << top->value << endl;
        return top->value;
    }

    bool isEmpty(){
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

        Node* stackTraverser = top;

        while (stackTraverser != nullptr)
        {
            cout << stackTraverser->value << " ";
            stackTraverser = stackTraverser->next;
        }
    }

};

int main()
{

    Stack s1;

    s1.push(3);
    s1.push(9);
    s1.push(1);
    s1.pop();
    s1.printStack();
    s1.topVal();

    return 0;
}