#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

class Stack
{
    
private:
    int* stack;
    int top;
    int size;
    
public:
    Stack(int s)
    {
        size = s;
        stack = new int[size];
        top = -1; // top is set to -1 to indicate an empty stack
    }
    
    ~Stack()
    {
        delete[] stack;
    }
    
    bool isEmpty()
    {
        return(top == -1);
    }
    
    bool isFull()
    {
        return(top == size-1);
    }
    
    void push(int value)
    {
        if ( isFull() )
        {
            cout<<"Error : Stack Overflow"<<endl;
        }
        else 
        {
            top++;
            stack[top] = value;
        }
    }
    
    int pop()
    {
        if ( isEmpty() )
        {
            cout<<"Error : Stack Underflow"<<endl;
            return -1;
        }
        else
        {
            int value = stack[top];
            top--;
            return value;
        }
    }
    
    void display()
    {
        if ( isEmpty() )
        {
            cout<<"Stack is Empty"<<endl;
        }
        else
        {
            for (int i=0;i<=top;i++)
                {
                    cout<<stack[i]<<" ";
                }
                cout<<endl;
        }   
    }
    
    int stackTop()
    {
        if ( isEmpty() )
        {
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        else
        {
            return stack[top];
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

    for (int i=0;i<size;i++)
    {
        int n = rand()%100;
        s.push(n);
    }
    
    s.display();
    
    for (int i=0;i<size -5 ;i++)
    {
        s.pop();
    }
    
    s.display();
    
    for (int i=0;i<size - 10 ;i++)
    {
        int n = rand()%100;
        s.push(n);
    }
    
    s.display();
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout<<"Runtime of stack using array : "<<duration.count()/1000.0<<"miliseconds"<<endl;
    
    return 0;
}
