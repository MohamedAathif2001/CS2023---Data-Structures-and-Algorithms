#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* head;
    int size;
    int capacity;

public:
    Stack(int s)
    {
        size = 0;
        capacity = s;
        head = nullptr;
    }

    ~Stack()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    bool isFull()
    {
        return (size == capacity);
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Error : Stack Overflow" << endl;
        }
        else
        {
            Node* new_node = new Node(value);
            new_node->next = head;
            head = new_node;
            size++;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Error : Stack Underflow" << endl;
            return -1;
        }
        else
        {
            int value = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return value;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            Node* current = head;
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    int stackTop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        else
        {
            return head->data;
        }
    }
};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack s(size);

    srand(time(0));

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size ; i++)
    {
        int n = rand() % 100;
        s.push(n);
    }

    s.display();

    for (int i = 0; i < size - 5; i++)
    {
        s.pop();
    }

    s.display();

    for (int i = 0; i < size - 10; i++)
    {
        int n = rand() % 100;
        s.push(n);
    }

    s.display();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Runtime of stack using linked list : " << duration.count() / 1000.0 << "miliseconds" << endl;

    return 0;
}
