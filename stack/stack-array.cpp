#include<iostream>
using namespace std;
#define MAX_SIZE 4

// All 3 are global variables because we access them all in the functions below

// doubleSize initally assigned the original max value which is 4 and will be modified later and stored for elsewhere
int doubleSize = MAX_SIZE;
// Allocating memory of doubleSize on the heap and its starting address stored in the pointer arr i.e a dynamic array
int* arr = new int[doubleSize];
// topIndex initialised to -1 as indexing starts from 0
int topIndex = -1;

void push(int val){

    // Incrementing the topIndex
    topIndex++;

    // Checking if the topIndex is equal to the size because the largest index is size-1, therefore if true means that index is invalid
    if(topIndex == doubleSize){

        // cout << "Top Index: " << topIndex << endl;
        // cout << "Double Size: " << doubleSize << endl;
        // cout << "Size Exceeded" << endl;

        // Doubling the size variable which will be changed throughout the program
        doubleSize *= 2;

        // Allocating memory of new doubleSize on the heap and its starting address stored in the pointer arr2 i.e a dynamic array
        int* arr2 = new int[doubleSize];

        // Copying all the elements from the old array into the new one
        for(int i = 0; i <= topIndex; i++){
            arr2[i] = arr[i];
        }

        // Deleting the old array contents and the starting address of the array/deallocating the memory
        delete[] arr;
        // Making the arr pointer store starting address of arr2
        arr = arr2;
    }

    // Assigning value at the topIndex position
    arr[topIndex] = val;
}

void pop(){
    // Decrementing the topIndex
    // Q. Why don't we delete the value at the topIndex?
    // Ans. Because the value will be automatically overwritten when we call the push method therefore there is no need
    topIndex--;
}

int top(){
    // Returns the value stored in the topIndex of the array
    return arr[topIndex];
}

bool isEmpty(){
    // Condition to check if the topIndex is less than or equal to -1, which it will be eventually if we call pop method many times
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

    // Looping only till the topIndex hence not traversing the whole array
    for(int i = 0; i <= topIndex; i++){

        if(i == topIndex) {
            cout << arr[i] << "(top)"; 
        }
        else
            cout << arr[i] << " ";
    }
}

int main()
{
    
    push(5);
    push(9);
    push(3);
    push(1);
    push(7);
    pop();

    // cout << "Top Value: " << top() << endl;
    isEmpty();
    printStack();

    // cout << endl << "Top Index: " << topIndex << endl;
    // cout << endl << "Size of Stack: " << doubleSize;

    return 0;
}