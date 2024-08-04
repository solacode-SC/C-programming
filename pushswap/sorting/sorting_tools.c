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
    printf("\n");
    free_all(head_a);
    free_all(head_b);
    free(sorted_array);
}

void lets_sort_100(stack_t **head_a, stack_t **head_b, int *sorted_array) {
    int len_list = get_listlen(*head_a);
    int low = 0;
    int high = 5;
    stack_t *temp = head_a;
    while (temp) {
        if (temp->data < sorted_array[low]) {
            //pb rb i++ j++
            ft_pushb(head_a, head_b);
            ft_rotateb(head_b);
            if (high < len_list)
                high++;
            if (low < high)
                low++;
        }
        else if (temp->data >= sorted_array[low] && temp->data <= sorted_array[high]) {
            //pb i++ j++
            ft_pushb(head_a, head_b);
            if (high < len_list)
                high++;
            if (low < high)
                low++;
        }
        else if (temp->data > sorted_array[high]) {
            // ra
            ft_rotatea(head_a);
        }
        temp = temp->next;
    } 

}