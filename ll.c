#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
} LinkedList;


// creates a single link in the LinkedList
LinkedList *create(void)
{
	LinkedList *l;

	l = malloc(sizeof(LinkedList));

	l->data = 0;
	l->next = NULL;

	return l;
}

// for building a random int list
void make_list(LinkedList **head, int n)
{
	int i;
	LinkedList *ref, *front;
	srand(time(NULL));

	if (*head == NULL)
	{
		*head = create();
	}

	front = *head;
	front->data = rand() % SIZE;


	ref = front->next;

	for (i = 0; i < n; ++i)
	{
		if (ref == NULL)
		{
			ref = create();
		}


		ref->data = rand() % SIZE;


		front->next = ref;

		front = front->next;

		ref = front->next;

	}

}

void print_list(LinkedList *list)
{

	LinkedList *temp;

	if (list == NULL)
	{
		printf("error: empty list\n");
		return;
	}

	temp = list;

	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

}


// destroys all links in the list via recursion
void destroy(LinkedList *list)
{
	if (list->next == NULL)
	{
		free(list);
		return;
	}

	destroy(list->next);
	free(list);
}





int main(void)
{
	LinkedList *list = create();

	make_list(&list, 10);

	print_list(list);

	destroy(list);

	return 0;
}
