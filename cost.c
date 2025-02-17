/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:27 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/17 13:44:52 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int ft_biggest(t_list *list)
{
    int max;

    if (!list)
        return (INT_MIN);
    max = list->value;
    while (list)
    {
        if (list->value > max)
            max = list->value;
        list = list->next;
    }
    return (max);
}

int ft_smallest(t_list *list)
{
    int min;

    if (!list)
        return (INT_MAX);
    min = list->value;
    while (list)
    {
        if (list->value < min)
            min = list->value;
        list = list->next;
    }
    return (min);
}

int find_correct_pos(t_list *temp, int push, int biggest, int smallest)
{
    int i;

    i = 0;
    if (push > biggest)
    {
       while(temp->value != biggest)
       {
            temp = temp->next;
            i++;
       }
    }
    else
    {
        while(temp->value != smallest)
        {
            temp = temp->next;
            i++;   
        }  
    }
    return (i);
}

int	find_insert_position_cost(t_list *list, int push)
{
    t_list *temp;
    int biggest;
    int smallest;
    int i;

    temp = list;
    biggest = ft_biggest(list);
    smallest = ft_smallest(list);
    i = 0;
    if (push > list->value && push < ft_lstlast(list)->value)
        i = 0;
    else if (push > biggest || push < smallest)
       i = find_correct_pos(temp, push, biggest, smallest);
    else
    {
        while (temp)
        {
            if (temp->value < push)
                break;
            i++;
            temp = temp->next;
        }
    }
    return (i);
}

int search_index(t_list *list, int value)
{
    int i;
    
    i = 0;
    while(list)
    {
        if (list->value == value)
            break;
        list = list->next;
        i++;
    }
    return (i);
}

int	ft_case_rarb(t_list **a, t_list **b, t_cost *cost, int value)
{
    cost->ra = 0;
    cost->rb = 0;
    cost->rra = 0;
    cost->rrb = 0;
    cost->index_a = search_index(*a, value);
    cost->ra = cost->index_a;
    cost->rb = find_insert_position_cost(*b, value);
    return (cost->ra + cost->rb);
}

int	ft_case_rrarrb(t_list **a, t_list **b, t_cost *cost, int value)
{
    int sizea;
    
    cost->ra = 0;
    cost->rb = 0;
    cost->rra = 0;
    cost->rrb = 0;
    sizea = ft_lstsize(*a);
    cost->index_a = search_index(*a, value);
    cost->rra = sizea - cost->index_a;
    cost->rrb = ft_lstsize(*b) - find_insert_position_cost(*b, value);
    return (cost->rra + cost->rrb);
}

int	ft_case_rarrb(t_list **a, t_list **b, t_cost *cost, int value)
{
    cost->ra = 0;
    cost->rb = 0;
    cost->rra = 0;
    cost->rrb = 0;
    cost->index_a = search_index(*a, value);
    cost->ra = cost->index_a;
    cost->rrb = ft_lstsize(*b) - find_insert_position_cost(*b, value);
    return (cost->ra + cost->rrb);
}

int	ft_case_rrarb(t_list **a, t_list **b, t_cost *cost, int value)
{
    int sizea;

    cost->ra = 0;
    cost->rb = 0;
    cost->rra = 0;
    cost->rrb = 0;
    sizea = ft_lstsize(*a);
    cost->index_a = search_index(*a, value);
    cost->rra = sizea - cost->index_a;
    cost->rb = find_insert_position_cost(*b, value);
    return (cost->rra + cost->rb);
}

int	calculate_cost(t_list **a, t_list **b, t_cost **cost, int value)
{
    int		total_cost;

    total_cost = INT_MAX;
        if (total_cost > ft_case_rarb(a, b, *cost, value))
        {
            printf("value%d\n", value);
            total_cost = ft_case_rarb(a, b, *cost, value);
            printf("coste rarb %d para %d\n", total_cost, value);  
        }
        if (total_cost > ft_case_rrarrb(a, b, *cost, value))
        {
            total_cost = ft_case_rrarrb(a, b, *cost, value);
            printf("coste rrarrb %d para %d\n", total_cost, value);  
        }
        if (total_cost > ft_case_rarrb(a, b, *cost, value))
        {
            total_cost = ft_case_rarrb(a, b, *cost, value); 
            printf("coste rarrb %d para %d\n", total_cost, value); 
        }
        if (total_cost > ft_case_rrarb(a, b, *cost, value))
        {
            total_cost = ft_case_rrarb(a, b, *cost, value);
            printf("coste rrarb %d para %d\n", total_cost, value);  
        }
    (*cost)->total_cost = total_cost;
    printf("coste retornado%d para %d\n", total_cost, value);
    return (total_cost);
}

t_cost  *min_cost(t_list **a, t_list **b)
{
    t_list	*current;
    t_cost  *cost;
    //t_cost  *temp;
    
    current = *a;
   cost = malloc(sizeof(t_cost));
    if(!cost)
        return (NULL);
    /*temp = cost;
    temp->index_a = 0;
    temp->ra = 0;
    temp->rb = 0;
    temp->rra = 0;
    temp->rrb = 0;
    temp->total_cost= 0;
    temp->value= 0;
    cost->index_a = 0;
    cost->ra = 0;
    cost->rb = 0;
    cost->rra = 0;
    cost->rrb = 0;
    cost->value= 0;*/
    //cost->total_cost = INT_MAX;
    printf("current value%d\n", current->value);
    current = *b;
    printf("current value%d\n", current->value);
    /*while (current)
    {
        if (cost->total_cost > calculate_cost(a, b, &temp, current->value))
        {
            printf("temp ra %d para valor %d\n", temp->ra, current->value);
            printf("temp rb %d para valor %d\n", temp->rb, current->value);
            printf("temp rra %d para valor %d\n", temp->rra, current->value);
            printf("temp rrb %d para valor %d\n", temp->rrb, current->value);
            cost->ra = temp->ra;
            cost->rb = temp->rb;
            cost->rra = temp->rra;
            cost->rrb = temp->rrb;
            //if (cost.total_cost == 0)
                //return (cost);
        }
        current = current->next;
    }*/
    return (cost);
}
