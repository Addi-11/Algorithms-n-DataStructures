//LDR
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* lchild;
    struct Node* rchild;
};


struct Node* createNode(int x){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* parent, int x){
    if(parent == NULL){
       parent =  createNode(x);
       //printf("\nParent while insert: %u",parent);
       printf("%d ",parent->data);
    } else if(x <= parent->data){
        parent->lchild = insertNode(parent->lchild,x);
    }else{
        parent ->rchild = insertNode(parent->rchild,x);
    }
    return parent;
}

void traversal(struct Node* root){
    
    if(root == NULL)return;
    //printf("\nRoot in traversal %u",root);

    struct Node* ltemp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* rtemp = (struct Node*)malloc(sizeof(struct Node));

    ltemp = root->lchild;
    rtemp = root->rchild;

    
    if(root != NULL){
        printf("%d ",root->data);
    }
    if(rtemp != NULL){
        traversal(rtemp);
    }
    if(ltemp != NULL){
        traversal(ltemp);
    }
    return;
}


int main(){

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root = NULL;
    root = insertNode(root,15);
    root =  insertNode(root,9);
    root =  insertNode(root,12);
    root =  insertNode(root,21);
    root =  insertNode(root,17);
    root =  insertNode(root,1);
    root =  insertNode(root,20);
    root =  insertNode(root,16);
    root =  insertNode(root,23);  
    printf("\n");
    traversal(root);
    return 0;
}