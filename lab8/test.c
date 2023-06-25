#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sNode sNode;

struct sNode
{
  int data;
  sNode *next;
};

size_t listLength (const sNode * L)
{
  sNode *curr = L;
  size_t len = 0;

  while (curr != NULL)
    {
      ++len;
      curr = curr->next;
    }
  return len;
}

void
push (struct sNode **head_ref, int new_data)
{
  /* allocate node */
  struct sNode *new_node = (struct sNode *) malloc (sizeof (struct sNode));

  /* put in the data  */
  new_node->data = new_data;

  /* link the old list off the new node */
  new_node->next = (*head_ref);

  /* move the head to point to the new node */
  (*head_ref) = new_node;
}

sNode *listRev (sNode * L)
{
sNode * temp = NULL;
sNode * curr = L;
sNode * next = NULL;
sNode * final = NULL;
while (curr != NULL){ 
    if (curr->next == NULL){
        final = curr;
    }
    next = curr->next;
    curr->next = temp;
    temp = curr;
    curr = next;
    
}
return final;
}



int
main ()
{
  /* Start with the empty list */
  struct sNode *head = NULL;

  /* Use push() to construct below list
     1->2->1->3->1  */
  push (&head, 5);
  push (&head, 4);
  push (&head, 3);
  push (&head, 2);
  push (&head, 1);
  push (&head, 1);

struct sNode *temp = listRev(head);
//struct sNode *temp = head;
printf ("count of nodes is %d\n", (int) listLength(temp));

printf("\n\nList elements are - \n");

while(temp != NULL) {
  printf("%d --->",temp->data);
  temp = temp->next;
}
  /* Check the count function */
  printf ("count of nodes is %d\n", (int) listLength(head));
  return 0;
}

