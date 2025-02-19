/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:01:32 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/19 17:59:10 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		return (sign * result);
	}
	return (0);
}

int	ft_lst_include(t_list **stack, int nbr)
{
	t_list	*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->value == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

int	input_error(t_list **a, char *arg)
{
	int		i;
	long	nbr;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	nbr = ft_atol(arg);
	if ((ft_lst_include(a, nbr) == 1) || (nbr < INT_MIN || nbr > INT_MAX))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}

void	add_to_node(t_list **stack, int nbr)
{
	t_list	*new;

	if (!stack)
	{
		*stack = ft_lstnew(nbr);
	}
	else
	{
		new = ft_lstnew(nbr);
		ft_lstadd_back(stack, new);
	}
}

void	stack_init(t_list **a, char **argv)
{
	int	i;
	int	nbr;

	i = 0;
	while (argv[i])
	{
		if (input_error(a, argv[i]) == 1)
		{
			ft_lstclear(a);
			exit(0);
		}
		else
		{
			nbr = ft_atoi(argv[i]);
			add_to_node(a, nbr);
		}
		i++;
	}
}
