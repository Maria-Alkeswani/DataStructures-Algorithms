
//lab 1 , Exercise  1

// Jamal Alaskari & Maria Alkeswani


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
struct list //Linked List
{
    struct Node*head; //Pointer to top of stack
};
bool isEmpty(struct list *l)
{
    if(l->head== NULL)
        return true;
    else
        return false;
}


struct  Node *NewNode(int new_data)
{
struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));// Dynamic linked list
    new_node->data = new_data;
    new_node->prev = NULL;
	new_node->next = NULL;
return new_node;}

bool insert(struct list *L, Node * N){
// for adding a element for the list.
	struct Node* last = L->head;

	if (isEmpty(L)) {     // If linked list is empty or not
		L->head= N;
		return true;	}
		else {

	while (last->next != NULL)
		last = last->next;

	last->next = N;
	N->prev = last;
	return true;}

	return false;}

int  search(struct list *L, int k){   // For searching about element in the list
   int pos = 0;
   if(isEmpty(L)) {
      printf("Linked List not initialized");
      return NULL;
   }

  struct Node* current = L->head;
   while(current!=NULL) {
   	pos++;
      if(current->data == k) {

         return pos;
      }


         current = current->next;}


   return NULL ;}

   int  deleteNode(struct list *L,int k){
   int pos = 0 ;
    if (isEmpty(L)) {
    	printf("Linked List not initialized");
    	 return NULL;
	}else{


    //head
    if (k==1){

        L->head =  L->head->next;
        if (L->head != NULL)
            L->head->prev = NULL;
            }
    else{

     struct Node* current = L->head;
   while(current!=NULL) {
   	pos++;
      if(pos==k) {
      	if(current->next==NULL)
      	 current->prev->next = NULL;
      	 else{
      	 	 current->prev->next = current->next;
             current->next->prev = current->prev;
		   }

      	 return pos;
      }

         current = current->next;
        }
 }}
    return NULL; }


    int Max(struct list *L){ // node for the max key in the list
     int pos = 0;
     int posMax =NULL ;

   if(isEmpty(L)) {
      printf("Linked List not initialized");
      return NULL;
   }
  else{
    posMax =1 ;
   int max =L->head->data ;
  struct Node* current = L->head;
   while(current!=NULL) {
   	pos++;
      if(max <current->data) {
        max =current->data ;
        posMax = pos ;
      }

         current = current->next;}
}

   return posMax ;
    }
int Min(struct list *L){ // node for the min key in the list
     int pos = 0;
     int posMin =NULL ;
   if(isEmpty(L)) {
      printf("Linked List not initialized");
      return NULL;
   }
  else{
  	posMin =1 ;
     int min =L->head->data ;

  struct Node* current = L->head;
   while(current!=NULL) {

   	pos++;
      if(min >current->data) {
        min =current->data ;

        posMin =pos ;
      }
         current = current->next;}
   return posMin ;
    }}
int successor(struct list *L, Node * N){ // node for the next larger node in the list
     int pos = 0;
   if(isEmpty(L)) {
      printf("Linked List not initialized");
      return NULL;
   }   else{


  struct Node* current = L->head;
   while(current!=NULL) {
   	pos++;
      if(current->data == N->data) {
         if(pos != Max(L))
         return pos+1;
         else
         return NULL;
      }


         current = current->next;}


   return NULL ;
    }  }
int predecessor(struct list *L, Node * N){ // node for the next smaller  node in the list
         int pos = 0;
   if(isEmpty(L)) {
      printf("Linked List not initialized");
      return NULL;
   } else{


  struct Node* current = L->head;
   while(current!=NULL) {
   	pos++;
      if(current->data == N->data) {
         if(pos != Min(L))
         return pos-1;
         else
         return NULL;
      }
         current = current->next;}
   return NULL ;
    }    }

  void affiche(struct list *L){ // To show the list you already made

   if(isEmpty(L)) {
      printf("Linked List not initialized");
   }
   else{
   	printf("--------------------List--------------------\n");
   	 struct Node* current = L->head;
   while(current!=NULL) {
   	printf("%d \n",current->data) ;
         current = current->next;}
   }

}

int main()
{
	struct list *l= (struct list*)malloc(sizeof(struct list));
    l->head = NULL;
    int tst ,data;
    int a ;

    while(true){
    	printf("\n-------------MENU-------------------\n") ;
    	printf(" 1- insert to lindklist \n") ;
    	printf(" 2- delete to lindklist \n") ;
    	printf(" 3- search to lindklist \n") ;
    	printf(" 4- max to lindklist \n") ;
    	printf(" 5- min to lindklist\n") ;
    	printf(" 6- successor to lindklist\n") ;
    	printf(" 7- predecessor to lindklist\n") ;
    	printf(" 8- affiche lindklist \n ") ;
    	scanf("%d",&tst) ;
    	if(tst==1){
    	printf(" add new data  :") ;
		scanf("%d",&data) ;
    	 a =insert(l,NewNode(data)) ;
		 if(a==1)
		 printf("\n succes \n") ;
		}
		if(tst==2){
    	printf(" node delete  :") ;
		scanf("%d",&data) ;
		 if(deleteNode(l,data))
		 printf("\n succes \n") ;
		}

		if(tst==3){
    	printf(" data  search :") ;
		scanf("%d",&data) ;
		 if(search(l,data))
		 printf("\n possition :%d \n",search(l,data)) ;
		}
		if(tst==4){
		 if(Max(l))
		 printf("\n Node for Max :%d \n",Max(l)) ;
		}
		if(tst==5){
		 if(Min(l))
		 printf("\n Node for Min :%d \n",Min(l)) ;
		}

        if(tst==6){
    	 printf(" data  successor :") ;
		scanf("%d",&data) ;
    	 a =successor(l,NewNode(data)) ;
		 if(a!=NULL)
		 printf("\nNode for successor :%d \n",a) ;
		}
		if(tst==7){
    	  printf(" data  predecessor :") ;
		scanf("%d",&data) ;
    	 a =predecessor(l,NewNode(data)) ;
		 if(a!=NULL)
		 printf("\n Node for predecessor :%d \n",a) ;
		}
     if(tst==8){
    	affiche(l);
		}

}
	return 0;
}

