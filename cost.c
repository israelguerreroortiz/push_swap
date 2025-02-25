/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/25 15:57:46 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

/*
	This function checks how many rar and rrb are
	needed to put the number in the right position in B.
	If there are rra and rrb, these variables are decreased
	and rrr is increased.
*/
int	ft_case_rrarrb(t_list **a, t_list **b, t_cost *cost, int value)
{
	int	sizea;

	cost->ra = 0;
	cost->rb = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rr = 0;
	cost->rrr = 0;
	sizea = ft_lstsize(*a);
	cost->index_a = search_index(*a, value);
	cost->rra = sizea - cost->index_a;
	cost->rrb = ft_lstsize(*b) - find_insert_position_cost(*b, value);
	while (cost->rra > 0 && cost->rrb > 0)
	{
		cost->rra--;
		cost->rrb--;
		cost->rrr++;
	}
	return (cost->rra + cost->rrb + cost->rrr);
}
/*
	This function checks how many ra and rrb are
	needed to put the number in the right position
	in B.
*/
int	ft_case_rarrb(t_list **a, t_list **b, t_cost *cost, int value)
{
	cost->ra = 0;
	cost->rb = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rr = 0;
	cost->rrr = 0;
	cost->index_a = search_index(*a, value);
	cost->ra = cost->index_a;
	cost->rrb = ft_lstsize(*b) - find_insert_position_cost(*b, value);
	return (cost->ra + cost->rrb);
}
/*
	This function checks how many rra and rb are
	needed to put the number in the right position
	in B.
*/
int	ft_case_rrarb(t_list **a, t_list **b, t_cost *cost, int value)
{
	int	sizea;

	cost->ra = 0;
	cost->rb = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rr = 0;
	cost->rrr = 0;
	sizea = ft_lstsize(*a);
	cost->index_a = search_index(*a, value);
	cost->rra = sizea - cost->index_a;
	cost->rb = find_insert_position_cost(*b, value);
	return (cost->rra + cost->rb);
}
/*
	Calculate_cost check the cheapest form of a number to be
	in his right position in B.
*/
int	calculate_cost(t_list **a, t_list **b, t_cost *cost, int value)
{
	t_cost	*temp;
	int		total_cost;

	temp = malloc(sizeof(t_cost));
	if (!temp)
		return (0);
	total_cost = INT_MAX;
	if (total_cost > ft_case_rarb(a, b, temp, value))
		total_cost = ft_case_rarb(a, b, cost, value);
	if (total_cost > ft_case_rrarrb(a, b, temp, value))
		total_cost = ft_case_rrarrb(a, b, cost, value);
	if (total_cost > ft_case_rarrb(a, b, temp, value))
		total_cost = ft_case_rarrb(a, b, cost, value);
	if (total_cost > ft_case_rrarb(a, b, temp, value))
		total_cost = ft_case_rrarb(a, b, cost, value);
	cost->total_cost = total_cost;
	free(temp);
	return (total_cost);
}
/*
	Min_cost function compare all the numbers in a
	with his respectives costs and return the number
	with less cost.
*/
t_cost	*min_cost(t_list **a, t_list **b)
{
	t_list	*current;
	t_cost	*cost;
	t_cost	*temp;

	current = *a;
	cost = malloc(sizeof(t_cost));
	temp = malloc(sizeof(t_cost));
	cost->total_cost = INT_MAX;
	while (current)
	{
		if (cost->total_cost > calculate_cost(a, b, temp, current->value))
			*cost = *temp;
		current = current->next;
	}
	free(temp);
	return (cost);
}
