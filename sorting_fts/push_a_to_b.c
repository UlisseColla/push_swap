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

int	find_push(t_stack *stack, int chunk_1, int chunk_2)
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

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, int flag, t_ls *ls)
{
	int	i;
	int	c_1;
	int	c_2;

	c_1 = 2;
	if (flag == CHUNK_1_4)
		c_1 = 1;
	c_2 = 5 - c_1;
	i = find_push(*stack_a, c_1, c_2);
	while (i > 0)
	{
		if (i > ft_list_size(stack_a) / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
		i--;
	}
	if ((*stack_a)->chunk == c_2)
		pb(stack_b, stack_a, 1, ls);
	else if ((*stack_a)->chunk == c_1)
	{
		pb(stack_b, stack_a, 1, ls);
		if (ft_list_size(stack_b) > 1)
			rb(stack_b, 1);
	}
}
