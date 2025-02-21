/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:54:31 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/21 11:37:57 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], 32);
		stack_init(&a, argv);
	}
	else
		stack_init(&a, argv + 1);
	if (!is_sorted(a, ft_lstsize(a)))
		sort_stack(&a, &b);
	ft_lstclear(&a);
	return (0);
}
