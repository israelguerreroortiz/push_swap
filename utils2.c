/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:01:13 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/19 18:10:07 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_biggest(t_list *list)
{
	int	max;

	if (!list)
		return (INT_MIN);
	max = list->value;
	while (list)
	{
		if (list->value > max)
			max = list->value;
		list = list->next;
	}
	return (max);
}

int	ft_smallest(t_list *list)
{
	int	min;

	if (!list)
		return (INT_MAX);
	min = list->value;
	while (list)
	{
		if (list->value < min)
			min = list->value;
		list = list->next;
	}
	return (min);
}

int	ft_case_rarb(t_list **a, t_list **b, t_cost *cost, int value)
{
	cost->ra = 0;
	cost->rb = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rr = 0;
	cost->rrr = 0;
	cost->index_a = search_index(*a, value);
	cost->ra = cost->index_a;
	cost->rb = find_insert_position_cost(*b, value);
	while ((cost->ra > 0) && (cost->rb > 0))
	{
		cost->ra--;
		cost->rb--;
		cost->rr++;
	}
	return (cost->ra + cost->rb + cost->rr);
}

int	find_correct_pos(t_list *temp, int biggest)
{
	int	i;

	i = 0;
	while (temp->value != biggest)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_insert_position_cost(t_list *list, int push)
{
	t_list	*temp;
	int		biggest;
	int		smallest;
	int		i;

	temp = list;
	biggest = ft_biggest(list);
	smallest = ft_smallest(list);
	i = 0;
	if (push > list->value && push < ft_lstlast(list)->value)
		i = 0;
	else if (push > biggest || push < smallest)
		i = find_correct_pos(temp, biggest);
	else
	{
		while (temp)
		{
			i++;
			if (temp->next && push < temp->value && push > temp->next->value)
				break ;
			temp = temp->next;
		}
	}
	return (i);
}
