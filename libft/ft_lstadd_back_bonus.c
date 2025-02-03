/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:19:46 by isrguerr          #+#    #+#             */
/*   Updated: 2025/01/31 13:11:59 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(stack_node **lst, stack_node *new)
{
	stack_node	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}
