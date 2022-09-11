#include<iostream>
using namespace std;

class LinkedList{

private:

    struct Node{
        int value;
        Node* next;
    };

public:

    Node* listHeadAddress = nullptr;

    void printList(){

        Node* listTraverser = listHeadAddress;      
       
        while(listTraverser != nullptr){              
            cout << listTraverser->value << endl;   
            listTraverser = listTraverser->next;    
        }
    }

    void printListRecursive(Node* listTraverser){

        if(listTraverser == nullptr){
            return;
        }

        cout << listTraverser->value << endl;
        printListRecursive(listTraverser->next); 
    }

    void printListReverseRecursive(Node* listTraverser){

        if(listTraverser == nullptr){
            return;
        }

        printListReverseRecursive(listTraverser->next); 
        cout << listTraverser->value << endl;
    }

    void addNodeAtFront(int val){

        Node* newNode = new Node();
        newNode->value = val;
        newNode->next = listHeadAddress;
        listHeadAddress = newNode;      
    }

    void addNodeAtEnd(int val){

        Node* newNode = new Node();
        newNode->value = val;

        Node* listTraverser = listHeadAddress;

        if (listHeadAddress == nullptr){
            
            listHeadAddress = newNode;
            newNode->next = nullptr;
            return;
        }
        
        while(listTraverser->next != nullptr){
            listTraverser = listTraverser->next;
        }

        listTraverser->next = newNode;
        newNode->next = nullptr;
    }

    void addNodeAtPosition(int val, int pos){

        Node* newNode = new Node();
        newNode->value = val;

        if(pos == 1){

            newNode->next = listHeadAddress;
            listHeadAddress = newNode;
            return;
        }

        Node* listTraverser = listHeadAddress;

        for(int i = 0; i < pos-2; i++){
            listTraverser = listTraverser->next;
        } 

        newNode->next = listTraverser->next;
        listTraverser->next = newNode;
    }

    void deleteNodeAtEnd(){

        Node* listTraverser = listHeadAddress;

        while (listTraverser->next->next != nullptr){
            listTraverser = listTraverser->next;
        }

        Node* toBeDeleted = listTraverser->next;
        
        listTraverser->next = nullptr;
        delete toBeDeleted;
        toBeDeleted = nullptr;
    }

    void deleteNodeAtFront(){

        Node* firstNode = listHeadAddress;
        listHeadAddress = firstNode->next;

        delete firstNode;
        firstNode = nullptr;
    }

    void deleteNodeAtPosition(int pos){

        if(pos == 1){
            deleteNodeAtFront();
            return;
        }

        Node* listTraverser = listHeadAddress;

        for(int i = 0; i < pos-2; i++){
            listTraverser = listTraverser->next;
        } 
        
        Node* toBeDeleted = listTraverser->next;
        listTraverser->next = toBeDeleted->next;

        delete toBeDeleted;
        toBeDeleted = nullptr;
    }

    void deleteList(){

        if(listHeadAddress == nullptr){
            cout << "List is Empty" << endl;
            return;
        }

        Node* toBeDeleted = listHeadAddress;
        Node* nextNode = listHeadAddress->next;

        while(nextNode != nullptr){
            
            listHeadAddress = nextNode;
            delete toBeDeleted;
            toBeDeleted = nextNode;
            nextNode = nextNode->next;
        }

        delete toBeDeleted;
        listHeadAddress = toBeDeleted = nullptr;
        
        cout << "List Deleted Successfully" << endl;
    }

    void reverseList(){

        Node* current = listHeadAddress;
        Node* previous = nullptr;
        Node* nextNode;

        while(current != nullptr){

            nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        listHeadAddress = previous;
    }

    void reverseListRecursive(Node* listTraverser){

        if(listTraverser->next == nullptr){
            listHeadAddress = listTraverser;
            return;
        }

        reverseListRecursive(listTraverser->next);

        Node* previous = listTraverser->next;
        previous->next = listTraverser;
        listTraverser->next = nullptr;
    }

    void searchValue(int val){

        Node* listTraverser = listHeadAddress;
        bool found = false;
        int nodeNum = 1;

        while (listTraverser != nullptr){

            if(listTraverser->value == val){
                found = true;
                break;
            }
            else{
                listTraverser = listTraverser->next;
                nodeNum++;
            }
        }

        if(found){
            cout << val << " is located at Node number " << nodeNum << endl;
        }
        else
            cout << val << " is not located at any Node" << endl;
    }

};

int main()
{
    LinkedList l1;

    l1.addNodeAtFront(3);
    l1.addNodeAtEnd(5); 
    l1.addNodeAtEnd(6); 
    // l1.addNodeAtPosition(1, 2);
    // l1.deleteNodeAtEnd();
    // l1.deleteNodeAtFront();
    // l1.deleteNodeAtPosition(1);
    // l1.reverseList();
    // l1.searchValue(3);
    l1.deleteList();
    l1.printList();
    // l1.reverseListRecursive(l1.listHeadAddress);
    // l1.printListRecursive(l1.listHeadAddress);

    return 0;
}