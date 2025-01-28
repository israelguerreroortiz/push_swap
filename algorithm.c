/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:44:29 by iisraa11          #+#    #+#             */
/*   Updated: 2025/01/27 12:55:01 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	smallest_number(stack_node **stack)
{
	stack_node	*current;
	int			temp;

	if (*stack == NULL)
		return (-1);
	current = *stack;
	temp = current->value;
	while (current != NULL)
	{
		if (current->value < temp)
			temp = current->value;
		current = current->next;
	}
	return (temp);
}

static int position(stack_node **stack, int objetive)
{
	int count;
	stack_node *current;

	current = *stack;
	count = 0;
	while(current != NULL)
	{
		if (current->value == objetive)
			break;
		count++;
		current = current->next;
	}
	return (count);
}

int biggest_number(stack_node **b, int size)
{
	stack_node *current;
	int max;

	if (size <= 0 || *b == NULL)
		return (-1);
	current = *b;
	max = current->value;
	current = current->next;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

void	cost_algorithm(stack_node **a, stack_node **b, int biggest, int smallest)
{
	
}

void	sort_stack(stack_node **a, stack_node **b)
{	
	ft_push(b, a, 'b');
	ft_push(b, a, 'b');
	while(ft_lstsize(*a) > 3)
		cost_algorithm(a, b);
	small_sort(a);
	push_to_a(a, b);
}