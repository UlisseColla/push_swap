/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:16:10 by aconciar          #+#    #+#             */
/*   Updated: 2026/10/11 15:43:32 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_error(t_node **stack_a, t_node **stack_b, int i, char *line)
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

static char	*free_and_return(char *line_to_free, char *line_to_return)
{
	free(line_to_free);
	return (line_to_return);
}

static char	*ft_check_operations(t_stack *a, t_stack *b, char *line)
{
	if (ft_strncmp(line, "pa", 2) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(line, "pb", ft_strlen(line) - 1) == 0)
		pb(b, a, 0);
	else if (ft_strncmp(line, "sa", ft_strlen(line) - 1) == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb", ft_strlen(line) - 1) == 0)
		sb(b, 0);
	else if (ft_strncmp(line, "ss", ft_strlen(line) - 1) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(line, "ra", ft_strlen(line) - 1) == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb", ft_strlen(line) - 1) == 0)
		rb(b, 0);
	else if (ft_strncmp(line, "rr", ft_strlen(line) - 1) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(line, "rra", ft_strlen(line) - 1) == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb", ft_strlen(line) - 1) == 0)
		rrb(b, 0);
	else if (ft_strncmp(line, "rrr", ft_strlen(line) - 1) == 0)
		rrr(a, b, 0);
	else
		ft_error(a->stack, b->stack, 1, line);
	return (free_and_return(line, get_next_line(0)));
}

static void	ft_check(t_stack *a, t_stack *b, char *line)
{
	while (line && *line != '\n')
		line = ft_check_operations(a, b, line);
	free(line);
	if (check_order(a->stack) == 0)
		ft_error(a->stack, b->stack, 0, line);
	else if (*b->stack)
		ft_error(a->stack, b->stack, 0, line);
	else
	{
		write(1, "OK\n", 3);
		ft_free_list(*b->stack);
	}
}

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;
	t_stack	a;
	t_stack	b;
	char	*line;

	head_a = NULL;
	head_b = NULL;
	a = (t_stack){&head_a, 0};
	b = (t_stack){&head_b, 0};
	if (initialize_stack(&a, argv, argc) > 0)
		return (1);
	line = get_next_line(0);
	if (!line && check_order(a.stack) == 0)
		ft_error(a.stack, b.stack, 1, line);
	else if (!line && check_order(a.stack) == 1)
		write(1, "OK\n", 3);
	else
		ft_check(&a, &b, line);
	ft_free_list(*a.stack);
	ft_free_list(*b.stack);
	return (0);
}
