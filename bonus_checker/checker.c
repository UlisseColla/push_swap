/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:16:10 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/10 16:02:00 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(t_stack **stack_a, t_stack **stack_b, int i, char *line)
{
	if (line)
		free(line);
	ft_free_list(*stack_a);
	ft_free_list(*stack_b);
	if (i == 1)
		write(2, "Error\n", 6);
	else
		write(1, "KO\n", 3);
	exit (1);
}

char	*free_and_return(char *line_to_free, char *line_to_return)
{
	free(line_to_free);
	return (line_to_return);
}

char	*ft_check_operations(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "pa", 2) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pb", ft_strlen(line) - 1) == 0)
		pb(stack_b, stack_a, 0);
	else if (ft_strncmp(line, "sa", ft_strlen(line) - 1) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(line, "sb", ft_strlen(line) - 1) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(line, "ss", ft_strlen(line) - 1) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "ra", ft_strlen(line) - 1) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(line, "rb", ft_strlen(line) - 1) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(line, "rr", ft_strlen(line) - 1) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "rra", ft_strlen(line) - 1) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(line, "rrb", ft_strlen(line) - 1) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(line, "rrr", ft_strlen(line) - 1) == 0)
		rrr(stack_a, stack_b, 0);
	else
		ft_error(stack_a, stack_b, 1, line);
	return (free_and_return(line, get_next_line(0)));
}

void	ft_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	while (line && *line != '\n')
		line = ft_check_operations(stack_a, stack_b, line);
	free(line);
	if (check_order(stack_a) == 0)
		ft_error(stack_a, stack_b, 0, line);
	else if (*stack_b)
		ft_error(stack_a, stack_b, 0, line);
	else
	{
		write(1, "OK\n", 3);
		ft_free_list(*stack_b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (initialize_stack(&a, argv, argc) > 0)
		return (1);
	line = get_next_line(0);
	if (!line && check_order(&a) == 0)
		ft_error(&a, &b, 1, line);
	else if (!line && check_order(&a) == 1)
		write(1, "OK\n", 3);
	else
		ft_check(&a, &b, line);
	ft_free_list(a);
	ft_free_list(b);
	return (0);
}
