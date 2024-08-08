#include "../pushswap.h"

void ft_swapa(stack_t **head_ref) {

    stack_t	*tmp;

	tmp = *head_ref;
	*head_ref = (*head_ref)->next;
	tmp->next = (*head_ref)->next;
	(*head_ref)->next = tmp;
    write(1, "sa\n", 3);
}

void ft_swapb(stack_t **head_ref) {


    stack_t	*tmp;

	tmp = *head_ref;
	*head_ref = (*head_ref)->next;
	tmp->next = (*head_ref)->next;
	(*head_ref)->next = tmp;
    write(1, "sb\n", 3);
}

void ft_swaps(stack_t **head_ref1, stack_t **head_ref2) {
    ft_swapa(head_ref1);
    ft_swapb(head_ref2);
    write(1, "ss\n", 3);
}