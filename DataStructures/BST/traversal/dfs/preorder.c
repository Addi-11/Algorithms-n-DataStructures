//DLR
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

struct Node* createNode(int x){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->data = x;
    return newNode;
}

struct Node* insertNode(struct Node* root,int x){
    if(root == NULL){
        root = createNode(x);
        //printf("\nRoot: %u ",root);
        printf("%d ",root->data);
    } else if(x <= root->data){
        root->lchild =  insertNode(root->lchild,x);
    }else{
        root->rchild =  insertNode(root->rchild,x);
    }
    return root;
}

void traversal(struct Node* root){
    
    struct Node* ltemp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* rtemp = (struct Node*)malloc(sizeof(struct Node));

    ltemp = root->lchild;
    rtemp = root->rchild;

    if(root == NULL)return;

    if(root != NULL){
        printf("%d ",root->data);
    }
    if(ltemp != NULL){
        //printf("%d ",ltemp->data);
         traversal(ltemp);
    } 
    if(rtemp != NULL){
        //printf("%d ",rtemp->data);
        traversal(rtemp);
    }
    return;
}

int main(){
    struct Node* root = NULL;
    root = insertNode(root,15);
    root = insertNode(root,9);
    root = insertNode(root,12);
    root = insertNode(root,21);
    root = insertNode(root,17);
    root = insertNode(root,1);
    root = insertNode(root,20);
    root = insertNode(root,16);
    root = insertNode(root,23);
    printf("\n");
    traversal(root);
    return 0;
}