#include<stdio.h>
#include<stdlib.h>

int max = 20;

struct Node{
    char vertex;
    int attachedNode;
    struct Node *nxt;
};

int insert(struct Node vertexNode,char x){
    
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->vertex = x; 
    
    if(vertexNode.nxt != NULL){
       temp->nxt = vertexNode.nxt;
       printf("\nitem %c inserted in non empty list",temp->vertex);
    } else{
        printf("\nitem %c in empty list",temp->vertex);
       temp->nxt = NULL;
    }
    vertexNode.nxt = temp;

}

void printVertexList(struct Node *vertexNode){
    
    struct Node *temp;
    {
    struct Node *temp;
    temp = vertexNode;
    while(temp != NULL){
        printf(" %c",vertexNode->vertex);
        temp = temp->nxt;
    }
    }
}


void printGraph(struct Node vertexArr[], int vertices){

    
     for(int i = 0; i < vertices; i++){
         printf("\nVertex %c ",vertexArr[i].vertex);
         printf("\nNode attached to %c : ", vertexArr[i].vertex);
         for(int j = 1; j <= vertexArr[i].attachedNode; j++){
             printVertexList(&vertexArr[i]);
         }
     }
}

void create_graph()
{
    int vertices;
    struct Node tempNode;
    printf("\nEnter no.of vertices: ");
    scanf("%d",&vertices);

    struct Node vertexArr[vertices];

    for(int i = 0; i < vertices; i++){
       printf("\nEnter the vertex: ");
       scanf(" %c",&vertexArr[i].vertex);
       printf("\nNo.of nodes attached to %c vertex: ",vertexArr[i].vertex);
       scanf("%d",&vertexArr[i].attachedNode);
       for(int j = 0; j < vertexArr[i].attachedNode; j++ ){
           printf("\nEnter node attched to %c ",vertexArr[i].vertex);
           scanf(" %c",&tempNode.vertex);
           insert(vertexArr[i],tempNode.vertex);
       }
    }

    printGraph(vertexArr, vertices);
}



int main(){

    create_graph();
    return 0;
}