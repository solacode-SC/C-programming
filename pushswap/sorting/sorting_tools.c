#include "../pushswap.h"

int has_duplicates(stack_t **head_a) {
    stack_t *current;
    stack_t *runner;
    
    current = *head_a;
    while (current != NULL) {
        runner = current->next;
        while (runner != NULL) {
            if (runner->data == current->data) {
                return 1;
            }
            runner = runner->next;
        }
        current = current->next;
    }
    return 0;
}



void copy_to_array(stack_t *head, int *arr) {
    int i;
    stack_t *temp;
    temp = head;
    i = 0;
    while (temp) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
}


int partition(int *arr, int low, int high) {
    int pivot;
    int i;
    int temp;

    i = low - 1;
    pivot = arr[high];
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}


void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


void global_sort(stack_t **head_a, stack_t **head_b) {
    int len_list;
    int *sorted_array;

    sorted_array = (int *)malloc(sizeof(int) * len_list);
    len_list = get_listlen(*head_a);
    copy_to_array(*head_a, sorted_array);
    quicksort(sorted_array, 0, len_list - 1);
    
    if (len_list >= 6) {
        lets_sort_100(head_a, head_b, sorted_array);
        
        best_move(head_a, head_b);
    }
}



static int	get_index_in_sorted_array(stack_t **head_b, int n)
{
	int	i;
    i = 0;
    stack_t *tmp;
	
    tmp = *head_b;
	while (tmp)
	{
        if(tmp->data == n)
        {
          break;
        }
        tmp = tmp->next;
        i++;
	}
	return (i);
}

void lets_sort_100(stack_t **head_a, stack_t **head_b, int *sorted_array) {
    int start;
    int len_list;
    int end;

    end = len_list / 6;
    len_list = get_listlen(*head_a);
    start = 0;
    while (*head_a) {
        if ((*head_a)->data >= sorted_array[start] && (*head_a)->data <= sorted_array[end]) {
            ft_pushb(head_a, head_b);
            if (end < len_list - 1) end++;
            start++;
        }
        else if ((*head_a)->data < sorted_array[start]) {
            ft_pushb(head_a, head_b);
            ft_rotateb(head_b);
            if (end < len_list -1) end++;
            start++;
        }
        else if ((*head_a)->data > sorted_array[end])  
            ft_rotatea(head_a);
        
    }
}


static int find_max_in_stack(stack_t *head) {
    int max;
    stack_t *tmp;

    max = INT_MIN;
    tmp  = head;
    while (tmp) {
        if (tmp->data > max) {
            max = tmp->data;
        }
        tmp = tmp->next;
    }

    return max;
}


void best_move(stack_t **head_a, stack_t **head_b) {
    int middle;
    int max;
    int len;
    int max_index;

    while (*head_b) {
        len = get_listlen(*head_b);
        middle = len / 2;
        max = find_max_in_stack(*head_b);
        max_index = get_index_in_sorted_array(head_b, max);
       

        if (max_index <= middle) {
            while((*head_b)->data != max)
                ft_rotateb(head_b);
        }
        else if(max_index > middle){
            while((*head_b)->data != max)
                ft_reverse_rotateb(head_b);
        }
        ft_pusha(head_a, head_b);
    }
}


