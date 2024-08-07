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

    
    copy_to_array(*head_a, sorted_array);
    quicksort(sorted_array, 0, len_list - 1);
    
    if (len_list >= 6) {
        lets_sort_100(head_a, head_b, sorted_array);
        
        best_move(head_a, head_b, sorted_array);
    }
}



static int	get_index_in_sorted_array(int *sorted, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == n)
			break ;
		i++;
	}
	return (i);
}

void lets_sort_100(stack_t **head_a, stack_t **head_b, int *sorted_array) {
    int start = 0;
    int end = get_listlen(*head_a) / 6;
    int len_list = get_listlen(*head_a) - 1;



    while (*head_a) {
        if ((*head_a)->data >= sorted_array[start] && (*head_a)->data <= sorted_array[end]) {
            ft_pushb(head_a, head_b);
            if (end < len_list) end++;
            start++;
        }
        else if ((*head_a)->data < sorted_array[start]) {
            ft_pusha(head_a, head_b);
            ft_rotateb(head_b);
            if (end < len_list) end++;
            start++;
        }
        else if ((*head_a)->data > sorted_array[end])  
            ft_rotatea(head_a);
        
    }
}


static int find_max_in_stack(stack_t *head) {
    int max = INT_MIN; // Initialize max to the smallest possible integer value

    while (head) {
        if (head->data > max) {
            max = head->data;
        }
        head = head->next;
    }

    return max;
}


void best_move(stack_t **head_a, stack_t **head_b, int *sorted_array) {
    int middle;
    int max;
    int len;

    while (*head_b) {
        len = get_listlen(*head_b);
        middle = len / 2;
        max = find_max_in_stack(*head_b);
        int max_index = get_index_in_sorted_array(sorted_array, len, max);

        if (max_index <= middle) {
            while((*head_b)->data != max)
                ft_rotateb(head_b);
        }
        else {
            while((*head_b)->data != max)
                ft_reverse_rotateb(head_b);
        }
        ft_pusha(head_a, head_b);
    }
}


