#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;

} Node;

// function for displaying the list
void
display (struct Node *ptr)
{
  printf ("Elements in the linked list :\n");
  while (ptr != NULL)
    {
      if (ptr->next != NULL)
	{
	  printf ("%d -> ", ptr->data);
	  ptr = ptr->next;
	}
      else
	{
	  printf ("%d ", ptr->data);
	  ptr = ptr->next;
	}
    }
}

//function for inserting at the beginning
struct Node *
InsertAtBeg (struct Node *head, int data)
{
  Node *new;
  new = (struct Node *) malloc (sizeof (struct Node));
  new->next = head;
  new->data = data;

  return new;
}

//function for inserting at the End
struct Node *
InsertAtEnd (struct Node *head, int data)
{
  Node *p = head;
  Node *new = (struct Node *) malloc (sizeof (struct Node));

  while (p->next != NULL)
    {
      p = p->next;
    }

  p->next = new;
  new->data = data;
  new->next = NULL;
  return head;
}

//function for inserting at the specific index
struct Node *
InsertAtPos (struct Node *head, int pos, int data)
{
  Node *p = head;
  Node *new = (struct Node *) malloc (sizeof (struct Node));

  for (int i = 1; i < pos - 1; i++)
    {
      p = p->next;
    }
  new->next = p->next;
  p->next = new;
  new->data = data;

  return head;
}

//function for deleting at the beginning
struct Node *
DeleteAtBeg (struct Node *head)
{
  Node *p = head;
  head = head->next;

  free (p);

  return head;
}

//function for deleting at the end
struct Node *
DeleteAtEnd (struct Node *head)
{
  Node *p = head;
  Node *q = head->next;
  while (q->next != NULL)
    {
      p = p->next;
      q = q->next;
    }
  p->next = NULL;
  free (q);

  return head;
}

//function for deleting at the pos
struct Node *
DeleteAtPos (struct Node *head, int pos)
{
  Node *p = head;
  Node *q = head->next;
  int i = 1;
  while (i < pos - 1)
    {
      p = p->next;
      q = q->next;
      i++;
    }
  p->next = q->next;
  free (q);

  return head;
}

int
main ()
{
  Node *head;
  head = (struct Node *) malloc (sizeof (struct Node));
  head = NULL;

  int data, pos;

  char operation;

    //taking input from user what to perform
  while (operation != 'a')
    {
      scanf (" %c", &operation);

      switch (operation)
	{
	case 'a':
	  display (head);
	  break;

	case 'b':
	  scanf ("%d", &data);
	  head = InsertAtBeg (head, data);
	  break;

	case 'c':
	  scanf ("%d", &data);
	  head = InsertAtEnd (head, data);
	  break;
	case 'd':
	  scanf ("%d%d", &pos, &data);
	  head = InsertAtPos (head, pos, data);
	  break;
	case 'e':
	  head = DeleteAtBeg (head);
	  break;
	case 'f':
	  head = DeleteAtEnd (head);
	  break;
	case 'g':
	  scanf ("%d", &pos);
	  head = DeleteAtPos (head, pos);
	  break;

	default:
	  printf ("Error");
	  goto end;
	  break;
	}
}
end: 
    

  return 0;
}


