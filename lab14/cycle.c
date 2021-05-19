#include "cycle.h"

void print_list(tnode *list)
{
    tnode* stop = list;
    tnode* temp = stop->next;
    printf("Lista: ");
    printf("%d, ", stop->value);
    while(temp != stop)
    {
        printf("%d, ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

tnode *add_el(tnode *head, tnode *el)
{
    if( head == NULL )
    {
        head = el;
        el->next = head;
    }
    else
    {
        tnode* temp = head;
        while( temp->next != head )
        {
            temp = temp->next;
        }
        temp->next = el;
        el->next = head;
    }
    return head;	
}

void del_el(struct tnode** head, int var)
{
    if (*head == NULL)
    {
        printf("List already empty\n");
        return;
    }

    tnode* temp = *head;
    tnode* prev = temp;

    unsigned int size = 1;
    while ( temp->next != *head )
    {
        temp = temp->next;
        size++;
    }

    unsigned int cur = 0;
    while(cur < size)
    {
        if(temp->value == var)
        {
            if(temp->next != temp)
            {
                prev->next = temp->next; 
            }
            else
            {
                prev->next = NULL;
            }

            if(temp == *head)
            {
                *head = prev->next;
            }

            free(temp);

            if(prev != NULL && prev->next != NULL)
            {
                temp = prev->next;
            } 
            else
            {
                temp = NULL;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
        cur++;
    }
}

tnode* add_list(tnode* head1, tnode* head2)
{
	if(head1 == NULL && NULL == head2)
	{
		printf("Lista jest pusta\n");
		return NULL;
	}
	if(head1 == NULL)
	{
		return head2;
	}
	if(head2 == NULL)
    {
		return head1;
	}

    tnode* last1 = head1;
    tnode* last2 = head2;

	while(last1->next != head1)
    {
		last1 = last1->next;
    }
    while(last2->next != head2)
    {
		last2 = last2->next;
    }
    last1->next = head2;
    last2->next = head1; 

	return head1;
}

tnode *div_list(tnode **original)
{
	if((*original) == NULL)
	{
		printf("Lista jest pusta\n");
		return NULL;
	}

	tnode *even = NULL; 
    tnode *temp = NULL; 

	tnode *last = *original; 
	while(last->next != (*original))
    {
		last = last->next;
    }
	last->next = NULL;

	tnode *cur = *original;
	tnode *prev = last;
    
	while(cur != NULL)
	{

		if(cur->value%2 == 0) 
		{
			prev->next = cur->next;
			if(even == NULL) 
			{
				even = cur;
				even->next = even;
				temp = even;
			}
			else
			{
				temp->next = cur;
				cur->next = even;
				temp = cur;
			}
			cur = prev;
		}
		prev = cur;
		cur = cur->next;
	}

	last = *original;
	while(last->next != NULL)
    {
		last = last->next;
    }
	last->next = *original;

	return even;
}

void rev_list(tnode *head)
{
	if(head == NULL)
	{
		printf("Lista jest pusta\n");
		return;
	}
	if(head->next == head)
    {
		return;
    }
	
	tnode *stop = head;
	tnode *temp = head;
    tnode *last = temp;
    unsigned int toSwap = 0;

	while(stop->next != head)
    {
		stop = stop->next;
        toSwap++;
    }
    last = stop;
    toSwap /= 2;
    for(unsigned int i=0; i<=toSwap; i++)
    {
        swap_el( temp, last );
        while(stop->next != last)
        {
            stop = stop->next;
        }
        last = stop;
        temp = temp->next;
    }
}

void free_list(tnode **head)
{
	if((*head) == NULL)
	{
		printf("Lista jest pusta\n");
		return;
	}

	tnode* temp = (*head)->next;
	(*head)->next = NULL;
	(*head) = temp;
    while(temp != NULL)
    {
        temp = (*head)->next;
        free(*head);
        (*head) = temp;
    }
    return;
}

void swap_el(tnode* node1 ,tnode* node2)
{
    int temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}
