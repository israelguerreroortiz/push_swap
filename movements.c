/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:21:13 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/24 19:42:44 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_push(t_list **dest, t_list **src, char c, bool check)
{
	t_list	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = temp;
	*dest = temp;
	(*dest)->prev = NULL;
	if (check)
	{
		if (c == 'a')
			write(1, "pa\n", 3);
		else if (c == 'b')
			write(1, "pb\n", 3);
	}
}

void	ft_swap(t_list **stack, char c, bool check)
{
	t_list	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = *stack;
	if (check)
	{
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'b')
			write(1, "sb\n", 3);
	}
}

void	ft_rotate(t_list **stack, char c, bool check)
{
	t_list	*temp;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	temp->next = NULL;
	last->next = temp;
	temp->prev = last;
	if (check)
	{
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1, "rb\n", 3);
	}
}

void	ft_reverse(t_list **stack, char c, bool check)
{
	t_list	*last;
	t_list	*prev;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
	if (check)
	{
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1, "rrb\n", 4);
	}
}

void	ft_apply_rrb(t_list **b, int rrb)
{
	while (rrb > 0)
	{
		ft_reverse(b, 'b', 1);
		rrb--;
	}
}
