#include<iostream>
using namespace std;

struct Node{

    int value;
    Node* next;
};

Node* listHeadAddress = nullptr;

void printList(){

    // Making a traverser pointer so that we do not lose the address of the first node stored in listHeadAddress
    Node* listTraverser = listHeadAddress;      
    // Q: What does listHeadAddress store and why? 
    // Ans: Stores whatever is the address of the first node atm, since global variables are stored seperately in memory and can be modified
    // from anywhere in the program and destroyed only when program finishes execution, hence listTraverser stores a copy from that global variable

    // cout << listHeadAddress << endl;
    // cout << listTraverser->value << endl;
    // cout << headptr->next->value << endl;

    // Condition to check if the address stored is not null / does not point to null
    while(listTraverser != nullptr){            
       
        // Print value at the current node
        // cout << "Address: " << listTraverser << endl;   
        cout << listTraverser->value << endl;   
        // Store the address of the next node / point to the next node 
        listTraverser = listTraverser->next;    
    }
}

// In the following two functions and the reverseListRecursive function we have added listTraverser as a parameter for 2 reasons:
// 1. So that we don't have to use the listHeadAddress itself thereby modifing its value instead passing its value as a copy
// 2. We haven't made the listTraverser as a local variable in the function body because it will be intialised for every call 
// and make an infinite loop because it will always points to(stores address of) the first node
void printListRecursive(Node* listTraverser){

    // Checking if list traverser is pointing to null(i.e storing null as address). If true return and don't continue further
    if(listTraverser == nullptr){
        return;
    }

    // Printing the value at the address pointed to (or address stored of) currently
    cout << listTraverser->value << endl;
    // Recursive call to the function itself, passing the address of the next node as arguement
    printListRecursive(listTraverser->next); 
}

void printListReverseRecursive(Node* listTraverser){

    // Checking if list traverser is pointing to null(i.e storing null as address). If true return and don't continue further    
    if(listTraverser == nullptr){
        return;
    }

    // Recursive call to the function itself, passing the address of the next node as arguement
    printListReverseRecursive(listTraverser->next); 
    // Printing the value at the address pointed to (or address stored of) currently    
    cout << listTraverser->value << endl;
}

void addNodeAtEnd(int val){

    // Making a new Node and assigning it the value
    Node* newNode = new Node();
    newNode->value = val;

    // Traverser Node pointer to move across the list to its end / storing the address of the last node eventually
    Node* listTraverser = listHeadAddress;

    // cout << listTraverser << endl;

    // Looping till we reach the current last node (as its next will point to null)
    while(listTraverser->next != nullptr){
        listTraverser = listTraverser->next;
    }

    // cout << listTraverser << endl;

    // Changing the node the current last points to from null to the new Node / Store the address of the new Node
    listTraverser->next = newNode;
    // Making the new Node point to null
    newNode->next = nullptr;
}

void addNodeAtFront(int val){

    // Making a new Node and assigning it the value
    Node* newNode = new Node();
    newNode->value = val;
    // Making the new Node point to(store the address of) the current first/head node of the list
    newNode->next = listHeadAddress;

    // Making the new Node the new first/head node of the list / Making listHeadAddress pointer store address of the new Node
    // Q. Why does this value stay outside the function itself?
    // Ans: Because listHeadAddress is a global variable, which is stored seperately in memory and changes to its value is visible throughout
    // the program
    listHeadAddress = newNode;     

    // cout << listHeadAddress << endl;
}

void addNodeAtPosition(int val, int pos){

    // Making a new Node and assigning it the value
    Node* newNode = new Node();
    newNode->value = val;

    // Condition to check whether node is to be inserted at the first position or not
    if(pos == 1){

        // Making the new Node point to(i.e store address of) the original first node(currently stored in listHeadAddress)
        newNode->next = listHeadAddress;
        // Making the Node*(i.e a variable that can store address of type Node) listHeadAddress point to(store address of) the new Node
        // Hence making it head of the list
        listHeadAddress = newNode;
        // Returning from the function as we don't want to execute the remaining statments
        return;
    }

    // Making a list traverser variable and copying the address of the first node
    Node* listTraverser = listHeadAddress;

    // Looping till we get the address of the (n-1)th node i.e the last node after which we insert the new Node at position n
    // Q. Why n-2?
    // Ans: So that we end up with the (n-1)th node's address stored in listTraverser which will later change links
    for(int i = 0; i < pos-2; i++){
        listTraverser = listTraverser->next;
    } 
     
    // cout << "List Traverser: " << listTraverser << endl;
    
    // Establishing a link between the new node and current nth node 
    // i.e Making the new node point to(store address) of the current nth node
    newNode->next = listTraverser->next;
    // Making the (n-1)th node point to(store address of) the newNode therefore establishing a link between the two 
    // and making newNode the new nth node
    listTraverser->next = newNode;

    // The order of those 2 statments is important because if we do them in reverse, we would lose the address of the current nth node 
    // and hence cannot establish the link between it and the new node
}

void deleteNodeAtEnd(){

    // Making a traverser pointer so that we do not lose the address of the first node stored in listHeadAddress
    Node* listTraverser = listHeadAddress;

    // Looping till we find the address of the second last node
    while (listTraverser->next->next != nullptr){
        listTraverser = listTraverser->next;
    }

    // cout << "List Traverser After: " << listTraverser << endl;

    // For storing the address of the last node i.e the node we want to delete
    Node* toBeDeleted = listTraverser->next;

    // cout << "ToBeDel: " << toBeDel << endl;
    
    // Making the second last node point to null
    listTraverser->next = nullptr;
    // Deleting/Deallocating the memory of the last node
    delete toBeDeleted;
    // Making toBeDeleted point to null so it no longer has address of the deleted node
    toBeDeleted = nullptr;

    // cout << "Value: " << toBeDeleted->value << endl; 
}

void deleteNodeAtFront(){

    // Storing the address of the current first/head node
    Node* firstNode = listHeadAddress;

    // cout << "Address of First Node: " << firstNode << endl;
    // cout << "Value at First Node Before: " << firstNode->value << endl;
    // cout << "Address of Second Node: " << firstNode->next << endl;

    // Making the listHeadAddress point to(store address of) the second node thereby making it the new first/head node
    listHeadAddress = firstNode->next;
    // Deleting/Deallocating the memory of the original first/head node
    delete firstNode;
    // Making firstNode point to null so it no longer has address of the deleted node
    firstNode = nullptr;

    // cout << "Address of First Node: " << firstNode << endl;
    // cout << "Value at First Node After: " << firstNode->value << endl;
}

void deleteNodeAtPosition(int pos){

    // Checking whether to delete node at the first/head position or not
    if(pos == 1){
        // Storing the address of the current first/head node
        Node* firstNode = listHeadAddress;
        // Making the listHeadAddress point to(store address of) the second node thereby making it the new first/head node
        listHeadAddress = firstNode->next;

        // Deleting/Deallocating the memory of the original first/head node
        delete firstNode;
        // Making firstNode point to null so it no longer has address of the deleted node
        firstNode = nullptr;
        return;
    }

    // Making a list traverser variable
    Node* listTraverser = listHeadAddress;

    // Looping till we get the address of the (n-1)th node i.e the last node after which we delete the node at position n
    // Q. Why n-2?
    // Ans: So that we end up with the (n-1)th node's address stored in listTraverser which will later change links
    for(int i = 0; i < pos-2; i++){
        listTraverser = listTraverser->next;
    } 
    
    // cout << "List Traverser: " << listTraverser << endl;

    // For storing the address of the nth node i.e the node we want to delete
    Node* toBeDeleted = listTraverser->next;

    // cout << "Node To Be Deleted: " << toBeDeleted << endl;
    // cout << "Value at Node To Be Deleted: " << toBeDeleted->value << endl;
    // cout << "Node after the one to be Deleted: " << toBeDeleted->next << endl;

    // Establishing the link between the (n-1)th node and (n+1)th node i.e making the (n-1)th node point to(store address of) the (n+1)th node
    listTraverser->next = toBeDeleted->next;
    // Deleting/Deallocating the memory of the nth node
    delete toBeDeleted;
    // Making toBeDeleted point to null so it no longer has address of the deleted node
    toBeDeleted = nullptr;

    // cout << "\nNode To Be Deleted: " << toBeDeleted << endl;
    // cout << "Value at Node To Be Deleted: " << toBeDeleted->value << endl;
    // cout << "Node after the one to be Deleted: " << toBeDeleted->next << endl;
}

void deleteList(){

    // Condition to check if listHeadAddress is pointing to null, if true means list is empty
    if(listHeadAddress == nullptr){
        cout << "List is Empty" << endl;
        return;
    }

    // Pointer to store address of the node that is to be deleted
    Node* toBeDeleted = listHeadAddress;
    // Pointer to traverse the list since addresses would be lost if nodes are deleted and no other pointer is there to store the next addresses
    Node* nextNode = listHeadAddress->next;

    // Looping till next node is null
    while(nextNode != nullptr){

        // cout << "listHeadAddress: " << listHeadAddress << endl;
        // cout << "toBeDeleted: " << toBeDeleted << endl;
        // cout << "Value: " << toBeDeleted->value << endl;
        
        // Making the subsequent next node the head node
        listHeadAddress = nextNode;
        // Deallocating memory/Deleting the previous head node
        delete toBeDeleted;
        // Pointing to(storing address of) the next node which is to be deleted
        toBeDeleted = nextNode;
        // Store the address of the next node / point to the next node 
        nextNode = nextNode->next;
    }

    // cout << "listHeadAddress: " << listHeadAddress << endl;
    // cout << "toBeDeleted: " << toBeDeleted << endl;
    // cout << "Value: " << toBeDeleted->value << endl;


    // Deleting the last node of the list
    delete toBeDeleted;
    // Making the listHeadAddress and toBeDeleted pointers point to null
    listHeadAddress = toBeDeleted = nullptr;
    

    // cout << "listHeadAddress: " << listHeadAddress << endl;
    // cout << "toBeDeleted: " << toBeDeleted << endl;

    cout << "List Deleted Successfully" << endl;
}

void deleteListRecursive(Node* listTraverser){

    // Counter to count the number of function calls that are pushed/popped on the call stack
    static int counter = 0;

    // Checking if list traverser is pointing to null(i.e storing null as address). If true return and don't continue further
    if(listTraverser == nullptr){
        return;
    }

    counter++;


    // cout << "ListTraverser: " << listTraverser << endl;
    // cout << "Value: " << listTraverser->value << endl;


    // Recursise call to the function itself, passing the next node as an argument
    deleteListRecursive(listTraverser->next);

    counter--;

    
    // cout << "ListTraverser: " << listTraverser << endl;
    // cout << "Value: " << listTraverser->value << endl;


    // Deleting the node, starting from the end of list
    delete listTraverser;
    // Making each node and the head pointer point to null
    listTraverser = nullptr;
    listHeadAddress = nullptr;

    // Condition to print the concluding statement
    if(counter == 0){
        cout << "List Deleted Successfully" << endl;
    }


    // cout << "ListTraverser: " << listTraverser << endl;
}

void reverseList(){

    // Storing address of the first node in current
    Node* current = listHeadAddress;
    // Previous assigned null as we will later make the current->next = null
    Node* previous = nullptr;
    // For storing the next node
    Node* nextNode;

    // Looping till current points to null
    while(current != nullptr){

        // Assigning nextNode the address of whatever is stored in the next variable of current node
        nextNode = current->next;
        // Changing the link between nodes to point to(store address of) the previous node
        current->next = previous;
        // Reassigning the pointers for each to point to(store address of) the next node respectively
        previous = current;
        current = nextNode;
    }

    // Changing the listHeadAddress to point to(store address of) the previously last node thereby making it the new first/head node
    listHeadAddress = previous;
}

void reverseListRecursive(Node* listTraverser){

    // Condition to check if the node's next points to null or not
    if(listTraverser->next == nullptr){
        // Since condition is true, listTraverser point to(stores address of) the current last node which is now made first/head node
        listHeadAddress = listTraverser;
        return;
    }

    // Recursive call to the function itself, passing the address of the next node as arguement
    reverseListRecursive(listTraverser->next);

    // Making a pointer to store address of the next node to the node in the parameter
    Node* previous = listTraverser->next;
    // Pointing(storing address of) the node in the parameter as the next node of the node whose address is in previous
    // therefore making it the previous node. Simply a reverse link is being made 
    previous->next = listTraverser;
    // Pointing the next of the node in the parameter to null so that eventually the last node points to null
    listTraverser->next = nullptr;
}

void searchValue(int val){

    // Making a traverser pointer so that we do not lose the address of the first node stored in listHeadAddress
    Node* listTraverser = listHeadAddress;
    // Boolean to check if we found the value or not, initially false
    bool found = false;
    // Position of the nodes, intially 1
    int nodeNum = 1;

    // Looping till list reaches its end/points to null
    while (listTraverser != nullptr)
    {
        // Condition to check if the value at the node currently pointed to(address stored of) is the same as value passed
        if(listTraverser->value == val){
            found = true;
            break;
        }
        else{
            listTraverser = listTraverser->next;
            nodeNum++;
        }
    }

    // Condition to display in case value if found or not
    if(found){
        cout << val << " is located at Node number " << nodeNum << endl;
    }
    else
        cout << val << " is not located at any Node" << endl;
}

int main()
{

    // Allocating memory for a new node, around 4 bytes for pointer variable and 4 bytes for integer variable
    Node* first = new Node(); 
    first->value = 1;

    // Storing address of the first node in the head, so that headptr can point to the first node
    listHeadAddress = first;  
    first->next = nullptr;
    
    // Inserting a node at the End of the list


    // Node* second = new Node();
    // second->value = 2;

    // first->next = second;
    // second->next = nullptr;


    // Inserting a node at the Front of the list

    // Create a new node and assign it a value


    // Node* newFirst = new Node();
    // newFirst->value = 3;
    // // Linking the new node with the old first node 
    // newFirst->next = listHeadAddress;
    // // Making head point to it
    // listHeadAddress = newFirst;


    // Inserting a node in the Middle of the list
    
    addNodeAtEnd(2);
    addNodeAtEnd(3);
    addNodeAtEnd(4);

    // addNodeAtPosition(5, 1);
    // addNodeAtPosition(6, 1);
    // addNodeAtPosition(6, 5);
    // addNodeAtPosition(8, 6);

    // deleteNodeAtFront();
    // searchValue(3);
    // deleteNodeAtPosition(3);
    // reverseList();
    // reverseListRecursive(listHeadAddress);
    // deleteList();
    deleteListRecursive(listHeadAddress);
    

    // cout << "List Head Address: " << listHeadAddress << endl;
    printList();
    // printListRecursive(listHeadAddress);
    // printListReverseRecursive(listHeadAddress);

    // cout << first << endl;
    // cout << newFirst << endl;
    // cout << newFirst->next << endl;
    // cout << "Address of First Node After: " << first << endl;
    // cout << newFirst->value << endl;
    // cout << first->value << endl;
    
    return 0;
}