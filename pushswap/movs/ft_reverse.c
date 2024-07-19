#include "../pushswap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// Function to reverse rotate stack a (move last element to the front)
void ft_reverse_rotatea(node_a **head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) return;

    node_a *second_last = NULL;
    node_a *last = *head_ref;
    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
    write(1, "rra\n", 4);
}

// Function to reverse rotate stack b (move last element to the front)
void ft_reverse_rotateb(node_a **head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) return;

    node_a *second_last = NULL;
    node_a *last = *head_ref;
    while (last->next != NULL) {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
    write(1, "rrb\n", 4);
}

// Function to reverse rotate both stacks a and b
void ft_reverse_rotater(node_a **head_a, node_a **head_b) {
    ft_reverse_rotatea(head_a);
    ft_reverse_rotateb(head_b);
    write(1, "rrr\n", 4);
}
