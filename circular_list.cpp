
#include <iostream>
#include <string>

// Implementation of circular linked list

typedef struct Node {
    int data;
    struct Node *next;
} Node;

class CircularList {
    private:
        Node *head;
        Node *tail;
        int size;
    public:
        CircularList();
        ~CircularList();
        void addLast(int data);
        void addAtIndex(int index, int data);
        void removeAtIndex(int index);
        void print();
        // misc
        void removeNode(Node* node);
        // Graded
        void deleteAllNodesWithOddNumberValue();
        void deleteAllNodesWithEvenNumberValue();
        void josephusProblemImplementation(int k);
        void deleteAllNodesWithEvenIndex();
};

CircularList::CircularList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

CircularList::~CircularList() {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

void CircularList::addLast(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = head;
    size++;
}

void CircularList::addAtIndex(int index, int data) {
    if (index < 0 || index > size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (index == 0) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        tail->next = head;
    } else if (index == size) {
        addLast(data);
    } else {
        Node *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}


void CircularList::removeAtIndex(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    if (index == 0) {
        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    } else {
        Node *current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    size--;
}



void CircularList::print() {
    Node *current = head;
    for (int i = 0; i < size; i++) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// misc

void CircularList::removeNode(Node* node) {
    Node *current = head;
    while (current->next != node) {
        current = current->next;
    }
    current->next = current->next->next;
    delete node;
    size--;
}

// graded

void CircularList::deleteAllNodesWithOddNumberValue() {
    Node *current = head;
    while (current != tail) {
        if (current->data % 2 == 1) {
            Node *tmp_current_next = current->next;
            removeNode(current);
            current = tmp_current_next;
        } else {
            current = current->next;
        }
    }
    if (current->data % 2 == 1) {
        removeNode(current);
    }
}

void CircularList::deleteAllNodesWithEvenNumberValue() {
    Node *current = head;
    while (current != tail) {
        if (current->data % 2 == 0) {
            Node *tmp_current_next = current->next;
            removeNode(current);
            current = tmp_current_next;
        } else {
            current = current->next;
        }
    }
    if (current->data % 2 == 0) {
        removeNode(current);
    }
}

void CircularList::josephusProblemImplementation(int k) {
    Node *current = head;
    while (size > 1) {
        if(current == head && current->next == head) break;
        std::cout << "DEBUG: while (size > 1) {}"<<std::endl;
        for (int i = 0; i < k - 1; i++) {
            std::cout << "DEBUG: for (int i = 0; i < k - 1; i++) {}"<<std::endl;
            current = current->next;
        }
        Node* tmp_current_next = current->next;
        removeNode(current);
        current = tmp_current_next;
    }
}

void CircularList::deleteAllNodesWithEvenIndex() {
    Node *current = head;
    int index = 0;
    while (current != tail) {
        if (index % 2 == 0) {
            Node* tmp_current_next = current->next;
            removeNode(current);
            current = tmp_current_next;
        } else {
            current = current->next;
        }
        index++;
    }
    if (index % 2 == 0) {
        removeNode(current);
    }
}

void printMenu() {
    std::cout << "1. Add last" << std::endl;
    std::cout << "2. Add at index" << std::endl;
    std::cout << "3. Remove at index" << std::endl;
    std::cout << "4. Print" << std::endl;
    std::cout << "5. Delete all nodes with odd number value" << std::endl;
    std::cout << "6. Delete all nodes with even number value" << std::endl;
    std::cout << "7. Josephus problem implementation" << std::endl;
    std::cout << "8. Delete all nodes with even index" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int main(){
    CircularList* list = new CircularList();
    int choice;
    int data;
    int index;
    int k;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter data: ";
                std::cin >> data;
                list->addLast(data);
                break;
            case 2:
                std::cout << "Enter index: ";
                std::cin >> index;
                std::cout << "Enter data: ";
                std::cin >> data;
                list->addAtIndex(index, data);
                break;
            case 3:
                std::cout << "Enter index: ";
                std::cin >> index;
                list->removeAtIndex(index);
                break;
            case 4:
                list->print();
                break;
            case 5:
                list->deleteAllNodesWithOddNumberValue();
                break;
            case 6:
                list->deleteAllNodesWithEvenNumberValue();
                break;
            case 7:
                std::cout << "Enter k: ";
                std::cin >> k;
                list->josephusProblemImplementation(k);
                break;
            case 8:
                list->deleteAllNodesWithEvenIndex();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
    } while (choice != 0);
    return 0;
}