#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *getNode() {
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->next = NULL;
    return q;
}

void display() {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    struct node *q = start;
    do {
        cout << q->data << " ";
        q = q->next;
    } while (q != start);
    cout << endl;
}

struct node *InsBeg(struct node *start, int y) {
    struct node *p = getNode();
    p->data = y;
    if (start == NULL) {
        p->next = p;
        start = p;
        return start;
    }
    struct node *temp = start;
    while (temp->next != start) temp = temp->next;
    p->next = start;
    temp->next = p;
    start = p;
    return start;
}

struct node *Insend(struct node *start, int y) {
    struct node *p = getNode();
    p->data = y;
    if (start == NULL) {
        p->next = p;
        start = p;
        return start;
    }
    struct node *temp = start;
    while (temp->next != start) temp = temp->next;
    temp->next = p;
    p->next = start;
    return start;
}

struct node *InsAfter(struct node *start, int after, int y) {
    if (start == NULL) return start;
    struct node *temp = start;
    do {
        if (temp->data == after) {
            struct node *p = getNode();
            p->data = y;
            p->next = temp->next;
            temp->next = p;
            return start;
        }
        temp = temp->next;
    } while (temp != start);
    cout << "Node not found" << endl;
    return start;
}

struct node *DeleteBeg(struct node *start) {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return start;
    }
    if (start->next == start) {
        free(start);
        return NULL;
    }
    struct node *temp = start;
    struct node *last = start;
    while (last->next != start) last = last->next;
    start = start->next;
    last->next = start;
    free(temp);
    return start;
}

struct node *DeleteEnd(struct node *start) {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return start;
    }
    if (start->next == start) {
        free(start);
        return NULL;
    }
    struct node *temp = start;
    struct node *prev = NULL;
    while (temp->next != start) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = start;
    free(temp);
    return start;
}

int main() {
    int choice;
    do {
        cout << "Enter your choice:" << endl;
        cout << "1.Display Linked List" << endl;
        cout << "2.Insert at Beginning" << endl;
        cout << "3.Insert at end" << endl;
        cout << "4.Insert after a node" << endl;
        cout << "5.Delete a element from the beginning" << endl;
        cout << "6.Delete a element frorm the end" << endl;
        cout << "7.Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            display();
            break;
        }
        case 2: {
            int y;
            cout << "Enter the element to be inserted at beginning" << endl;
            cin >> y;
            start = InsBeg(start, y);
            break;
        }
        case 3: {
            int y;
            cout << "Enter the element to be inserted at end" << endl;
            cin >> y;
            start = Insend(start, y);
            break;
        }
        case 4: {
            int y, after;
            cout << "Enter the element to be inserted after a node" << endl;
            cin >> y;
            cout << "Enter the node after which you want to insert the element" << endl;
            cin >> after;
            start = InsAfter(start, after, y);
            break;
        }
        case 5: {
            start = DeleteBeg(start);
            break;
        }
        case 6: {
            start = DeleteEnd(start);
            break;
        }
        case 7: {
            cout << "Exiting the program" << endl;
            break;
        }
        default: {
            cout << "Uh oh! Wrong choice, try again" << endl;
            break;
        }
        }
    } while (choice != 7);
    return 0;
}
