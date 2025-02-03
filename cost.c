/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/03 17:59:17 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int find_insert_position_cost(t_list **a, int value)
{
    int position = 0;
    t_list *current;
    int median = find_median(a, ft_lstsize(*a));
    if (value < median)
    {
        current = *a;
        while (current) 
        {
        if (current->value > value && (!current->next || current->next->value > value))
            break;
        position++;
        current = current->next;
        }
    }
    else
    {
        current = ft_lstlast(*a);
        while(current)
        {
            if (current->value < value && (!current->prev || current->prev->value < value))
                break;
            position--;
            current = current->prev;
        }
    }
    return (position);   
}

t_cost calculate_cost(t_list **a, t_list **b, int index_b, int median, int sizeb) {
    t_cost cost;
    int size_b = ft_lstsize(*b);
    cost.index_b = index_b;
    if (index_b <= size_b / 2)
        cost.cost_b = index_b;
    else
        cost.cost_b =  size_b - index_b;
    cost.cost_a = find_insert_position_cost(a, (*b)->value);
    cost.total_cost = abs(cost.cost_b) + abs(cost.cost_a);
    return (cost);
}

t_cost find_min_cost(t_list **a, t_list **b, int median, int sizeb) {
    t_cost min_cost;
    t_cost current_cost;
    t_list *current = (*b);
    int index = 0;

    min_cost.total_cost = INT_MAX; // Inicializa con un coste muy alto
    while (current) 
    {
        current_cost = calculate_cost(a, b, index, median, sizeb);
        current_cost.value = current->value;
        //printf("Valor current: %d\n", current_cost.value);
        //printf("Coste A current: %d\n", current_cost.cost_a);     
        //printf("Coste B current: %d\n", current_cost.cost_b);
        //printf("Coste Total current: %d\n", current_cost.total_cost);
        //printf("Index current: %d\n\n", current_cost.index_b);
        if (current_cost.total_cost < min_cost.total_cost)
        {
            min_cost.cost_a = current_cost.cost_a;
            min_cost.cost_b = current_cost.cost_b;
            min_cost.total_cost = current_cost.total_cost;
            min_cost.value = current_cost.value;
            min_cost.index_b = current_cost.index_b;
            if (min_cost.total_cost == 0)
                return (min_cost);
        }
        //printf("Valor min_cost: %d\n", min_cost.value);
        //printf("Coste A min_cost: %d\n", min_cost.cost_a);     
        //printf("Coste B min_cost: %d\n", min_cost.cost_b);
        //printf("Coste Total min_cost: %d\n", min_cost.total_cost);
        //printf("Index min_cost: %d\n\n", min_cost.index_b);
        current = current->next;
        index++;
    }
    return (min_cost);
}

void push_to_a(t_list **a, t_list **b)
{
    int rotated = 0;
    int sizeb = ft_lstsize(*b);
    int median = find_median(a, ft_lstsize(*a));
    t_cost min_cost = find_min_cost(a, b, median, sizeb);
    
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
        rotated++;
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

/*void push_to_a_mod(t_list **a, t_list **b)
{
    int rotated = 0;
    t_cost min_cost = find_min_cost(a, b);
    int median = find_median(a, ft_lstsize(*a));
    int temp = min_cost.cost_a;
    
    if (min_cost.index_b <= (ft_lstsize(*b) / 2))
    {
        if (min_cost.cost_a > 0 && (min_cost.value < median))
        {
            while (min_cost.cost_b > 0 && min_cost.cost_a > 0)
            {
                ft_rotate_both(a, b);
                min_cost.cost_b--;
                min_cost.cost_a--;
                rotated++;
            }
        } 
        while((*b)->value != min_cost.value)
            ft_rotate(b, 'b');
    }
    else
    {
        if (min_cost.cost_a < 0 && min_cost.value > median)
            while((min_cost.cost_a < 0) && min_cost.cost_b)
            {
                ft_reverse_both(a, b);
                min_cost.cost_a++;
                min_cost.cost_b--;
                rotated++;
            }
        while((*b)->value != min_cost.value)
            ft_reverse(b, 'b');
    }
    
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
        rotated++;
    }
    
    ft_push(a, b, 'a');
    
    while(rotated--)
    {
        if (temp > 0)
            ft_reverse(a, 'a');
        else
            ft_rotate(a, 'a');
    }
}*/
