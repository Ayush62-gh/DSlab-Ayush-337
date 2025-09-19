#include <bits/stdc++.h>
using namespace std;

int top = -1;
char st[100];

void push(char x) {
    if (top == 99) {
        cout << "overflow" << endl;
    } else {
        st[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        cout << "underflow" << endl;
        return '\0';
    } else {
        return st[top--];
    }
}

int priority(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    string exp;
    cin >> exp;
    char ch;

    for (int i = 0; i < exp.length(); i++) {
        ch = exp[i];
        if (ch == '(') {
            push(ch);
        } 
        else if (isalnum(ch)) {
            cout << ch;
        } 
        else if (ch == ')') {
            char y;
            while ((y = pop()) != '(') {
                cout << y;
            }
        } 
        else {
            while (top != -1 && priority(st[top]) >= priority(ch)) {
                cout << pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        cout << pop();
    }
}