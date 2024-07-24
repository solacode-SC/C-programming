#include "../pushswap.h"

void sorting_three(stack_t **head_a, stack_t **head_b) {
    ft_pushb(&head_a, &head_b);
    stack_t *ref = *head_a;
    if (ref->data > ref->next->data)
        ft_rotatea(ref);
    if ()

}

void set_algo(int len, stack_t **head_a, stack_t **head_b) {
    if (len <= 3) {

    }
}