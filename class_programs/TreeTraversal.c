#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left,*right;
};

struct node* create() {
    int x;
    scanf("%d",&x);
    if(x==-1) return NULL;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    printf("Enter left child of %d (-1 for no child): ",x);
    newnode->left=create();
    printf("Enter right child of %d (-1 for no child): ",x);
    newnode->right=create();
    return newnode;
}

void preorder(struct node *root) {
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root) {
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node *root) {
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    struct node *root=NULL;
    int choice;
    printf("Enter root data (-1 for no node): ");
    root=create();
    while(1) {
        printf("\n1.Preorder\n2.Inorder\n3.Postorder\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        if(choice==1) {
            preorder(root);
        } else if(choice==2) {
            inorder(root);
        } else if(choice==3) {
            postorder(root);
        } else if(choice==4) {
            break;
        } else {
            printf("Invalid choice");
        }
    }
    return 0;
}