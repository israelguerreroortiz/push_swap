/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:28:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/04 12:51:09 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	input_error(t_list **a, char *arg)
{
	int		i;
	long	nbr;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	nbr = ft_atol(arg);
	if ((ft_lst_include(a, nbr) == 1) || (nbr < INT_MIN || nbr > INT_MAX))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}

int	ft_lst_include(t_list **stack, int nbr)
{
	t_list	*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->value == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

void	add_to_node(t_list **stack, int nbr)
{
	t_list	*new;

	if (!stack)
	{
		*stack = ft_lstnew(nbr);
	}
	else
	{
		new = ft_lstnew(nbr);
		ft_lstadd_back(stack, new);
	}
}

void	print_node_value(int content)
{
	printf("%d\n", content);
}

void	ft_push(t_list **dest, t_list **src, char c)
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
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
	else
		return ;
}

void	ft_swap(t_list **stack, char c)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = *stack;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	else
		return ;
}

void	ft_swap_both(t_list **a, t_list **b)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	write(1, "ss\n", 3);
}

void	ft_rotate(t_list **stack, char c)
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
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	else
		return ;
}

void	ft_rotate_both(t_list **a, t_list **b)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	write(1, "rr", 2);
}

void	ft_reverse(t_list **stack, char c)
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
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	else
		return ;
}

void	ft_reverse_both(t_list **a, t_list **b)
{
	ft_reverse(a, 0);
	ft_reverse(b, 0);
	write(1, "rrr", 2);
}
void	free_stack(t_list **a)
{
	t_list *temp;

	while (*a != NULL)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	*a = NULL;
}
