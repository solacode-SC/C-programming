#include "../pushswap.h"

int has_duplicates(stack_t **head_a) {
    stack_t *current = *head_a;
    stack_t *runner;
    
    while (current != NULL) {
        runner = current->next;
        while (runner != NULL) {
            if (runner->data == current->data) {
                return 1;  // Duplicate found
            }
            runner = runner->next;
        }
        current = current->next;
    }
    return 0;  // No duplicates found
}


// Helper function to copy linked list values to an array
void copy_to_array(stack_t *head, int *arr) {
    int i = 0;
    stack_t *temp = head;
    while (temp) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
}

// Partition function for quicksort
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Quicksort function
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


void global_sort(stack_t **head_a, stack_t **head_b) {
    int len_list = get_listlen(*head_a);
    int *sorted_array = (int *)malloc(sizeof(int) * len_list);
    int i = 0;
    
    copy_to_array(*head_a, sorted_array);
    while (i < len_list)
    {
        printf("\n num : %d", sorted_array[i]);
        i++;
    }
    printf("\n++++\n");
    quicksort(sorted_array, 0, len_list - 1);
    i = 0;
    while (i < len_list)
    {
        printf("\n num : %d", sorted_array[i]);
        i++;
    }
    printf("\n++++\n");
    if (len_list >= 6)
        lets_sort_100(head_a, head_b, sorted_array);
    printf("\n");
}

// void lets_sort_100(stack_t **head_a, stack_t **head_b, int *sorted_array) {
//     int len_list = get_listlen(*head_a); // Get the length of list A
//     int low = 0; // Initialize low index
//     int high = 5; // Initialize high index
//     int pushed = 0; // Track the number of elements pushed to B

//     while (*head_a) { // Traverse through each element in list A
//         if ((*head_a)->data < sorted_array[low]) {
//             // Push element from A to B, then rotate B
//             ft_pushb(head_a, head_b);
//             ft_rotateb(head_b);

//             // Increment high and low pointers if within bounds
//             pushed++;
//             if (high < len_list) high++;
//             if (low < high) low++;
//         } else if ((*head_a)->data >= sorted_array[low] && (*head_a)->data <= sorted_array[high]) {
//             // Push element from A to B
//             ft_pushb(head_a, head_b);

//             // Increment high and low pointers if within bounds
//             pushed++;
//             if (high < len_list) high++;
//             if (low < high) low++;
//         } else if ((*head_a)->data > sorted_array[high]) {
//             // Rotate A
//             ft_rotatea(head_a);
//         }

//         // If list A is modified, update temp to new head_a
//         if (pushed) {
//             pushed = 0;
//         } else {
//             // Move to the next element in list A if no push operation was performed
//             ft_rotatea(head_a);
//         }
//     }
// }

// int set_high(int num) {

// }
void lets_sort_100(stack_t **head_a, stack_t **head_b, int *sorted_array) {
    int len_list = get_listlen(*head_a); // Get the length of list A
    int low = 0; // Initialize low index
    int high = 15; // Initialize high index

    while (*head_a) { // Traverse through each element in list A
        if ((*head_a)->data < sorted_array[low]) {
            // Push element from A to B, then rotate B
            ft_pushb(head_a, head_b);
            ft_rotateb(head_b);

            // Increment high and low pointers if within bounds
            if (high < len_list - 1) high++;
            if (low < len_list -1) low++;
        } else if ((*head_a)->data >= sorted_array[low] && (*head_a)->data <= sorted_array[high]) {
            // Push element from A to B
            ft_pushb(head_a, head_b);

            // Increment high and low pointers if within bounds
            if (high < len_list - 1) high++;
            if (low < len_list -1) low++;
        } else if ((*head_a)->data > sorted_array[high]) {
            // Rotate A
            ft_rotatea(head_a);
        } 
        // else {
        //     // This should never be reached, but just in case:
        //     // Rotate A to avoid infinite loop
        //     ft_rotatea(head_a);
        // }
    }
}
