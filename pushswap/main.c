/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:18:49 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/08 23:57:17 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		i;
	int		len;

	i = 1;
	head_a = NULL;
	head_b = NULL;
	if (argc <= 1)
		return (0);
	while (i < argc)
	{
		parseandstorenumbers(argv[i], &head_a, &head_b);
		i++;
	}
	if (get_listlen(head_a) < 2)
		return (0);
	else
	{
		len = get_listlen(head_a);
		set_algo(len, &head_a, &head_b);
	}
	free_all(&head_a);
	free_all(&head_b);
}
