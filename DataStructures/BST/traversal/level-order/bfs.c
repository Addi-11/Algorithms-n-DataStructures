#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//structure for bst
struct Node{
    int data;
    struct Node* rchild;
    struct Node* lchild;
};

struct Node* root;

//structure for queue
struct Qnode{
    struct Node* item;
    struct Qnode* nxt;
};

struct Qnode* front = NULL;
struct Qnode* rear = NULL;

//Code for entering data in a bst

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->rchild = NULL;
    newNode->lchild = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root,int x){
    if(root == NULL){
        root = createNode(x);
        //printf("\nValue of root: %u",root);
        printf("%d ",root->data);
    } else
    if(x <= root->data){
        root->lchild = insertNode(root->lchild,x);
    } else{
        root->rchild =  insertNode(root->rchild,x);
    }
    return root;
}

void createTree(){
    root = NULL;
    root = insertNode(root,15);
    root = insertNode(root,9);
    root = insertNode(root,12);
    root = insertNode(root,21);
    root = insertNode(root,17);
    root = insertNode(root,1);
    root = insertNode(root,20);
    root = insertNode(root,16);
    root = insertNode(root,23);
}

//tree traversal-level order using queues

void Enqueue(struct Node* root){

    struct Qnode *temp = (struct Qnode*)malloc(sizeof(struct Qnode));

    temp->item = root;
    temp->nxt = NULL;

    //if empty
    if(front == NULL && rear == NULL){
        front = temp;
    } else{
        rear->nxt = temp;
    }
    rear = temp;
    return;
}

void Dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
    } else if(front == rear){
        front = NULL;
        rear = NULL;
    } else{
        front = front->nxt;
    }
}

bool IsEmpty(){
    if(front == NULL){
        printf("Queue is empty\n");
        return true;
    }
    else{
        printf("Queue is not empty\n");
        return false;
    }
}


void createQueueItem(struct Node* root){
    //empty queue 
    if(front == NULL){
        Enqueue(root);
    }
    if(root != NULL){
        //Enqueue(root);
        printf("%d ",root->data);
        if(root->lchild != NULL)
            Enqueue(root->lchild);
        if(root->rchild != NULL)
            Enqueue(root->rchild);
        Dequeue();
    }
}

void traverseTree(struct Node* root){
    
    if(root == NULL)return;

    Enqueue(root);
    //bool s = IsEmpty();
    while(front != NULL){
        //printf("in while");
        struct Qnode* temp = front;
      
        printf("%d ",temp->item->data);
        if(temp->item->lchild != NULL)
            Enqueue(temp->item->lchild);
        if(temp->item->rchild != NULL)
            Enqueue(temp->item->rchild);
         Dequeue();
    }

    //createQueueItem(root);
    //if(root->lchild != NULL){
    //    return traverseTree(root->lchild); 
    //}
    //if(root->rchild != NULL){
    //    return traverseTree(root->rchild);
    //}
}

int main(){
    createTree();
    printf("\n");
    traverseTree(root);
    return 0;
}