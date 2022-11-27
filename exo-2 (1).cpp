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
return new_node;} ;

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


    
  void affiche(struct list *L){	
 
   if(isEmpty(L)) {
      printf("Linked List not initialized");
   }
   else{
   	printf("--------------------List--------------------\n");
   	 struct Node* current = L->head;
   while(current!=NULL) {
   	printf("%d \n",current->data) ;
         current = current->next;}
   } }
 void split(struct Node* head, struct Node** a, struct Node** b)
{
    struct Node* slow = head;
    struct Node* fast = head->next;
 
    // advance `fast` by two nodes, and advance `slow` by a single node
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *b = slow->next;
    slow->next = NULL;
}

struct Node* merge(struct Node* a, struct Node* b)
{
    // base cases
    if (a == NULL) {
        return b;
    }
 
    if (b == NULL) {
        return a;
    }
 
    // pick either `a` or `b`, and recur
    if (a->data <= b->data)
    {
        a->next = merge(a->next, b);
        a->next->prev = a;
        a->prev = NULL;
        return a;
    }
    else
    {
        b->next = merge(a, b->next);
        b->next->prev = b;
        b->prev = NULL;
        return b;
    }}
    
 
void mergeSort(struct Node** head)
{
    // base case: 0 or 1 node
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
 
    // split head into `a` and `b` sublists
    struct Node *a = *head, *b = NULL;
    split(*head, &a, &b);
 
    // recursively sort the sublists
    mergeSort(&a);
    mergeSort(&b);
 
    // merge the two sorted lists
    *head = merge(a, b);
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
    	printf(" 2- sorting doubly linked lists\n") ;
    	printf(" 3- affiche lindklist \n ") ;
    	scanf("%d",&tst) ;
    	if(tst==1){
    	printf(" add new data  :") ;
		scanf("%d",&data) ;	
    	 a =insert(l,NewNode(data)) ;
		 if(a==1)
		 printf("\n succes \n") ;	
		}
		if(tst==2){
		 mergeSort(&l->head);
		 printf("\n succes \n") ;	
		}

     if(tst==3){
    	affiche(l);	
		}
    
}
	return 0;
}

