/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 02:20:45 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/10 02:34:51 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	lets_sort(t_stack **head_a, t_stack **head_b, int *sorted_array)
{
	int	start;
	int	len_list;
	int	end;

	len_list = get_listlen(*head_a);
	end = 0;
	set_end(&end, len_list);
	start = 0;
	while (*head_a)
	{
		if ((*head_a)->data >= sorted_array[start]
			&& (*head_a)->data <= sorted_array[end])
		{
			ft_pushb(head_a, head_b);
			plus_one(&start, &end, len_list);
		}
		else if ((*head_a)->data < sorted_array[start])
		{
			ft_pushb(head_a, head_b);
			ft_rotateb(head_b);
			plus_one(&start, &end, len_list);
		}
		else if ((*head_a)->data > sorted_array[end])
			ft_rotatea(head_a);
	}
}

static	int	get_index_in_sorted_array(t_stack **head_b, int n)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *head_b;
	while (tmp)
	{
		if (tmp->data == n)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static	int	find_max_in_stack(t_stack *head)
{
	int		max;
	t_stack	*tmp;

	max = INT_MIN;
	tmp = head;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

void	best_move(t_stack **head_a, t_stack **head_b)
{
	int	middle;
	int	max;
	int	len;
	int	max_index;

	while (*head_b)
	{
		len = get_listlen(*head_b);
		middle = len / 2;
		max = find_max_in_stack(*head_b);
		max_index = get_index_in_sorted_array(head_b, max);
		if (max_index <= middle)
		{
			while ((*head_b)->data != max)
				ft_rotateb(head_b);
		}
		else if (max_index > middle)
		{
			while ((*head_b)->data != max)
				ft_reverse_rotateb(head_b);
		}
		ft_pusha(head_a, head_b);
	}
}
