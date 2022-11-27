//lab 1 , Exercise  4

// Jamal Alaskari & Maria Alkeswani
#include<stdio.h>
#include <stdlib.h>

struct Node // Queue with a linked list
{
   int data;
   struct Node *next;
};

struct Node *front = NULL,*rear = NULL;

void EnQueue(int val)
{
    struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = val;
    newNode -> next = NULL;

    if(front == NULL)
        front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
    printf("\n Data inserted in Queue!!!\n");
}


void affiche()
{
    if(front == NULL)
        printf("\n Queue is Empty!!!\n");
    else
    {
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            printf("%d --> ",temp->data);
            temp = temp -> next;
        }
        printf("%d \n",temp->data);
   }}
int main()
{
    int tst, val;
    while(1)
    {
        printf("\n------------------------\n");
        printf("1. Insert in Queue\n");
        printf("2. affiche Queue\n");
         scanf("%d",&tst);

        if(tst==1){
                printf("Insert the val: ");
                scanf("%d", &val);
                EnQueue(val);
                }
        if(tst==2){
                affiche();
        }        }

   return 0;
}





