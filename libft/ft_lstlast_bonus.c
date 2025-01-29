/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:06:17 by isrguerr          #+#    #+#             */
/*   Updated: 2025/01/15 17:11:41 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack_node	*ft_lstlast(stack_node *lst)
{
	stack_node	*current;

	current = lst;
	while (current != NULL && current->next != NULL)
		current = current->next;
	return (current);
}
