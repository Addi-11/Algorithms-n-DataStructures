#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define prime 101

struct List{
   int data;
   struct List *nxt;
};


//array storing pointer
struct List hashTable[100] = {0};

int hashfunct(int x){

   int index = prime%x;
   return index;
}

void insert(int x){

   int index = hashfunct(x);
   if(hashTable[index].data == 0){
      hashTable[index]. data = x;
      hashTable[index].nxt = NULL;
   } else {
      //link list created to avoid collisions
      struct List *temp = (struct List*)malloc(sizeof(struct List));
      temp->data = x;
      temp->nxt = hashTable[index].nxt;

      hashTable[index].nxt = temp;
   }
}

void search(int x){
   int index = hashfunct(x);
   if(hashTable[index].data == x )
      printf("\n%d is at index : %d in the hash table.", hashTable[index].data, index);
   else
      if(hashTable[index].nxt == NULL )
           printf("\n%d not in table", x);

      else
         {
            struct List *temp = (struct List*)malloc(sizeof(struct List));
            temp = hashTable[index].nxt;
            //traversing the link list
            do{
                  //printf("\n%d going into while",x);
               if (temp->data == x){
                  printf("\n%d is at index %d",x,index);
                  break;
               }
               temp = temp->nxt;
            
            } while(temp->nxt != NULL); 
         }
   
}

int main(){
   insert(9);
   insert(67);
   insert(32);
   insert(5);
   insert(56);
   insert(101);
   insert(27);
   insert(96);
   insert(11);
   insert(20);
   insert(99);
   insert(100);
   

   search(9);
   search(67);
   search(101);
   search(32);
   search(5);
   search(96);
   search(56);
   search(20);
   search(11);
   search(27);
   search(99);
   search(54);
   search(7);
   search(100);

   return 0;
}
