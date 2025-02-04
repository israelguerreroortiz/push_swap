/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:44:29 by iisraa11          #+#    #+#             */
/*   Updated: 2025/02/04 17:10:59 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	smallest_number(t_list **stack)
{
	t_list	*current;
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

int biggest_number(t_list **b, int size)
{
	t_list *current;
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

void ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int find_median(t_list **stack, int size)
{
	int *values;
	t_list *current;
	int median;
	int i;

	if (stack == NULL || *stack == NULL || size <= 0)
		return (0);
	values = malloc(sizeof(int) * size);
	if (values == NULL)
		return (0);
	current = *stack;
	i = 0;
	while (current != NULL && i < size)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	ft_sort_int_tab(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}

static int position(t_list **stack, int objetive)
{
	int count;
	t_list *current;

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

void push_b(t_list **a, t_list **b, int median)
{
	int sizea = ft_lstsize(*a);
	int biggest = biggest_number(a, sizea);
	while ((*a)->next != NULL)
	{
		if ((*a)->value < median)
		{
			ft_push(b, a, 'b');
			ft_rotate(b, 'b');
		}
		else if ((*a)->value == biggest)
			ft_rotate(a, 'a');
		else
			ft_push(b, a, 'b');
	}
}

void insertion_sort(t_list **a, t_list **b, int size)
{
	int biggest;
	int pos;
 
	while(*b != NULL)
	{
		biggest = biggest_number(b, size);
		pos = position(b, biggest);
		if ((*b)->value == biggest)
			ft_push(a, b, 'a');
		else
		{
			if (pos <= ft_lstsize(*b) / 2)
			{
				while((*b)->value != biggest)
					ft_rotate(b, 'b');	
			}
			else
				while((*b)->value != biggest)
					ft_reverse(b, 'b');
		}
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2 && (*a)->value > (*a)->next->value)
		ft_swap(a, 'a');
	else
	{
		int median = find_median(a, ft_lstsize(*a));
		push_b(a, b, median);
		while(*b != NULL)
			push_to_a(a, b);
	}
}
