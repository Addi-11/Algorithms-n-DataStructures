#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* lchild;
    struct Node* rchild;
};



struct Node* createLeaf(int x){
    struct Node* newLeaf = (struct Node*)malloc(sizeof(struct  Node));

    newLeaf->data = x;
    newLeaf ->lchild = NULL;
    newLeaf ->rchild = NULL;

    return newLeaf;
}

struct Node* insertNode(struct Node* root, int x){
    if(root == NULL){
        root = createLeaf(x);
        printf("%d ",root->data);
    } else if(x <= root->data){
        root->lchild = insertNode(root->lchild,x);
    } else{
        root->rchild = insertNode(root->rchild,x);
    }
    return root;
}

bool search(struct Node* root,int x){
    if(root == NULL){
        return false;
    } else if(root->data == x){
        return true;
    } else if(x <= root->data){
        return search(root->lchild,x);
    } else{
        return search(root->rchild,x);
    }
}

int main(){
    struct Node* root = NULL;
    root = insertNode(root,15);	
	root = insertNode(root,10);	
	root = insertNode(root,20);
	root = insertNode(root,25);
	root = insertNode(root,8);
	root = insertNode(root,12);
    if(search(root,10)){
        printf("\nin the tree");
    } else{
        printf("\nnot in tree");
    }
    return 0;
}