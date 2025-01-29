/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/01/29 18:16:26 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int find_insert_position_cost(stack_node *a, int value)
{
    int position = 0;
    stack_node *current = a;

    while (current) {
        if (current->value > value && (!current->next || current->next->value < value)) {
            break;
        }
        position++;
        current = current->next;
    }

    return (position <= ft_lstsize(a) / 2) ? position : position - ft_lstsize(a);
}

t_cost calculate_cost(stack_node *a, stack_node *b, int index_b) {
    t_cost cost;
    int size_b = ft_lstsize(b);

    cost.index_b = index_b;
    cost.cost_b = (index_b <= size_b / 2) ? index_b : index_b - size_b; // Positivo: rb, Negativo: rrb
    cost.cost_a = find_insert_position_cost(a, b->value); // Calcula dónde debería insertarse en a
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
        current_cost = calculate_cost(*a, *b, index);
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
        while((*b)->value != min_cost.value)
            ft_rotate(b, 'b');
    else
        while((*b)->value != min_cost.value)
            ft_reverse(b, 'b');
    if (min_cost.index_b <= (ft_lstsize(*b) / 2))
    {
        while(min_cost.cost_a--)
        {
            ft_rotate(a, 'a');
            rotated++;
        }
    }
    else
    {
        while(min_cost.cost_a--)
        {
            ft_reverse(a, 'a');
            rotated++;
        }
    }
    ft_push(a, b, 'a');
    while(rotated--)
    {
        if (min_cost.index_b <= (ft_lstsize(*b) / 2))
            ft_rotate(a, 'a');
        else
            ft_reverse(a, 'a');
    }
}
