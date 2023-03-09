

/*
 * Author: Mujtaba SP22-BSE-036
 * Date: March 8, 2023
 * 
 * Integer Linked List implementation in C++
 * 
 */

#include <iostream>

using namespace std;

class IntList {
public:
    typedef struct Node {
        int data;
        Node* next;
    } Node;

    Node* head = NULL;
    Node* tail = NULL;

    // Add a node to the end of the list
    void insertLast(int data) {
        Node* node = new Node;
        node->data = data;
        node->next = NULL;
        
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // Add a node to the beginning of the list

    void insertFirst(int data) {
        Node* node = new Node;
        node->data = data;
        node->next = head;
        head = node;
    }

    // Search for a value in the list
    Node* search(int value){
        Node* node = head;
        while (node != NULL) {
            if (node->data == value) {
                return node;
            }
            node = node->next;
        }
        return NULL;
    }

    // Insert after a specific value
    void insertAfterASpecificValue(int value, int data) {
        Node* node = search(value);
        if (node != NULL) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = node->next;
            node->next = newNode;
        }
    }

    // Deleting first node
    void deleteFirst() {
        Node* node = head;
        head = head->next;
        delete node;
    }

    // Deleting last node
    void deleteLast() {
        Node* node = head;
        while (node->next != tail) {
            node = node->next;
        }
        delete tail;
        tail = node;
        tail->next = NULL;
    }

    // Deleting node with specific data value
    void deleteNode(int value) {
        Node* node = head;
        Node* prev = NULL;
        while (node != NULL) {
            if (node->data == value) {
                if (node == head) {
                    deleteFirst();
                } else if (node == tail) {
                    deleteLast();
                } else {
                    prev->next = node->next;
                    delete node;
                }
                return;
            }
            prev = node;
            node = node->next;
        }
    }

    // Deleting whole list
    void deleteList() {
        Node* node = head;
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    // Printing linked list in reverse order using loop
    void printReversUsingLoops() {
        Node* node = head;
        int count = 0;
        while (node != NULL) {
            count++;
            node = node->next;
        }
        int* arr = new int[count];
        node = head;
        for (int i = 0; i < count; i++) {
            arr[i] = node->data;
            node = node->next;
        }
        for (int i = count - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Printing linked list in reverse order using recursion
    void printReverseUsingRecursion(Node* node) {
        if (node == NULL) { return; }
        printReverseUsingRecursion(node->next);
        cout << node->data << " ";
    }

    // Merge 2 lists into one without recursion
    Node* mergeLists(Node* list1, Node* list2){
        Node* node = list1;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = list2;
        return list1;
    }

    // Return occurence of a value in the list
    int countOccurence(int value) {
        Node* node = head;
        int count = 0;
        while (node != NULL) {
            if (node->data == value) {
                count++;
            }
            node = node->next;
        }
        return count;
    }
};


int main(){
    IntList list;
    list.insertLast(1);
    list.insertLast(1);
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    cout << "List: " << endl;
    list.printReversUsingLoops();
    cout << "Occurance of 1: " << list.countOccurence(1) << endl;

    return 0;
}

