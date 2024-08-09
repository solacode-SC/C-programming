/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:18:01 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/09 19:33:47 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack	*createnode(int data)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}

void	appendnode(t_stack **head, int data)
{
	t_stack	*newnode;
	t_stack	*temp;

	newnode = createnode(data);
	if (*head == NULL)
		*head = newnode;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}

int	get_listlen(t_stack *head)
{
	int		len;
	t_stack	*temp;

	len = 0;
	temp = head;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

void	free_all(t_stack **head)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *head;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*head = NULL;
}
