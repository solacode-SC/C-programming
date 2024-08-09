/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:18:44 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/09 19:39:09 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	has_duplicates(t_stack **head_a)
{
	t_stack	*current;
	t_stack	*runner;

	current = *head_a;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (runner->data == current->data)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	copy_to_array(t_stack *head, int *arr)
{
	int		i;
	t_stack	*temp;

	temp = head;
	i = 0;
	while (temp)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	i = low - 1;
	j = low;
	pivot = arr[high];
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void	quicksort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

void	global_sort(t_stack **head_a, t_stack **head_b)
{
	int	len_list;
	int	*sorted_array;

	len_list = get_listlen(*head_a);
	sorted_array = (int *)malloc(sizeof(int) * len_list);
	copy_to_array(*head_a, sorted_array);
	quicksort(sorted_array, 0, len_list - 1);
	if (len_list >= 6)
	{
		lets_sort(head_a, head_b, sorted_array);
		best_move(head_a, head_b);
	}
	free(sorted_array);
}
