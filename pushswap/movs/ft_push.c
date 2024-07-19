#include "../pushswap.h"


// Function to push the first element in stack b to the top of stack a
void ft_pusha(node_a **head_a, node_a **head_b) {
    if (*head_b == NULL) return;

    node_a *temp = *head_b;
    *head_b = (*head_b)->next;
    temp->next = *head_a;
    *head_a = temp;
    write(1, "pa\n", 3);
}

// Function to push the first element in stack a to the top of stack b
void ft_pushb(node_a **head_a, node_a **head_b) {
    if (*head_a == NULL) return;

    node_a *temp = *head_a;
    *head_a = (*head_a)->next;
    temp->next = *head_b;
    *head_b = temp;
    write(1, "pb\n", 3);
}
