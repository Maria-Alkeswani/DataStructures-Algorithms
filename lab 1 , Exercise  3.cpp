//lab 1 , Exercise  3

// Jamal Alaskari & Maria Alkeswani

#include <stdio.h>
#include <stdlib.h>
struct node // Stack with a linked list
{
    int data;
    struct node *next;
};
typedef struct node node;

node *head;

void newstrack()
{
    head = NULL;
}

void insert(int value)
{
   struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp -> data = value;
    tmp -> next = head;
    head = tmp;
}



void affiche(node *head)
{
    if(head == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%d\n", head -> data);
        if(head->next)
        affiche(head->next);
    }
}

int main()
{   int tst, val ;
    newstrack();
    while(1)
    {
        printf("\n------------------------\n");
        printf("1. Insert in stack\n");
        printf("2. affiche stack\n");
         scanf("%d",&tst);

        if(tst==1){
                printf("Insert the val: ");
                scanf("%d", &val);
                insert(val);
                }
        if(tst==2){
                affiche(head);
                }

 }
    return 0;
}
