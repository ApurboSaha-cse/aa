#include<bits/stdc++.h>
using namespace std;

int maxSize = 200;
int top = -1;
int stk[200];

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top == maxSize - 1)
        return 1;
    else
        return 0;
}

int peek()
{
    return stk[top];
}

void push(int data)
{
    if(!isFull())
    {
        top++;
        stk[top]= data;
    }
    else
        cout << "Stack overflow" << endl;
}

int pop()
{
    int data;
    if(!isEmpty())
    {
        data = stk[top];
        top--;
        return data;

    }
    else    
        cout << "Stack underflow" << endl;
}


int main()
{
    int n;
    cout << "Enter the number of elements to insert: ";
    cin >> n;
    while(n--)
    {
        int a;
        cout << "enter the element: ";
        cin >> a;
        push(a);
    }
    
    cout << "The top element is : " << peek() << endl;
    cout << "The elements in the stack are : ";
    if( n == 0)
    cout << "NULL";

    while (!isEmpty())
    {
        int data = pop();
        cout << data << " ";
    }

    return 0;
}   