#include "../pushswap.h"
#include <stdlib.h>

// Function to push the first element in stack b to the top of stack a
void ft_pusha(stack_t **head_a, stack_t **head_b) {
    if (*head_b == NULL) return;

    stack_t *temp = *head_b;
    *head_b = (*head_b)->next;
    temp->next = *head_a;
    *head_a = temp;
    write(1, "pa\n", 3);
}

// Function to push the first element in stack a to the top of stack b
void ft_pushb(stack_t **head_a, stack_t **head_b) {
    if (*head_a == NULL) return;

    stack_t *temp = *head_a;
    *head_a = (*head_a)->next;
    temp->next = *head_b;
    *head_b = temp;
    write(1, "pb\n", 3);
}
