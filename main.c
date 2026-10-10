/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:41:00 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/06 15:36:36 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	t_stack	a;
	t_stack	b;

	head_a = NULL;
	head_b = NULL;
	a = (t_stack){&head_a, 0};
	b = (t_stack){&head_b, 0};
	if (initialize_stack(&a, argv, argc) > 0)
		return (ft_free_list(*a.stack), 1);
	if (argc > 1 && check_order(a.stack) == 0)
	{
		if (a.size == 2)
			ft_two_numbers(&a);
		else if (a.size == 3)
			ft_three_numbers(&a);
		else if (a.size == 4)
			ft_four_numbers(&a, &b);
		else if (a.size == 5)
			ft_five_numbers(&a, &b);
		else
			sorting(&a, &b);
	}
	return (ft_free_list(*a.stack), 0);
}
