
#include "../pushswap.h"

int isSorted(stack_t* head) {
    if (head == NULL || head->next == NULL)
        return 1;

    stack_t* current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data)
            return 0; // Not sorted
        current = current->next;
    }
    return 1; // Sorted
}

void sorting_two(stack_t **head_a) {
    stack_t *ref = *head_a;

    if (ref->data > ref->next->data) {
        ft_swapa(head_a);
    }
}

void sorting_three(stack_t **head_a) {
    stack_t *ref = *head_a;
    int a = ref->data;
    int b = ref->next->data;
    int c = ref->next->next->data;

    if (a > b && b < c && a < c) {
        ft_swapa(head_a);
    } else if (a > b && b > c) {
        ft_swapa(head_a);
        ft_reverse_rotatea(head_a);
    } else if (a > b && b < c && a > c) {
        ft_rotatea(head_a);
    } else if (a < b && b > c && a < c) {
        ft_swapa(head_a);
        ft_rotatea(head_a);
    } else if (a < b && b > c && a > c) {
        ft_reverse_rotatea(head_a);
    }
}

int get_max(stack_t **head_a) {
    stack_t *ref = *head_a;
    int max_a = ref->data;
    int i = 0;
    int max_i = 0;
    stack_t *current = ref->next;
    while (current) {
        i++;
        if (current->data > max_a) {
            max_a = current->data;
            max_i = i;
        }
        current = current->next;
    }
    return max_i;
}

void sorting_four(stack_t **head_a, stack_t **head_b) {
    
    if (get_max(head_a) == 0) {
        ft_pushb(head_a, head_b);
        sorting_three(head_a);
        ft_pusha(head_a, head_b);
        ft_rotatea(head_a);
    }
    else if (get_max(head_a) == 1) {
        ft_swapa(head_a);
        ft_pushb(head_a, head_b);
        sorting_three(head_a);
        ft_pusha(head_a, head_b);
        ft_rotatea(head_a);
    }
    else if (get_max(head_a) == 2) {
        ft_reverse_rotatea(head_a);
        ft_reverse_rotatea(head_a);
        ft_pushb(head_a, head_b);
        sorting_three(head_a);
        ft_pusha(head_a, head_b);
        ft_rotatea(head_a);
    }
    else if (get_max(head_a) == 3) {
        ft_reverse_rotatea(head_a);
        ft_pushb(head_a, head_b);
        sorting_three(head_a);
        ft_pusha(head_a, head_b);
        ft_rotatea(head_a);
    }
}



void sorting_five(stack_t **head_a, stack_t **head_b) {
    if (get_max(head_a) == 0) {
        ft_pushb(head_a, head_b);
        sorting_four(head_a, head_b);
        ft_pusha(head_a, head_b);
        ft_rotatea(head_a);
    }
    else if (get_max(head_a) == 1) {
        ft_swapa(head_a);
        ft_pushb(head_a, head_b);
        sorting_four(head_a, head_b);
        ft_pusha(head_a, head_b);
        ft_rotatea(head_a);
    }
    else if (get_max(head_a) == 2) {
        ft_rotatea(head_a);
        ft_rotatea(head_a);
        ft_pushb(head_a, head_b);
        sorting_four(head_a, head_b);
        ft_pusha(head_a, head_b);
        ft_rotatea(head_a);
    }
    else if (get_max(head_a) == 3) {
        ft_reverse_rotatea(head_a);
        ft_reverse_rotatea(head_a);
        ft_pushb(head_a, head_b);
        sorting_four(head_a, head_b);
        ft_pusha(head_a, head_b);
        ft_rotatea(head_a);
    }
    else if (get_max(head_a) == 4) {
        ft_reverse_rotatea(head_a);
        ft_pushb(head_a, head_b);
        sorting_four(head_a, head_b);
        ft_pusha(head_a, head_b);
        ft_rotatea(head_a);
    }
}


void set_algo(int len, stack_t **head_a, stack_t **head_b) {
    if (has_duplicates(head_a) || isSorted(*head_a))
        print_error(head_a, head_b);
    if (len == 2)
        sorting_two(head_a);
    else if (len == 3)
        sorting_three(head_a);
    else if (len == 4)
        sorting_four(head_a, head_b);
    else if (len == 5)
        sorting_five(head_a, head_b);
    else if (len > 5)
        global_sort(head_a, head_b);
}