#include "cycle.h"

int main()
{
    tnode *head = NULL;
	tnode *head2 = NULL;
	for(int i=0; i<6; i++)
	{
		tnode *new = malloc(sizeof(tnode));
		new->value = i;
		head = add_el(head, new);
	}	

	printf("Head:\n");
	print_list(head);

	for(int i=0; i<5; i++)
	{
		tnode *new = malloc(sizeof(tnode)); 
		new->value = 7 - i;
		head2 = add_el(head2, new);
	}	
	printf("\nHead2:\n");
	print_list(head2);

	tnode *polaczone = NULL;
	polaczone = add_list(head, head2);
	printf("\nLaczenie:\n");
	print_list(polaczone);

    printf("\nUsuwanie:\n");
	del_el(&polaczone, 4);
	print_list(polaczone);

    printf("\nOdwracanie:\n");
    rev_list(polaczone);
	print_list(polaczone);

	tnode *even = div_list(&polaczone);
	printf("\nParzyste:\n");
	print_list(even);
    printf("\nNieparzyste:\n");
	print_list(polaczone);
	
	free_list(&even);
	free_list(&polaczone);

    return 0;
}