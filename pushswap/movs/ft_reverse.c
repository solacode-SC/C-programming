#include "../pushswap.h"

static void    ft_lstadd_front(stack_t **lst, stack_t *new)
{
        if (!lst || !new)
                return ;
        new->next = *lst;
        *lst = new;
}

void ft_reverse_rotatea(stack_t **head_ref) {
    stack_t *last;
    last = *head_ref;
    while (last->next->next) {
        last = last->next;
    }
    ft_lstadd_front(head_ref, last->next);
    last->next = NULL;
    write(1, "rra\n", 4);
}

void ft_reverse_rotateb(stack_t **head_ref) {
    stack_t *last;
    last = *head_ref;
    while (last->next->next) {
        last = last->next;
    }

    ft_lstadd_front(head_ref, last->next);
    last->next = NULL;
    write(1, "rrb\n", 4);
}

void ft_reverse_rotater(stack_t **head_a, stack_t **head_b) {
    ft_reverse_rotatea(head_a);
    ft_reverse_rotateb(head_b);
    write(1, "rrr\n", 4);
}
