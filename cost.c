/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/01/30 19:56:45 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int find_insert_position_cost(stack_node **a, int value)
{
    int position = 0;
    stack_node *current = *a;
    int median = find_median(a, ft_lstsize(*a));
    while (current) 
    {
        if (current->value > value && (!current->next || current->next->value > value)) {  // A: 3, 5, 7  B: 4
            break;
        }
        position++;
        current = current->next;
    }
    if (value > median)
        position *= -1;
    return (position);
    
}

t_cost calculate_cost(stack_node **a, stack_node **b, int index_b) {
    t_cost cost;
    int size_b = ft_lstsize(*b);

    cost.index_b = index_b;
    cost.cost_b = (index_b <= size_b / 2) ? index_b : index_b - size_b; // Positivo: rb, Negativo: rrb
    cost.cost_a = find_insert_position_cost(a, (*b)->value); // Calcula dónde debería insertarse en a
    cost.total_cost = abs(cost.cost_b) + abs(cost.cost_a); // Coste total

    return (cost);
}

t_cost find_min_cost(stack_node **a, stack_node **b) {
    t_cost min_cost;
    t_cost current_cost;
    stack_node *current = (*b);
    int index = 0;

    min_cost.total_cost = INT_MAX; // Inicializa con un coste muy alto
    min_cost.value = current->value;
    while (current) {
        current_cost = calculate_cost(a, b, index);
        if (current_cost.total_cost < min_cost.total_cost)
        {
            min_cost = current_cost;
            min_cost.value = current->value;
        }
        current = current->next;
        index++;
    }

    return (min_cost);
}

void push_to_a(stack_node **a, stack_node **b)
{
    int rotated = 0;
    t_cost min_cost = find_min_cost(a, b);

    if (min_cost.index_b <= (ft_lstsize(*b) / 2))
    {
        while((*b)->value != min_cost.value)
            ft_rotate(b, 'b');  
    }
    else
    {
        while((*b)->value != min_cost.value)
            ft_reverse(b, 'b');        
    }
    int median = find_median(a, ft_lstsize(*a));
    int temp = min_cost.cost_a;
    if ((*b)->value < median)
    {
        while(min_cost.cost_a--)
        {
            ft_rotate(a, 'a');
            rotated++;
        }
    }
    else
    {
        while(min_cost.cost_a++)
        {
            ft_reverse(a, 'a');
            rotated++;
        }
    }
    ft_push(a, b, 'a');
    while(rotated--)
    {
        if (temp > 0)
            ft_reverse(a, 'a');
        else
            ft_rotate(a, 'a');
    }
}

void push_to_a_mod(stack_node **a, stack_node **b)
{
    int rotated = 0;
    t_cost min_cost = find_min_cost(a, b);
    printf("Value: %d\n", min_cost.value);
    printf("Index: %d\n", min_cost.index_b);
    printf("Cost A: %d\n", min_cost.cost_a);
    printf("Cost B: %d\n", min_cost.cost_b);
    printf("Total cost: %d\n", min_cost.total_cost);
    if (min_cost.index_b <= (ft_lstsize(*b) / 2))
    {
        while((*b)->value != min_cost.value)
            ft_rotate(b, 'b');  
    }
    else
    {
        while((*b)->value != min_cost.value)
            ft_reverse(b, 'b');        
    }
    int median = find_median(a, ft_lstsize(*a));
    printf("Median: %d\n", median);
    int temp = min_cost.cost_a;
    if ((*b)->value < median)
    {
        while(min_cost.cost_a--)
        {
            ft_rotate(a, 'a');
            rotated++;
        }
    }
    else
    {
        while(min_cost.cost_a++)
        {
            ft_reverse(a, 'a');
            rotated++;
        }
    }
    ft_push(a, b, 'a');
    while(rotated--)
    {
        if (temp > 0)
            ft_reverse(a, 'a');
        else
            ft_rotate(a, 'a');
    }
}
