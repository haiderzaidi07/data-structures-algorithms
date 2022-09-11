#include<iostream>
using namespace std;
#define MAX_SIZE 4

class Stack{

private:

    int doubleSize = MAX_SIZE;
    int* arr = new int[doubleSize];
    int topIndex = -1;

public:

    void push(int val){

        topIndex++;

        if(topIndex == doubleSize){

            doubleSize *= 2;

            int* arr2 = new int[doubleSize];

            for(int i = 0; i <= topIndex; i++){
                arr2[i] = arr[i];
            }

            delete[] arr;
            arr = arr2;
        }

        arr[topIndex] = val;
    }

    void pop(){
        topIndex--;
    }

    int top(){
        return arr[topIndex];
    }

    bool isEmpty(){
        if(topIndex <= -1){
            cout << "Stack is Empty" << endl;
            return true;
        }

        else{
            cout << "Stack is NOT Empty" << endl;
            return false;
        }
    }

    void printStack(){

        cout << "Stack: ";

        for(int i = 0; i <= topIndex; i++){

            if(i == topIndex) {
                cout << arr[i] << "(top)"; 
            }
            else
                cout << arr[i] << " ";
        }
    }

};

int main()
{

    Stack s1;

    s1.push(5);
    s1.push(1);
    s1.push(8);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.pop();
    // cout << "Top: " << s1.top() << endl;
    // s1.isEmpty();
    s1.printStack();

    return 0;
}