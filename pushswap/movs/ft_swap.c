#include "../pushswap.h"

// Function to swap the first 2 elements at the top of stack a
void ft_swapa(stack_t **head_ref) {
    stack_t *temp = *head_ref;
    if (temp == NULL || temp->next == NULL) return;

    stack_t *second = temp->next;
    temp->next = second->next;
    second->next = temp;
    *head_ref = second;
    write(1, "sa\n", 3);
}

// Function to swap the first 2 elements at the top of stack b
void ft_swapb(stack_t **head_ref) {
    stack_t *temp = *head_ref;
    if (temp == NULL || temp->next == NULL) return;

    stack_t *second = temp->next;
    temp->next = second->next;
    second->next = temp;
    *head_ref = second;
    write(1, "sb\n", 3);
}

// Function to swap the first 2 elements at the top of both stacks a and b
void ft_swaps(stack_t **head_ref1, stack_t **head_ref2) {
    ft_swapa(head_ref1);
    ft_swapb(head_ref2);
    write(1, "ss\n", 3);
}