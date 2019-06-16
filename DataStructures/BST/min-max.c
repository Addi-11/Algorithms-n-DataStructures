#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

struct Node* createNode(int x){
    struct Node* newLeaf = (struct Node*)malloc(sizeof(struct Node)); 

    newLeaf->data = x;
    newLeaf->lchild = NULL;
    newLeaf->rchild = NULL;
    return newLeaf;
}

struct Node* insertNode(struct Node* root, int x){
    if(root == NULL){
        root = createNode(x);
    }else if(x <= root->data){
        root->lchild = insertNode(root->lchild,x);
    }else {
        root->rchild = insertNode(root->rchild,x);
    }
    return root;
}

int findMax(struct Node* root){
    //move down the right child
    if(root == NULL){
        printf("Tree is empty\n");
        return -1;
    }
    while(root->rchild != NULL){
        root = root->rchild;
    }
    return root->data;
}

int findMin(struct Node* root){
   //move down the leftchild
   if(root == NULL){
       printf("tree is Empty");
       return -1;
   }
   while(root->lchild != NULL){
       root = root->lchild;
   }
   return root->data;
}

int main(){
    struct Node* root = NULL;
    int a = findMax(root);
    root = insertNode(root,15);	
	root = insertNode(root,10);	
	root = insertNode(root,20);
	root = insertNode(root,25);
	root = insertNode(root,8);
	root = insertNode(root,12);
	root = insertNode(root,56);

    int max = findMax(root);
    int min = findMin(root);
    printf("%d is the maximum element of the tree\n",max);
    printf("%d is the minimum element of the tree\n",min);
    return 0;
}