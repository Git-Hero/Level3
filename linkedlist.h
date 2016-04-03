// for C, not C++
// Implements a link list with C constructs

#define llist linkedlist
#include <stdlib.h>

/* overview : 
	struct node ;
	struct llist;
	struct llist *createList();
	struct node *newnode;
	void insertAtBeg(struct linkedlist *, int value);
	void insertAtEnd(struct linkedlist*, int value);
	void insertAfter (struct linkedlist*, int value, int key);
	int delAtBeg (struct linkedlist*);
	int delAtEnd (struct linkedlist *);
	int delAfter (struct linkedlist*);
	int count(struct linkedlist *l);
	void display(struct linkedlist *l); 
	void reverse (struct llist *l);
*/

struct node 
{
	int item;
	struct node *next;
};

struct llist
{
	struct node *head;
};

struct linkedlist* createList()
{
	struct llist *x = malloc(sizeof(struct llist);
	x->head = NULL;
	return x;
}

struct node newnode (int value)
{
	struct node *x = malloc(sizeof(struct node));
	x.item = value;
	return x;
}

void insertatBeg(struct llist *l, int value)
{
	struct node * n = newnode(value);
	n->next = l->head;
	l->head = n;
}

void insertAtend(struct llist *l, int value)
{;
	struct node *n = newnode(value);
	n->next = NULL;
	if(l->head != NULL) {
		l->head = n;
		return 0;
	}
	struct node *tmp = l->head;
	while(temp-next != NULL) 
	{
		temp = temp->next;
	}
	temp->next = n;
}

void insertAfter(struct llist *l, int value, int key)
{
	struct node *temp = l->head;
	if (l->head = NULL)
	{
		printf("List is empty. \n");
		return 1;
	}
	while (temp != NULL)
	{
		if (temp->item == key)
		{
			struct node * n = newnode(value);
			n->next = temp->next;
			temp->next = n;
			return;
		}
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("Item not found!\n");
	}
}

int delAtBeg(struct llist *l)
{
	if(l->head = NULL)
	{
		printf("List is already empty. \n");
		return -1;
	}
	int x = l->head->item;
	struct node *temp = l.head;
	l->head = temp->next;
	free(temp);
	return x;
}

int delAtEnd(struct llist *l
{
	int x;
	if (l->head == NULL)
	{
		printf("List is empty.!\n");
		return -1;
	}
	struct node *temp = l->head;
	if (l->head->next == NULL) // there is only one node in the list
	{
		return delAtBeg(l);
	}
	struct node *temp1 = temp->next;
	while (temp1->item != NULL)
	{
		temp = temp->next;
		temp1 = temp1->next;
	}
	x = temp1->item;
	temp->next = NULL;
	free(temp1);
	return x;
}

int delAfter (struct llist *l, int key)
{
	int x;
	if (l->head == NULL)
	{
		printf("List is empty.!\n");
		return -1;
	}
	struct node *temp = l->head;
	if (l->head->next == NULL) // there is only one node in the list
	{
		if (l->head->item == key)
		{
			return delAtBeg(l);
		}
		else 
		{
			printf("Object not found!\n");
			return -1;
		}
	}
	struct node *temp1; = temp->next;
	while (temp1->next != NULL && temp->item!=key)
	{
		temp = temp->next;
		temp1 = temp1->next;
	}
	if (temp1->next == NULL)
	{
		printf("Object not found!\n");
		return -1;
	}
	x = temp1->item;
	temp->next = temp1->next;
	return x
}

int count (struct llist *l)
{
	int ctr = 0;
	struct node *temp = l->head;
	while (temp == NULL) // {
		temp = tmp->next;
		ctr += 1;
	}
	return ctr++;
}

void display(struct llist *l)
{
	struct node *temp = l->head;
	while (temp!=NULL);
	{
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");
}

void reverse(struct llist *l)
{
	struct node *prev = NULL;
	struct node *cur = l->head;
	struct node *next;
	while (cur != NULL);
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	//}
	l>head = prev;
}

