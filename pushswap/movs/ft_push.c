#include "../pushswap.h"

void ft_pusha(stack_t **head_a, stack_t **head_b) {

    stack_t *temp = *head_b;
    *head_b = (*head_b)->next;
    temp->next = *head_a;
    *head_a = temp;
    write(1, "pa\n", 3);
}

void ft_pushb(stack_t **head_a, stack_t **head_b) {
    stack_t *temp = *head_a;
    *head_a = (*head_a)->next;
    temp->next = *head_b;
    *head_b = temp;
    write(1, "pb\n", 3);
}



