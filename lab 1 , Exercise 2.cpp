//lab 1 , Exercise  2

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
struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
	new_node->next = NULL;
return new_node;}

bool insert(struct list *L, Node * N){

	struct Node* last = L->head;

	if (isEmpty(L)) {
		L->head= N;
		return true;	}
		else {

	while (last->next != NULL)
		last = last->next;

	last->next = N;
	N->prev = last;
	return true;}

	return false;}

    int Maxposition(struct list *L){
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
int Minposition(struct list *L){
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

int predecessorposition(struct list *L, int k){
         int pos = 0;
   if(isEmpty(L)) {
      printf("Linked List not initialized");
      return NULL;
   } else{


  struct Node* current = L->head;
  struct Node* last = NULL;
   while(current!=NULL) {
   	pos++;
      if(pos == k) {
         return last->data;

      }   last =current ;
         current = current->next;}
   return NULL ;
    }    }


    int Max(struct list *L){
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


   return max ;
    }}
int Min(struct list *L){
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
   return min ;
    }}

int successor(struct list *L,int k){
      int pos = 0;
   if(isEmpty(L)) {
      printf("Linked List not initialized");
      return NULL;
   } else{


  struct Node* current = L->head;

   while(current!=NULL) {
   	pos++;
      if(current->data == k) {
         return current->next->data;

      }
         current = current->next;}
   return NULL ;
    }  }
int predecessor(struct list *L, int k){
         int pos = 0;
   if(isEmpty(L)) {
      printf("Linked List not initialized");
      return NULL;
   } else{


  struct Node* current = L->head;
  struct Node* last = NULL;
   while(current!=NULL) {
   	pos++;
      if(current->data == k) {
         return last->data;

      }   last =current ;
         current = current->next;}
   return NULL ;
    }    }

int main()
{int a ;
	struct list *l1= (struct list*)malloc(sizeof(struct list));
    l1->head =NewNode(3);
    a =insert(l1,NewNode(1)) ; //3; 1; 5; 10; 8; 7
    a =insert(l1,NewNode(5)) ;
	a =insert(l1,NewNode(10)) ;
    a =insert(l1,NewNode(8)) ;
    a =insert(l1,NewNode(7)) ;
    struct list *l2= (struct list*)malloc(sizeof(struct list));
    l2->head = NewNode(5);//5; 2; 9; 6; 1; 2
    a =insert(l2,NewNode(2)) ;
	a =insert(l2,NewNode(9)) ;
    a =insert(l2,NewNode(6)) ;
    a =insert(l2,NewNode(1)) ;
    a =insert(l2,NewNode(2)) ;



		 printf("\n Max l1 :%d min l1 :%d \n",Max(l1),Min(l1)) ;
		printf("\n Max l2 :%d min l2 :%d \n",Max(l2),Min(l2)) ;


		 printf("\n successor l1  key  5:%d \n",successor(l1,5) ) ;
		 printf("\n predecessor l1 key 5  :%d \n",predecessor(l1,5) ) ;
         printf("\n successor l2  key  9: %d \n",successor(l2,9) ) ;
		 printf("\n predecessor l2 key 9  :%d \n",predecessor(l2,9) ) ;
		 printf("\n predecessor l2 max de  l1  :%d \n",predecessorposition(l2,Maxposition(l1)) ) ;
		 printf("\n predecessor l1 max de l2  :%d \n",predecessorposition(l1,Maxposition(l2)) ) ;


	return 0;
}

