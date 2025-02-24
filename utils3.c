/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:06:20 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/24 19:32:23 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_four(t_list **a, t_list **b)
{
	int	smallest;
	int	smallest_i;

	smallest = ft_smallest(*a);
	smallest_i = search_index(*a, smallest);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->value == smallest)
			ft_push(b, a, 'b', 1);
		else
		{
			if (smallest_i < 4 / 2)
				ft_rotate(a, 'a', 1);
			else
				ft_reverse(a, 'a', 1);
		}
	}
	sort_three(a);
	ft_push(a, b, 'a', 1);
}

int	is_sorted(t_list *stack, int size)
{
	int	i;

	if (stack == NULL || size <= 1)
		return (1);
	i = 0;
	while (stack->next != NULL && i < size - 1)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}
