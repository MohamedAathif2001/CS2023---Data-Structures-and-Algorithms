#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

const int stackSize = 10; // initializing stack size

class Stack
{
    
private:
    int stack[stackSize];
    int top;
    
public:
    Stack()
    {
        top=0; // top is set as the index of next element to be added to the stCK
    }
    
    bool isEmpty()
    {
        return(top==0);
    }
    
    bool isFull()
    {
        return(top==stackSize);
    }
    
    void push(int value)
    {
        if ( isFull() )
        {
            cout<<"Error : Stack Overflow"<<endl;
        }
        else 
        {
            stack[top] = value;
            top++;
        }
    }
    
    int pop()
    {
        if ( isEmpty() )
        {
            cout<<"Error : Stack Underflow"<<endl;
        }
        else
        {
            top--;
            return (stack[top]);
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
            for (int i=0;i<top;i++)
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
            cout<<"Stack if Empty"<<endl;
            return 0;
        }
        else
        {
            return (stack[top-1]);
        }
    }
};

int main() 
{
    Stack s;
    
    srand(time(0));
    
    s.push(10); // pushing two elements to stack
    s.push(3);
    
    s.display();
    
    for(int i=0;i<3;i++) // popping 3 elements
    {
        s.pop();
    }

    for (int i=0;i<12;i++) // pushing more than stack size
    {
        int n = rand()%100;
        s.push(n);
    }
    
    s.display();
    
    for (int i=0;i<5;i++)
    {
        s.pop();
    }
    
    s.display();
    
    for (int i=0;i<4;i++)
    {
        int n = rand()%100;
        s.push(n);
    }
    
    return 0;
}