#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = NULL;
        size = 0;
    }

    bool isEmpty() {
        return top == NULL;
    }

    bool isFull() {
        return size == 10;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Error: Stack Overflow" << endl;
        }
        else {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            size++;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow" << endl;
            return -1;
        }
        else {
            int data = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
            return data;
        }
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Error: Stack is Empty" << endl;
            return -1;
        }
        else {
            return top->data;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        }
        else {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack s;

    srand(time(0));

    s.push(10);
    s.push(3);

    s.display();

    for (int i = 0; i < 3; i++) {
        s.pop();
    }

    for (int i = 0; i < 12; i++) {
        int n = rand() % 100;
        s.push(n);
    }

    s.display();

    for (int i = 0; i < 5; i++) {
        s.pop();
    }

    s.display();

    for (int i = 0; i < 4; i++) {
        int n = rand() % 100;
        s.push(n);
    }

    s.display();

    return 0;
}
