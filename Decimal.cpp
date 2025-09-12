#include <iostream>
# define MAX 100
using namespace std;
int stack[MAX];
int top = -1;
int num;
void push(){
    if(top>=MAX)
      cout<<"Stack Overflow"<<endl;
    else{
        int rem,power=1,decimal=0;
        while(num>0){
            rem=num%10;
            decimal=decimal+rem*power;
            power=power*2;
            stack[++top]=decimal;
            num=num/10;
        }
    }
}
void pop(){
    if(top<=-1)
      cout<<"Stack Underflow"<<endl;
    else
      cout<<"The popped element is "<<stack[top--]<<endl;
}
int main(){
    cout<<"Enter the size of stack"<<endl;
    cin>>num;
    push();
    pop();
}
