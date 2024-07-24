#include "../pushswap.h"


// Function to rotate stack a (move first element to the end)
void ft_rotatea(stack_t **head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) return;

    stack_t *last = *head_ref;
    stack_t *second = (*head_ref)->next;
    while (last->next != NULL)
        last = last->next;

    last->next = *head_ref;
    (*head_ref)->next = NULL;
    *head_ref = second;
    write(1, "ra\n", 3);
}

// Function to rotate stack b (move first element to the end)
void ft_rotateb(stack_t **head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) return;

    stack_t *last = *head_ref;
    stack_t *second = (*head_ref)->next;
    while (last->next != NULL)
        last = last->next;

    last->next = *head_ref;
    (*head_ref)->next = NULL;
    *head_ref = second;
    write(1, "rb\n", 3);
}

// Function to rotate both stacks a and b
void ft_rotater(stack_t **head_a, stack_t **head_b) {
    ft_rotatea(head_a);
    ft_rotateb(head_b);
    write(1, "rr\n", 3);
}