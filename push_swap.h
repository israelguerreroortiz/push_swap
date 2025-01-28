/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:01:48 by isrguerr          #+#    #+#             */
/*   Updated: 2025/01/28 13:34:26 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
typedef struct stack_node
{
	int					value;
	struct stack_node	*next;
}						stack_node;

void					stack_init(stack_node **a, char **argv);
void					print_node_value(int content);
int						input_error(stack_node **a, char *arg);
void					add_to_node(stack_node **stack, int nbr);
void					ft_swap(stack_node **stack, char c);
void					ft_swap_both(stack_node **a, stack_node **b);
void					ft_rotate(stack_node **stack, char c);
void					ft_reverse(stack_node **stack, char c);
void					ft_reverse_both(stack_node **a, stack_node **b);
void					ft_rotate_both(stack_node **a, stack_node **b);
int						ft_lst_include(stack_node **stack, int nbr);
void					ft_push(stack_node **dest, stack_node **src, char c);
void					sort_stack(stack_node **a, stack_node **b);
int						smallest_number(stack_node **stack);
long					ft_atol(const char *str);
void					free_stack(stack_node **a);
int	quick_sort(stack_node **a, stack_node **b, int size);
void sort_b(stack_node **a, stack_node **b, int chunksize);

#endif