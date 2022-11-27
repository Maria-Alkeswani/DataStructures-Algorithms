
//lab 1 , Exercise  6

// Jamal Alaskari & Maria Alkeswani


#include <stdio.h>
#include <stdlib.h>
struct node// A stack for Jamal's personal number
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
        printf(" %d -> ", head -> data);
        if(head->next)
        affiche(head->next);
    }
}

int main()
{
    newstrack();
   insert(1);
   insert(9);
   insert(9);
   insert(4);
   insert(0);
   insert(2);
   insert(1);
   insert(0);
   insert(6);
   insert(1);
   insert(3);
   insert(3);
printf("stack is :\n");
   affiche(head);



    return 0;
}
