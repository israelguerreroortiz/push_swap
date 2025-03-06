/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrguerr <isrguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:28:38 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/19 17:58:46 by isrguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_apply_rr(t_list **a, t_list **b, int rr)
{
	while (rr > 0)
	{
		ft_rotate_both(a, b);
		rr--;
	}
}

void	ft_apply_rrr(t_list **a, t_list **b, int rrr)
{
	while (rrr > 0)
	{
		ft_reverse_both(a, b);
		rrr--;
	}
}

void	ft_apply_ra(t_list **a, int ra)
{
	while (ra > 0)
	{
		ft_rotate(a, 'a');
		ra--;
	}
}

void	ft_apply_rb(t_list **b, int rb)
{
	while (rb > 0)
	{
		ft_rotate(b, 'b');
		rb--;
	}
}

void	ft_apply_rra(t_list **a, int rra)
{
	while (rra > 0)
	{
		ft_reverse(a, 'a');
		rra--;
	}
}
