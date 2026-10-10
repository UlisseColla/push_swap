/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:41:00 by ucolla            #+#    #+#             */
/*   Updated: 2026/10/10 18:55:09 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

time_t	my_gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (-1);
	return ((time.tv_sec * 1e3) + (time.tv_usec / 1e3));
}

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;
	t_stack	a;
	t_stack	b;

	/* time_t start = my_gettime(); */

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
	/* printf("\nTime: %ld ms\n", my_gettime() - start); */
	return (ft_free_list(*a.stack), 0);
}
