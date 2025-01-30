/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:44:29 by iisraa11          #+#    #+#             */
/*   Updated: 2025/01/30 19:47:40 by isrguerr         ###   ########.fr       */
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

void push_b(stack_node **a, stack_node **b, int median)
{
	while (*a != NULL)
	{
		if ((*a)->value < median)
		{
			ft_push(b, a, 'b');
			ft_rotate(b, 'b');
		}
		else
		{
			ft_push(b, a, 'b');
			if ((*b)->next != NULL && (*b)->value < (*b)->next->value)
				ft_swap(b, 'b');	
		}
	}
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
	if (ft_lstsize(*a) == 2 && (*a)->value > (*a)->next->value)
		ft_swap(a, 'a');
	else
	{
		int median = find_median(a, ft_lstsize(*a));
		push_b(a, b, median);
		push_to_a(a, b);
		push_to_a(a, b);
		push_to_a(a, b);
		push_to_a(a, b);
		push_to_a(a, b);
		push_to_a(a, b);
		push_to_a(a, b);
		push_to_a(a, b);
		push_to_a(a, b);
		push_to_a(a, b);
		/*Probar con ./push_swap 552 2800 9075 7258 2710 7263 7841 -1796 2508 1232 6978 7812 2305 5424 3511 9374 5131 -633 8082 612 -1420 2425 4145 -1897 1621 2073 6136 8267 9567 9655 5303 -612 529 6656 -1130 -711 2498 1285 5104 3507 7040 -958 6090 -1960 -1441 -1076 2204 4729 4451 9438 1705 8512 -983 3344 6883 7626 7614 3285 6634 -942 722 9932 6380 9597 -698 4109 -1775 687 -458 447 2732 9758 7396 9633 -1984 -1433 20 3742 6577 5338 6235 8706 9988 -1517 425 9158 4596 4923 2909 280 2585 4827 6398 389 7839 4101 -492 8054 8891 -891*/
	}
}
