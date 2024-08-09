/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:18:27 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/09 19:35:09 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_rotatea(t_stack **head_ref)
{
	t_stack	*first;
	t_stack	*last;

	first = *head_ref;
	*head_ref = (*head_ref)->next;
	first->next = NULL;
	last = *head_ref;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

void	ft_rotateb(t_stack **head_ref)
{
	t_stack	*first;
	t_stack	*last;

	first = *head_ref;
	*head_ref = (*head_ref)->next;
	first->next = NULL;
	last = *head_ref;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	write(1, "rb\n", 3);
}

void	ft_rotater(t_stack **head_a, t_stack **head_b)
{
	ft_rotatea(head_a);
	ft_rotateb(head_b);
	write(1, "rr\n", 3);
}
