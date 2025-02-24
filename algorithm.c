/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:44:29 by iisraa11          #+#    #+#             */
/*   Updated: 2025/02/24 19:34:24 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	big_sort(t_list **a, t_list **b)
{
	t_cost	*cost;

	cost = NULL;
	cost = min_cost(a, b);
	if (cost->rr > 0)
		ft_apply_rr(a, b, cost->rr);
	if (cost->rrr > 0)
		ft_apply_rrr(a, b, cost->rrr);
	if (cost->ra > 0)
		ft_apply_ra(a, cost->ra);
	if (cost->rb > 0)
		ft_apply_rb(b, cost->rb);
	if (cost->rra > 0)
		ft_apply_rra(a, cost->rra);
	if (cost->rrb > 0)
		ft_apply_rrb(b, cost->rrb);
	ft_push(b, a, 'b', 1);
	free(cost);
}

void	push_to_a(t_list **a, t_list **b)
{
	int	objetive;

	objetive = find_insert_position_cost_a(*a, (*b)->value);
	if (objetive)
		while ((*a)->value != objetive)
			ft_reverse(a, 'a', 1);
	ft_push(a, b, 'a', 1);
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		ft_swap(a, 'a', 1);
	else if (first > second && second > third && first > third)
	{
		ft_swap(a, 'a', 1);
		ft_reverse(a, 'a', 1);
	}
	else if (first > second && second < third && first > third)
		ft_rotate(a, 'a', 1);
	else if (first < second && second > third && first < third)
	{
		ft_swap(a, 'a', 1);
		ft_rotate(a, 'a', 1);
	}
	else if (first < second && second > third && first > third)
		ft_reverse(a, 'a', 1);
}

void	sort_five(t_list **a, t_list **b)
{
	int	smallest;
	int	smallest_i;

	smallest = ft_smallest(*a);
	smallest_i = search_index(*a, smallest);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->value == smallest)
		{
			ft_push(b, a, 'b', 1);
			smallest = ft_smallest(*a);
			smallest_i = search_index(*a, smallest);
		}
		else if (smallest_i < 5 / 2)
			ft_rotate(a, 'a', 1);
		else
			ft_reverse(a, 'a', 1);
	}
	sort_three(a);
	if ((*b)->value < (*b)->next->value)
		ft_swap(b, 'b', 1);
	ft_push(a, b, 'a', 1);
	ft_push(a, b, 'a', 1);
}

void	sort_stack(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		ft_swap(a, 'a', 1);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
	{
		ft_push(b, a, 'b', 1);
		ft_push(b, a, 'b', 1);
		while (ft_lstsize(*a) > 3)
			big_sort(a, b);
		sort_three(a);
		while (*b != NULL)
			push_to_a(a, b);
		while ((*a)->value > ft_lstlast(*a)->value)
			ft_rotate(a, 'a', 1);
	}
}
