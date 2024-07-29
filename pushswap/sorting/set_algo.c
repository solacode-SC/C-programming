
#include "../pushswap.h"

int isSorted(stack_t* head) {
    // An empty list or a list with a single node is considered sorted
    if (head == NULL || head->next == NULL)
        return 1;

    // Traverse the list and check if each element is less than or equal to the next
    stack_t* current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data)
            return 0; // Not sorted
        current = current->next;
    }
    return 1; // Sorted
}

void sorting_three(stack_t **head_a) {
    stack_t *ref = *head_a;
    int a = ref->data;
    int b = ref->next->data;
    int c = ref->next->next->data;

    if (a > b && b < c && a < c) {
        // Case: 2 1 3 -> 1 2 3
        ft_swapa(head_a);
    } else if (a > b && b > c) {
        // Case: 3 2 1 -> 1 2 3
        ft_swapa(head_a);
        ft_reverse_rotatea(head_a);
    } else if (a > b && b < c && a > c) {
        // Case: 3 1 2 -> 1 2 3
        ft_rotatea(head_a);
    } else if (a < b && b > c && a < c) {
        // Case: 1 3 2 -> 1 2 3
        ft_swapa(head_a);
        ft_rotatea(head_a);
    } else if (a < b && b > c && a > c) {
        // Case: 2 3 1 -> 1 2 3
        ft_reverse_rotatea(head_a);
    }
}

// void sorting_four(stack_t **head_a, stack_t **head_b) {
//     stack_t *ref = *head_a;
//     //get max num from stack a
//     int max_a = ref->data;
//     int i = 0;
//     int max_i = 0;
//     stack_t *current = ref->next;
//     while (current) {
//         if (current->data > max_a) {
//             max_a = current->data;
//             max_i = i;
//         }
//         current = current->next;
//         i++;
//     }
//     if (max_i == 0) {
//         ft_pushb(head_a, head_b);
//         sorting_three(head_a);
//         ft_rotatea(head_a, head_b);
//     }
//     else if (max_i == 1) {
//         ft_swapa(head_a);
//         ft_pushb(head_a, head_b);
//         sorting_three(head_a);
//         ft_rotatea(head_a, head_b);
//     }
//     else if (max_i == 2) {
//         ft_reverse_rotatea(head_a);
//         ft_reverse_rotatea(head_a);
//         ft_pushb(head_a, head_b);
//         sorting_three(head_a);
//         ft_rotatea(head_a, head_b);
//     }
//     else if (max_i == 3) {
//         ft_reverse_rotatea(head_a);
//         ft_pushb(head_a, head_b);
//         sorting_three(head_a);
//         ft_rotatea(head_a, head_b);
//     }
// }

void set_algo(int len, stack_t **head_a, stack_t **head_b) {
    if (len == 3) {
        sorting_three(head_a);
    }
    // else if (len == 4) {
    //     sorting_four(head_a, head_b);
    // }
    stack_t *current = *head_b;
    if (current)
        write(1, "\n", 1);
}
// 