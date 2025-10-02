//primitve operations in stack
# include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* top = NULL;

void push(int value){
    Node* newnode = new Node();
    if(!newnode){
        cout<<"Stack overflow"<<endl;
        return;
    }
    newnode->data=value;
    newnode->next=top;
    top=newnode;
    cout<<value<<"pushed to stack"<<endl;
}

void pop(){
    if(top==NULL){
        cout<<"Stack underflow"<<endl;
        return;
    }
    Node* temp=top;
    cout<<"Popped element: "<<temp->data;
    top=top->next;
    delete temp;
}

void peek(){
    if(top==NULL){
        cout<<"Stack is empty\n"<<endl;
        return;
    }
    cout<<"Top element is:"<<endl;

}
void display(){
    if(top==NULL){
        cout<<"Stack is empty\n"<<endl;
        return;
    }
    Node* temp = top;
    cout<<"Stack elements:"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<"\n";

}

int main(){
    int ch,value;
    while(true){
    cout<<"- - - - Stack Menu - - - - "<<endl;
    cout<<"1.Press 1 to push the element into the stack."<<endl;
    cout<<"2.Press 2 to delete element from the stack."<<endl;
    cout<<"3.Press 3 to see the top element of the stack."<<endl;
    cout<<"4.Press 4 to display the elements of the stack."<<endl;
    }
    switch(ch){
        case 1:
        cout<<"Enter the elemnt to be inserted in the stack:"<<endl;
        cin >> value;
        push(value);
        case 2:
        cout<<"Deleting the top element from the stack."<<endl;
        pop();
        case 3:
        cout<<"Seeing the top element of the stack."<<endl;
        peek();
        case 4:
        cout<<"Displaying the elements of the stack."<<endl;
        display();

    }
    



}
