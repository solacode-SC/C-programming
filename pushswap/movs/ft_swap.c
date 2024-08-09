/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:18:33 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/09 19:35:14 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_swapa(t_stack **head_ref)
{
	t_stack	*tmp;

	tmp = *head_ref;
	*head_ref = (*head_ref)->next;
	tmp->next = (*head_ref)->next;
	(*head_ref)->next = tmp;
	write(1, "sa\n", 3);
}

void	ft_swapb(t_stack **head_ref)
{
	t_stack	*tmp;

	tmp = *head_ref;
	*head_ref = (*head_ref)->next;
	tmp->next = (*head_ref)->next;
	(*head_ref)->next = tmp;
	write(1, "sb\n", 3);
}

void	ft_swaps(t_stack **head_ref1, t_stack **head_ref2)
{
	ft_swapa(head_ref1);
	ft_swapb(head_ref2);
	write(1, "ss\n", 3);
}
