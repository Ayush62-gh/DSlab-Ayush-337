#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

Node* getNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    Node* newNode = getNode(value);
    if (head == NULL) head = newNode;
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << "Inserted at beginning.\n";
}

void insertAtEnd(int value) {
    Node* newNode = getNode(value);
    if (head == NULL) head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Inserted at end.\n";
}

void insertAfter(int key, int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != key) temp = temp->next;
    if (temp == NULL) cout << "Key not found.\n";
    else {
        Node* newNode = getNode(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Inserted after " << key << ".\n";
    }
}

void deleteAtBeginning() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
    cout << "Deleted from beginning.\n";
}

void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        delete temp;
        cout << "Deleted last element.\n";
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
    cout << "Deleted from end.\n";
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Forward: ";
    while (temp->next != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
    cout << "Backward: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    int choice, value, key;
    while (true) {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Delete at Beginning\n5. Delete at End\n6. Display\n7. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter key and value: ";
                cin >> key >> value;
                insertAfter(key, value);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                display();
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}