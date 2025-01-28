/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:44:29 by iisraa11          #+#    #+#             */
/*   Updated: 2025/01/28 13:50:05 by iisraa11         ###   ########.fr       */
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

int tab_size(int asize)
{
	int size;

	size = 0;
	while (asize > 2)
	{
		asize /= 2;
		size++;
	}
	return (size);
}

void insertion_sort(stack_node **a, stack_node **b, int size)
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

void	sort_stack(stack_node **a, stack_node **b)
{
	int asize;
	int tabsize;
	int *tab;
	int i;
	
	asize = ft_lstsize(*a);
	tabsize = tab_size(asize);
	tab = malloc(sizeof(int) * tabsize);
	while (asize > 2)
	{
		tabsize--;
		tab[tabsize] = quick_sort(a, b, asize);
		asize = ft_lstsize(*a);
	}
	if ((*a)->next != NULL && (*a)->value > (*a)->next->value)
		ft_swap(a, 'a');	
	i = 0;
	while (tab[i])
	{
		if (tab[i + 1] == 0)
			break;
		sort_b(a, b, tab[i]);
		i++;
	}
	insertion_sort(a, b, tab[i]);
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

int find_median(stack_node **stack, int size)
{
	int *values;
	stack_node *current;
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

int	quick_sort(stack_node **a, stack_node **b, int size)
{
	int	median;
	int pushed;

	if (size <= 1 || a == NULL || *a == NULL)
		return (0);
	median = find_median(a, size);
	pushed = 0;
	while (size--)
	{
		if ((*a)->value < median)
		{
			ft_push(b, a, 'b');
			pushed++;	
		}
		else
			ft_rotate(a, 'a');
	}
	return (pushed);
}
void divide_b(stack_node **b, stack_node **a, int size) 
{
	int biggest;
	int rotate;
	int pushed;
	int i;

	i = 0;	
	pushed = 0;
	rotate = 0;
	while (i < size)
	{
		biggest = biggest_number(b, size);
		if ((*b)->value == biggest)
		{
			ft_push(a, b, 'a');
			pushed++;	
		}
		else if ((*b)->next->value == biggest)
		{
			ft_swap(b, 'b');
			ft_push(a, b, 'a');
			pushed++;
		}
		else
		{
			ft_rotate(b, 'b');
			rotate++;	
		}
		i++;
	}
	while(rotate--)
		ft_reverse(b, 'b');
	if (pushed < size)
		divide_b(b, a, size - pushed);
}

int is_sorted(stack_node *stack, int size)
{
	int i;

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

void sort_b(stack_node **a, stack_node **b, int chunksize)
{
	if (is_sorted(*b, chunksize))
	{
		while(chunksize--)
			ft_push(a, b, 'a');
	}
	else
	{
		if (chunksize == 2)
		{
			ft_swap(b, 'b');
			ft_push(a, b, 'a');
			ft_push(a, b, 'a');
		}
		else
			divide_b(b, a, chunksize);
	}
}