/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:55:39 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/09 19:35:31 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	plus_one(int start, int end, int len_list)
{
	if (end < len_list -1)
		end++;
	start++;
}

void	set_end(int end, int len_list)
{
	if (len_list <= 100)
		end = len_list / 6;
	else
		end = 35;
}

int	issorted(t_stack *head)
{
	t_stack	*current;

	if (head == NULL || head->next == NULL)
		return (1);
	current = head;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sorting_two(t_stack **head_a)
{
	t_stack	*ref;

	ref = *head_a;
	if (ref->data > ref->next->data)
		ft_swapa(head_a);
}
