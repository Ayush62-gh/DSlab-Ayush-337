// stack operations
#include <iostream>
#define MAX 100
using namespace std;
void display();
int n;
int top=-1;
int x;
void push(int stack[], int n, int x)
{
    if (top == n - 1)
        cout << "overflow" << endl;
    else
        stack[++top] = x;
}
int pop(int stack[], int n)
{
    if (top == -1)
    {
        cout << "underflow" << endl;
        return -1;
    }
    else
    {
        x = stack[top];
        top--;
        return x;
    }
    
}

void display(int stack[], int n)
{
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
}
int main()
{
    int choice;
    cout << "enter the size of stack" << endl;
    cin >> n;
    int stack[n];
    do
    {
        cout << "Enter 1.Push\n2.Pop\n3.Display" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Element to be inserted" << endl;
            cin >> x;
            push(stack, n, x);
            break;
        case 2:
            cout << endl<< "popped element" << pop(stack, n);
            break;
        case 3:
            display(stack, n);
            break;

        default:
            cout << "you have entered wrong choice, try again" << endl;
        }
    }while(choice!=4);
}