#include "../pushswap.h"


void ft_rotatea(stack_t **head_ref) {

    stack_t	*first;
	stack_t	*last;

	first = *head_ref;
	*head_ref = (*head_ref)->next;
	first->next = NULL;
	last = *head_ref;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
    write(1, "ra\n", 3);
}

void ft_rotateb(stack_t **head_ref) {

    stack_t	*first;
	stack_t	*last;

	first = *head_ref;
	*head_ref = (*head_ref)->next;
	first->next = NULL;
	last = *head_ref;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
    write(1, "rb\n", 3);
}

void ft_rotater(stack_t **head_a, stack_t **head_b) {
    ft_rotatea(head_a);
    ft_rotateb(head_b);
    write(1, "rr\n", 3);
}