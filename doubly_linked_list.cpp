
/*
 * Author: Mujtaba SP22-BSE-036
 * March 15, 2023
 * Lab 3 - Doubly Linked List
 */

#include <iostream>
#include <string>

#include "linked_list.cpp"

using namespace std;

class IntDoublyList {
public:
    typedef struct Node {
        int data;
        Node *next;
        Node *prev;
    } Node;

    Node *head = NULL;
    Node *tail = NULL;

    void display(){
        Node* tmp = head;
        for(; tmp != NULL; tmp = tmp->next){
            cout << tmp->data << " ";
        }
        cout << endl;
    }

    void insertEnd(int data){
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if(head == NULL){
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    int access(int index){
        int i = 0;
        for(Node* tmp = 0; tmp != NULL; tmp->next){
            if(i == index){
                return tmp->data;
            }
            i++;
        }
    }

    void insertStart(int data){
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertWhenReachedValue(int data, int value){
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
            if(tmp->data == value){
                newNode->next = tmp->next;
                newNode->prev = tmp;
                tmp->next = newNode;
                newNode->next->prev = newNode;
            }
        }
    }

    void deleteAtIndex(int index){
        int i = 0;
        for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
            if(i == index) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
                delete tmp;
                break;
            }
            i++;
        }
    }

    void deleteList(){
        for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
            delete tmp;
        }
    }


    // Graded
    void reverseList(){
        Node* tmp = head;
        head = tail;
        tail = tmp;
        for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
            Node* tmp2 = tmp->next;
            tmp->next = tmp->prev;
            tmp->prev = tmp2;
        }
    }

    // @b
    void swap2NodesAtGivenValues(int value1, int value2){
        Node* node1 = NULL;
        Node* node2 = NULL;
        for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
            if(tmp->data == value1){
                node1 = tmp;
            }
            if(tmp->data == value2){
                node2 = tmp;
            }
        }
        if(node1 != NULL && node2 != NULL){
            Node* tmp = node1->next;
            node1->next = node2->next;
            node2->next = tmp;
            tmp = node1->prev;
            node1->prev = node2->prev;
            node2->prev = tmp;
        }
    }
        IntDoublyList* fromSinglyList(IntList* which){
            IntDoublyList* result = new IntDoublyList;
            IntList::Node* tmp = which->head;
            for(int i = 0; i < which->length(); i++){
                result->insertEnd(tmp->data);
                tmp = tmp->next;
                if(tmp == NULL) break;
            }
            return result;
        }

};


int main(){
    IntDoublyList* doublyList = new IntDoublyList;
    doublyList->insertEnd(2);
    doublyList->insertEnd(4);
    doublyList->insertEnd(9);
    doublyList->insertEnd(7);
    doublyList->insertEnd(3);
    doublyList->display();
    doublyList->reverseList();
    doublyList->display();
    return 0;
}















