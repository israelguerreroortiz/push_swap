/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:12:48 by isrguerr          #+#    #+#             */
/*   Updated: 2025/01/15 17:11:53 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

stack_node	*ft_lstnew(int content)
{
	stack_node	*node;

	node = malloc(sizeof(stack_node));
	if (!node)
		return (NULL);
	node->value = content;
	node->next = NULL;
	return (node);
}
