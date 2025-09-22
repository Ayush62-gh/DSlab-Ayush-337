#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char value) {
        data = value;
        next = nullptr;
    }
};

void traverse(Node* A) {
    Node* PTR = A;
    int count = 0;
    while (PTR != nullptr) {
        cout << PTR->data << " ";
        PTR = PTR->next;
        count = count + 1;
    }
}

int main() {
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');

    A->next = B;
    B->next = C;
    C->next = D;
    D->next = nullptr;

    traverse(A);

}
