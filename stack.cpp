
#include <iostream>
#include <string>

class ArrayStack {
private:
    int currentIndex;
    int size;
    int* values;

public:
    ArrayStack(int size) {
        this->size = size;
        this->currentIndex = -1;
        this->values = new int[size];
    }

    void push(int value) {
        if (this->currentIndex == this->size - 1) {
            std::cout << "Stack is full" << std::endl;
            return;
        }

        this->values[++this->currentIndex] = value;
    }

    void pushBulk(std::string value) {
        for (int i = 0; i < value.length(); i++) {
            this->push(value[i]);
        }
    }

    int pop() {
        if (this->currentIndex == -1) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }

        return this->values[this->currentIndex--];
    }

    int peek() {
        if (this->currentIndex == -1) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }

        return this->values[this->currentIndex];
    }

    bool isEmpty() {
        return this->currentIndex == -1;
    }

    void print() {
        if (this->currentIndex == -1) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        for (int i = 0; i <= this->currentIndex; i++) {
            std::cout << this->values[i] << " ";
        }

        std::cout << std::endl;
    }
};

class LinkedStack {
private:
    struct Node {
        int value;
        Node* above;
    };

    Node* base;
    Node* top;

public:
    LinkedStack() {
        this->base = nullptr;
        this->top = nullptr;
    }

    void push(int value) {
        Node* node = new Node();
        node->value = value;
        node->above = nullptr;

        if (this->base == nullptr) {
            this->base = node;
            this->top = node;
        } else {
            this->top->above = node;
            this->top = node;
        }
    }

    int pop() {
        if (this->base == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }

        int value = this->top->value;

        if (this->base == this->top) {
            this->base = nullptr;
            this->top = nullptr;
        } else {
            Node* node = this->base;

            while (node->above != this->top) {
                node = node->above;
            }

            node->above = nullptr;
            this->top = node;
        }

        return value;
    }

    int peek() {
        if (this->base == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }

        return this->top->value;
    }

    bool isEmpty() {
        return this->base == nullptr;
    }

    void print() {
        if (this->base == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        Node* node = this->base;

        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->above;
        }

        std::cout << std::endl;
    }
};

bool isStringParenthesisBalanced(std::string expression){
    ArrayStack* myStack = new ArrayStack(expression.length());
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            myStack->push(expression[i]);
        }
        if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            myStack->pop();
        }
        if(myStack->isEmpty()) {
            return false;
        }
    }
    return true;
}

// graded 1
bool isStringParenthesisBalancedByPriority(std::string expression){
    ArrayStack* myStack = new ArrayStack(expression.length());
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            myStack->push(expression[i]);
        }
        if(expression[i] == ')') {
            if(myStack->pop() != '(') {
                return false;
            }
        }
        if(expression[i] == '}') {
            if(myStack->pop() != '{') {
                return false;
            }
        }
        if(expression[i] == ']') {
            if(myStack->pop() != '[') {
                return false;
            }
        }
    }
    return true;
}

// graded 2
// implement infix to postfix through stack
void infixToPostfix(std::string expr){
    LinkedStack* myStack = new LinkedStack();
    for(int i = 0; i < expr.length(); i++) {
        if(expr[i] == '(') {
            myStack->push(expr[i]);
        }
        if(expr[i] == ')') {
            while(myStack->peek() != '(') {
                std::cout << myStack->pop();
            }
            myStack->pop();
        }
        if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            myStack->push(expr[i]);
        }
        if(expr[i] >= 'a' && expr[i] <= 'z' || expr[i] >= 'A' && expr[i] <= 'Z' || expr[i] >= '0' && expr[i] <= '9') {
            std::cout << expr[i];
        }
    }
    myStack->print();
}

void evaluateExpression(std::string expr){
    LinkedStack* myStack = new LinkedStack();
    for(int i = 0; i < expr.length(); i++) {
        if(expr[i] >= '0' && expr[i] <= '9') {
            myStack->push(expr[i] - '0');
        }
        if(expr[i] == '+') {
            int a = myStack->pop();
            int b = myStack->pop();
            myStack->push(a + b);
        }
        if(expr[i] == '-') {
            int a = myStack->pop();
            int b = myStack->pop();
            myStack->push(a - b);
        }
        if(expr[i] == '*') {
            int a = myStack->pop();
            int b = myStack->pop();
            myStack->push(a * b);
        }
        if(expr[i] == '/') {
            int a = myStack->pop();
            int b = myStack->pop();
            myStack->push(a / b);
        }
    }
    std::cout << myStack->pop();
    myStack->print();
}


int main() {
    ArrayStack* arrayStack = new ArrayStack(5);

    arrayStack->push(1);
    arrayStack->push(2);
    arrayStack->push(3);

    arrayStack->print();

    std::cout << arrayStack->pop() << std::endl;
    std::cout << arrayStack->pop() << std::endl;

    LinkedStack* linkedStack = new LinkedStack();

    linkedStack->push(1);
    linkedStack->push(2);
    linkedStack->push(3);

    linkedStack->print();

    std::cout << linkedStack->pop() << std::endl;
    std::cout << linkedStack->pop() << std::endl;


    ArrayStack* iLoveCode = new ArrayStack(16);
    iLoveCode->pushBulk({'I', ' ', 'L', 'O', 'V', 'E', ' ', 'C', 'O', 'D', 'E'});
    for(int i = 0; i < 16; i++) {
        std::cout << (char)iLoveCode->pop();
    }


    infixToPostfix("a+b");

    evaluateExpression("2+2");

    return 0;
}