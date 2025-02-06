/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:01:48 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/06 17:07:44 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_cost
{
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				index_a;
	int				rr;
	int				rrr;
	int				value;
}					t_cost;

void				stack_init(t_list **a, char **argv);
void				print_node_value(int content);
int					input_error(t_list **a, char *arg);
void				add_to_node(t_list **stack, int nbr);
void				ft_swap(t_list **stack, char c);
void				ft_swap_both(t_list **a, t_list **b);
void				ft_rotate(t_list **stack, char c);
void				ft_reverse(t_list **stack, char c);
void				ft_reverse_both(t_list **a, t_list **b);
void				ft_rotate_both(t_list **a, t_list **b);
int					ft_lst_include(t_list **stack, int nbr);
void				ft_push(t_list **dest, t_list **src, char c);
void				sort_stack(t_list **a, t_list **b);
int					smallest_number(t_list **stack);
long				ft_atol(const char *str);
void				free_stack(t_list **a);
void				push_to_a(t_list **a, t_list **b);
t_cost				find_min_cost(t_list **a, t_list **b, int median);
t_cost				calculate_cost(t_list **a, t_list **b, int index_b, int median, int size);
int					find_insert_position_cost(t_list **a, int value, int median);
void				push_to_a_mod(t_list **a, t_list **b);
int					find_median(t_list **stack, int size);
void				big_sort(t_list **a, t_list **b);

#endif