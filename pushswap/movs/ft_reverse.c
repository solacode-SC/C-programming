/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:18:21 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/09 19:35:04 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static	void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_reverse_rotatea(t_stack **head_ref)
{
	t_stack	*last;

	last = *head_ref;
	while (last->next->next)
		last = last->next;
	ft_lstadd_front(head_ref, last->next);
	last->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_reverse_rotateb(t_stack **head_ref)
{
	t_stack	*last;

	last = *head_ref;
	while (last->next->next)
		last = last->next;
	ft_lstadd_front(head_ref, last->next);
	last->next = NULL;
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotater(t_stack **head_a, t_stack **head_b)
{
	ft_reverse_rotatea(head_a);
	ft_reverse_rotateb(head_b);
	write(1, "rrr\n", 4);
}
