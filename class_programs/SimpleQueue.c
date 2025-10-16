#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1;

void enqueue(int queue[], int n, int x){
    if (front == 0 && rear == n-1){
        printf("Overflow\n");
    }
    if(front == -1 && rear == -1){
        front=rear=0;
        queue[rear]=x;
    }
    else if(rear == n-1 && front != 0){
        rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }

}

void dequeue(int queue[], int n){
    if(front == -1 && rear == -1){
        printf("Underflow\n");
    }
    else if(front == rear){
        printf("Deleted element is %d\n", queue[front]);
        front=rear=-1;
    }
    else if(front == n-1){
        printf("Deleted element is %d\n", queue[front]);
        front=0;
    }
    else{
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}
void display(int queue[], int n){

}
int main(){
    int n, choice,x;
    printf("Enter the size of the queue\n");
    scanf("%d", &n);
}