#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void traverse(Node* head) {
    Node* PTR = head;
    int COUNT = 0;
    while (PTR) {
        cout << PTR->data << " -> ";
        PTR = PTR->next;
        COUNT++;
    }
    cout << "NULL" << endl;
    cout << "Total nodes = " << COUNT << endl;
}

int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "1.Insert at End\n";
        cout << "2.Traverse List\n";
        cout << "3.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(head, value);
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}

