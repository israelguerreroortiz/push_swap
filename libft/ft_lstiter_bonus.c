/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:17:25 by isrguerr          #+#    #+#             */
/*   Updated: 2025/01/25 13:45:58 by iisraa11         ###   ########.fr       */
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
