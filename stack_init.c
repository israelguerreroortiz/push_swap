/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:01:32 by isrguerr          #+#    #+#             */
/*   Updated: 2025/01/15 16:27:47 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void stack_init(stack_node **a, char **argv)
{
    int i;
    int nbr;
    
    i = 0;
    while(argv[i])
    {
        if (input_error(a ,argv[i]) == 1)
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
