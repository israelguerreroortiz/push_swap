/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:17:25 by isrguerr          #+#    #+#             */
/*   Updated: 2025/01/15 17:11:36 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(stack_node *lst, void (*f)(int))
{
	stack_node	*current;

	current = lst;
	while (current != NULL)
	{
		f(current->value);
		current = current->next;
	}
}
