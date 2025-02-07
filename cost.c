/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/07 18:47:26 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int find_insert_position_cost(t_list **b, int value, int median)
{
    int position = 0;
    t_list *current;
    
    if (value > median)
    {
        current = *b;
        while (current) 
        {
            if (current->value < value)
                break;
            position++;
            current = current->next;
        }
    }
    else
    {
        current = ft_lstlast(*b);
        //printf("Current value:%d\n", current->value);
        //printf("Current prev value:%d\n", current->prev->value);
        //printf("value:%d\n", value);
        while(current)
        {
            if (current->value > value)
                break;
            position++;
            current = current->prev;
        }
    }
    return (position);   
}

t_cost calculate_cost(t_list **a, t_list **b, int index_a, int median, int value) {
    t_cost cost;
    int sizea = ft_lstsize(*a);
    cost.rr = 0;
    cost.rrr = 0;
    cost.value = value;
    cost.index_a = index_a;
    if (index_a <= sizea / 2)
        cost.cost_a = index_a;
    else
        cost.cost_a =  sizea - index_a;
    cost.cost_b = find_insert_position_cost(b, value, median);
    //printf("Cost A: %d\n", cost.cost_a);
    if (cost.cost_a && cost.cost_b)
    {
        if ((cost.index_a <= sizea / 2) && (cost.value > median))
        {
            cost.rr++;
            cost.cost_a--;
            cost.cost_b--;
        }
        if ((cost.index_a > sizea / 2) && (cost.value < median))
        {
            cost.rrr++;
            cost.cost_a--;
            cost.cost_b--;
        }
    }
    cost.total_cost = cost.cost_b + cost.cost_a + cost.rr + cost.rrr;
    return (cost);
}

t_cost find_min_cost(t_list **a, t_list **b, int median) {
    t_cost min_cost;
    t_cost current_cost;
    t_list *current = (*a);
    int index = 0;
    
    min_cost.total_cost = INT_MAX;
    while (current) 
    {
        current_cost = calculate_cost(a, b, index, median, current->value);
        //printf("Current value: %d\n", current_cost.value);
        //printf("Current costA: %d\n", current_cost.cost_a);
        //printf("Current costB: %d\n", current_cost.cost_b);
        //printf("Current rr: %d\n", current_cost.rr);
        //printf("Current rrr: %d\n", current_cost.rrr);
        //printf("Current totalcost: %d\n\n", current_cost.total_cost);
        if (current_cost.total_cost < min_cost.total_cost)
        {
            min_cost.cost_a = current_cost.cost_a;
            min_cost.cost_b = current_cost.cost_b;
            min_cost.total_cost = current_cost.total_cost;
            min_cost.index_a = current_cost.index_a;
            min_cost.rr = current_cost.rr;
            min_cost.rrr = current_cost.rrr;
            min_cost.value = current->value;
            if (min_cost.total_cost == 0)
                return (min_cost);
        }
        //printf("Min_cost value: %d\n", min_cost.value);
        //printf("Min_cost costA: %d\n", min_cost.cost_a);
        //printf("Min_cost costB: %d\n", min_cost.cost_b);
        //printf("Min_cost rr: %d\n", min_cost.rr);
        //printf("Min_cost rrr: %d\n", min_cost.rrr);
        //printf("Min_cost total_cost: %d\n\n", min_cost.total_cost);
        current = current->next;
        index++;
    }
    return (min_cost);
}

