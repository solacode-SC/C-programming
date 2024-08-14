/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:13:55 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/09 19:31:27 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

t_stack		*createnode(int data);
void		appendnode(t_stack **head, int data);
long		my_strtol(const char *str, char **endPtr);
void		parseandstorenumbers(const char *str,
				t_stack **head_a, t_stack **head_b);
void		ft_pusha(t_stack **head_a, t_stack **head_b);
void		ft_pushb(t_stack **head_a, t_stack **head_b);
void		ft_reverse_rotatea(t_stack **head_ref);
void		ft_reverse_rotateb(t_stack **head_ref);
void		ft_reverse_rotater(t_stack **head_a, t_stack **head_b);
void		ft_rotatea(t_stack **head_ref);
void		ft_rotateb(t_stack **head_ref);
void		ft_rotater(t_stack **head_a, t_stack **head_b);
void		ft_swapa(t_stack **head_ref);
void		ft_swapb(t_stack **head_ref);
void		ft_swaps(t_stack **head_ref1, t_stack **head_ref2);
void		sorting_five(t_stack **head_a, t_stack **head_b);
int			has_duplicates(t_stack **head_a);
void		quicksort(int *arr, int low, int high);
int			partition(int *arr, int low, int high);
void		copy_to_array(t_stack *head, int *arr);
void		global_sort(t_stack **head_a, t_stack **head_b);
void		lets_sort(t_stack **head_a, t_stack **head_b, int *sorted_array);
void		best_move(t_stack **head_a, t_stack **head_b);
void		plus_one(int *start, int *end, int len_list);
void		set_end(int *end, int len_list);
void		free_all(t_stack **heade);
int			get_listlen(t_stack *head);
int			is_no_digit(const char *str);
void		print_error(t_stack **head_a, t_stack **head_b);
void		sorting_two(t_stack **head_a);
void		sorting_three(t_stack **head_a);
void		sorting_four(t_stack **head_a, t_stack **head_b);
void		sorting_five(t_stack **head_a, t_stack **head_b);
void		set_algo(int len, t_stack **head_a, t_stack **head_b);
int			issorted(t_stack *head);

#endif 
