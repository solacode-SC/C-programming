/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:18:09 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/09 19:34:58 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_pusha(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;

	temp = *head_b;
	*head_b = (*head_b)->next;
	temp->next = *head_a;
	*head_a = temp;
	write(1, "pa\n", 3);
}

void	ft_pushb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;

	temp = *head_a;
	*head_a = (*head_a)->next;
	temp->next = *head_b;
	*head_b = temp;
	write(1, "pb\n", 3);
}
