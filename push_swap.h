/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:01:48 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/20 14:40:47 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_cost
{
	int				index_a;
	int				index_b;
	int				value;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total_cost;
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
void				push_to_a(t_list **a, t_list **b);
t_cost				find_min_cost(t_list **a, t_list **b);
int					calculate_cost(t_list **a, t_list **b, t_cost *cost,
						int value);
int					find_insert_position_cost(t_list *a, int value);
void				push_to_a_mod(t_list **a, t_list **b);
int					find_median(t_list **stack, int size);
void				big_sort(t_list **a, t_list **b);
t_cost				*min_cost(t_list **a, t_list **b);
int					find_insert_position_cost_a(t_list *list, int push);
int					is_sorted(t_list *stack, int size);
void				sort_four(t_list **a, t_list **b);
int					search_index(t_list *list, int value);
int					ft_case_rarb(t_list **a, t_list **b, t_cost *cost,
						int value);
void				sort_three(t_list **a);
int					ft_biggest(t_list *list);
void				insertion_sort(t_list **a, t_list **b);
int					ft_smallest(t_list *list);

// Apply movements

void				ft_apply_rr(t_list **a, t_list **b, int rr);
void				ft_apply_rrr(t_list **a, t_list **b, int rrr);
void				ft_apply_ra(t_list **a, int ra);
void				ft_apply_rb(t_list **b, int rb);
void				ft_apply_rra(t_list **a, int rra);
void				ft_apply_rrb(t_list **a, int rrb);

#endif