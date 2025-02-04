/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/04 12:57:28 by iisraa11         ###   ########.fr       */
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
    return (abs(position));   
}

t_cost calculate_cost(t_list **a, t_list **b, int index_b, int median, int value) {
    t_cost cost;
    int sizeb = ft_lstsize(*b);
    cost.index_b = index_b;
    cost.value = value;
    if (index_b <= sizeb / 2)
        cost.cost_b = index_b;
    else
        cost.cost_b =  sizeb - index_b;
    cost.cost_a = find_insert_position_cost(a, (*b)->value);
    if (cost.cost_a && cost.cost_b)
    {
        if ((index_b <= sizeb / 2) && (cost.value < median))
            while(cost.cost_a > 0 && cost.cost_b > 0)
            {
                cost.rr++;
                cost.cost_a--;
                cost.cost_b--;
            }
        else if ((index_b > sizeb / 2) && (cost.value > median))
            while(cost.cost_a > 0 && cost.cost_b > 0)
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
    t_list *current = (*b);
    int index = 0;

    min_cost.total_cost = INT_MAX; // Inicializa con un coste muy alto
    while (current) 
    {
        current_cost = calculate_cost(a, b, index, median, current->value);
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
            min_cost.rr = current_cost.rr;
            min_cost.rrr = current_cost.rrr;
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
    int median = find_median(a, ft_lstsize(*a));
    int sizeb = ft_lstsize(*b);
    t_cost min_cost = find_min_cost(a, b, median);
    int temp = min_cost.cost_a + min_cost.rr + min_cost.rrr;
    
    while (min_cost.rr--)
        ft_rotate_both(a, b);
    while (min_cost.rrr--)
        ft_reverse_both(a, b);
    
    while (min_cost.cost_b--)
    {
        if (min_cost.index_b <= sizeb / 2)
            ft_rotate(b, 'b');
        else
            ft_reverse(b, 'b');
            
    }
    while (min_cost.cost_a--)
    {
        if (min_cost.value < median)
            ft_rotate(a, 'a');
        else
            ft_reverse(a, 'a');
            
    }
    ft_push(a, b, 'a');
    while(temp--)
    {
        if (min_cost.value < median)
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
