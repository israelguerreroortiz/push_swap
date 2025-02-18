/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/18 18:02:54 by isrguerr         ###   ########.fr       */
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

int	find_insert_position_cost_a(t_list *list, int push)
{
	t_list	*temp;
	int i;

	i = 0;
	temp = list;
	while(temp)
	{
		i++;
		if (temp->next && push > temp->value && push < temp->next->value)
			break;
		temp = temp->next;
	}
	return (i);
}

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
	//printf("valor de ra%d y rb%d previo a calcular rr para valor %d\n", cost->ra, cost->rb, value);
	while((cost->ra > 0) && (cost->rb > 0))
	{
		cost->ra--;
		cost->rb--;	
		cost->rr++;
	}
	return (cost->ra + cost->rb + cost->rr);
}

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
	//printf("valor de rra%d y rrb%d previo a calcular rrr para valor %d\n", cost->rra, cost->rrb, value);
	while(cost->rra > 0 && cost->rrb > 0)
	{
		cost->rra--;
		cost->rrb--;	
		cost->rrr++;
	}
	return (cost->rra + cost->rrb + cost->rrr);
}

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
	return (total_cost);
}

t_cost	*min_cost(t_list **a, t_list **b)
{
	t_list	*current;
	t_cost	*cost;
	t_cost	*temp;
	int		value;

	value = 0;
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
