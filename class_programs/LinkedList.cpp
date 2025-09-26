#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *getNode()
{
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->next = NULL;
    return q;
}

void display()
{
    struct node *p = start;
    if (p == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    struct node *q = p;
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}
struct node *InsBeg(struct node *start, int y)
{
    struct node *p = getNode();
    p->data = y;
    p->next = start;
    start = p;
    return start;
}
struct node *Insend(struct node *start, int y)
{
    struct node *p = getNode();
    p->data = y;
    if (start == NULL)
    {
        start = p;
        return start;
    }
    struct node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    return start;
}
struct node *InsAfter(struct node *start, int after, int y)
{
    struct node *temp = start;
    while (temp != NULL && temp->data != after)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Node not found" << endl;
        return start;
    }
    struct node *p = getNode();
    p->data = y;
    p->next = temp->next;
    temp->next = p;
    return start;
}

int main()
{
    int choice;
    do
    {
        cout << "Enter your choice:" << endl;
        cout << "1.Display Linked List" << endl;
        cout << "2.Insert at Beginning" << endl;
        cout << "3.Insert at end" << endl;
        cout << "4.Insert after a node" << endl;
        cout << "5.Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            display();
            break;
        }
        case 2:
        {
            int y;
            cout << "Enter the element to be inserted at beginning" << endl;
            cin >> y;
            start = InsBeg(start, y);
            break;
        }
        case 3:
        {
            int y;
            cout << "Enter the elemen to be inserted at end" << endl;
            cin >> y;
            start = Insend(start, y);
            break;
        }
        case 4:
        {
            int y, after;
            cout << "Enter the element to be inserted after a node" << endl;
            cin >> y;
            cout << "Enter the node after which you want to insert the element" << endl;
            cin >> after;
            start = InsAfter(start, after, y);
            break;
        }
        case 5:
        {
            cout << "Exiting the program" << endl;
            break;
        }
        default:
        {
            cout << "Uh oh! Wrong choice, try again" << endl;
            break;
        }
        }
    } while (choice != 5);
    return 0;
}
