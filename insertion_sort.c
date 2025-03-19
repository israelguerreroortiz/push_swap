/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:11:06 by isrguerr          #+#    #+#             */
/*   Updated: 2025/03/19 19:19:32 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void insertion_sort(t_list **a, t_list **b)
{
    int smallest;
    int smallest_index;
    
    smallest = ft_smallest(*a);
    smallest_index = search_index(*a, smallest);
    while(*a)
    {
        if (smallest_index < ft_lstsize(*a) / 2)
            while((*a)->value != smallest)
                ft_rotate(a, 'a');
        else
            while((*a)->value != smallest)
                ft_reverse(a, 'a');
        ft_push(b, a, 'b');
        smallest = ft_smallest(*a);
        smallest_index = search_index(*a, smallest);
    }
    while(*b)
        ft_push(a, b, 'a');
}
