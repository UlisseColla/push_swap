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
	t_stack	*a;
	t_stack	*b;
	t_ls	ls;

	a = NULL;
	b = NULL;
	ls = (t_ls){0, 0};
	if (initialize_stack(&a, argv, argc, &ls) > 0)
		return (ft_free_list(a), 1);
	if (argc > 1 && check_order(&a) == 0)
	{
		if (ls.list_a == 2)
			ft_two_numbers(&a);
		else if (ls.list_a == 3)
			ft_three_numbers(&a);
		else if (ls.list_a == 4)
			ft_four_numbers(&a, &b);
		else if (ls.list_a == 5)
			ft_five_numbers(&a, &b);
		else
			sorting(&a, &b, &ls);
	}
	return (ft_free_list(a), 0);
}
