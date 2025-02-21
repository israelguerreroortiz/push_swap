/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisraa11 <iisraa11@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:47:47 by isrguerr          #+#    #+#             */
/*   Updated: 2025/02/21 11:46:30 by iisraa11         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

static char	*ft_check_mov(t_list **a, t_list **b, char *line)
{
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_push(a, b, 'a');
    else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_push(b, a, 'b');
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_rotate(a, 'a');
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rotate(b, 'b');
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rotate_both(a, b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		ft_reverse(a, 'a');
    else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		ft_reverse(b, 'b');
    else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
		ft_reverse_both(a, b);
    else if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_swap(a, 'a');
    else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_swap(b, 'b');
    else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_swap_both(a, b);
    else
        return (NULL);
    return(get_next_line(0));
}

static void	ft_check_file(t_list **a, t_list **b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = ft_check_mov(a, b, line);
		free(temp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!is_sorted(*a, ft_lstsize(*a)))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	char *line;

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
	line = get_next_line(0);
	if (!line && !is_sorted(a, ft_lstsize(a)))
		write(1, "KO\n", 3);
	else if (!line && is_sorted(a, ft_lstsize(a)))
		write(1, "OK\n", 3);
	else
		ft_check_file(&a, &b, line);
	ft_lstclear(&a);
    ft_lstclear(&b);
	return (0);
}