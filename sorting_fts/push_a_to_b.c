/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:13:37 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/04 17:39:03 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_push(t_node *stack, int chunk_1, int chunk_2)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->chunk == chunk_1 || stack->chunk == chunk_2)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	push_a_to_b(t_stack *stack_a, t_stack *stack_b, int c_1, int c_2)
{
	int		i;
	t_node	*a;
	t_node	*b;

	a = stack_a->stack;
	b = stack_b->stack;
	i = find_push(a, c_1, c_2);
	while (i > 0)
	{
		if (i > stack_a->size / 2)
			rra(&a, 1);
		else
			ra(&a, 1);
		i--;
	}
	if (a->chunk == c_2)
		pb(stack_b, stack_a, 1, ls);
	else if (a->chunk == c_1)
	{
		pb(stack_b, stack_a, 1, ls);
		if (stack_b->size > 1)
			rb(stack_b, 1);
	}
}
