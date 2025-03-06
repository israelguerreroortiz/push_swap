/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:28:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/19 18:34:46 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	search_index(t_list *list, int value)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->value == value)
			break ;
		list = list->next;
		i++;
	}
	return (i);
}

void	ft_swap_both(t_list **a, t_list **b)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	write(1, "ss\n", 3);
}

void	ft_rotate_both(t_list **a, t_list **b)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	write(1, "rr\n", 3);
}

void	ft_reverse_both(t_list **a, t_list **b)
{
	ft_reverse(a, 0);
	ft_reverse(b, 0);
	write(1, "rrr\n", 4);
}

int	find_insert_position_cost_a(t_list *list, int push)
{
	t_list	*current;
	int		result;
	int		temp;
	int		value;

	current = list;
	result = INT_MAX;
	temp = 0;
	value = 0;
	while (current)
	{
		if (push < current->value)
		{
			temp = current->value - push;
			if (result > temp)
			{
				result = current->value - push;
				value = current->value;
			}
		}
		current = current->next;
	}
	return (value);
}
