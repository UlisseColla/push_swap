/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_and_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:17 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/06 18:14:58 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a, int i)
{
	t_node	*node;
	t_node	**stack;

	stack = a->stack;
	if (a->size < 2)
		return ;
	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int i)
{
	t_node	*node;
	t_node	**stack;

	stack = b->stack;
	if (b->size < 2)
		return ;
	node = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	node->next = *stack;
	*stack = node;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int i)
{
	t_node	**stack_a;
	t_node	**stack_b;

	stack_a = a->stack;
	stack_b = b->stack;
	if (a->size < 2 || b->size < 2)
		return ;
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}

void	pa(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_node	*tmp_node;
	t_node	**a;
	t_node	**b;

	a = stack_a->stack;
	b = stack_b->stack;
	if (!(*b))
		return ;
	tmp_node = (*b)->next;
	ft_list_addfront(a, *b);
	*b = tmp_node;
	stack_a->size++;
	stack_b->size--;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack_b, t_stack *stack_a, int i)
{
	t_node	*tmp_node;
	t_node	**a;
	t_node	**b;

	a = stack_a->stack;
	b = stack_b->stack;
	if (!(*a))
		return ;
	tmp_node = (*a)->next;
	ft_list_addfront(b, *a);
	*a = tmp_node;
	stack_a->size--;
	stack_b->size++;
	if (i == 1)
		write(1, "pb\n", 3);
}
