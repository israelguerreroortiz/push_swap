/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:54:31 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/09 17:21:34 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int is_sorted(t_list *stack, int size)
{
	int i;

	if (stack == NULL || size <= 1)
		return (1);
	i = 0;
	while (stack->next != NULL && i < size - 1)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

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
	printf("Pila B: \n");
	ft_lstiter(b, print_node_value);
	printf("Pila A: \n");
	ft_lstiter(a, print_node_value);
    free_stack(&a);
    return (0);
}
