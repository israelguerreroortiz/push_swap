/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:44:29 by iisraa11          #+#    #+#             */
/*   Updated: 2025/02/06 18:56:48 by isrguerr         ###   ########.fr       */
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

void	big_sort(t_list **a, t_list **b)
{
    int median = find_median(b, ft_lstsize(*b));
    int sizea = ft_lstsize(*a);
    t_cost min_cost = find_min_cost(a, b, median);
    int rotated = 0;
    
    while (min_cost.rr--)
    {
        ft_rotate_both(a, b);
        rotated++;
    }
        
    while (min_cost.rrr--)
    {
        rotated++;
        ft_reverse_both(a, b);
    }
    
    while (min_cost.cost_a--)
    {
        if (min_cost.index_a <= sizea / 2)
            ft_rotate(a, 'a');
        else
            ft_reverse(a, 'a');
            
    }
    while (min_cost.cost_b--)
    {
        if (min_cost.value > median)
        {
            ft_rotate(a, 'a');
            rotated++;
        }
        else
        {
            ft_reverse(a, 'a');
            rotated++;
        }
    }
    ft_push(a, b, 'a');
    if (min_cost.value < median)
        rotated++;
    while(rotated--)
    {
        if (min_cost.value > median)
            ft_reverse(a, 'a');
        else
            ft_rotate(a, 'a');
    }
}

//void ()

void    sort_stack(t_list **a, t_list **b)
{
    int size = ft_lstsize(*a);
    
    if (size == 2)
        ft_swap(a, 'a');
    //else if (size == 3)
        //sort_three(a);
    //else if (size <= 5)
        //sort_five(a, b);
    else
	{
		ft_push(b, a, 'b');
		ft_push(b, a, 'b');
		if ((*b)->value < (*b)->next->value)
			ft_swap(b, 'b');
		big_sort(a, b);
		//sort_three(a);
		//push_to_a(a, b);
	}
}
