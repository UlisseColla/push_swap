/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:51:04 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/31 11:10:32 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_create_list(char *str_args, int *size)
{
	t_node	*list;
	t_node	*new;
	int		i;
	char	**args;

	list = NULL;
	i = 0;
	args = ft_split(str_args, ' ');
	while (args[i])
	{
		new = ft_create_node(ft_atoi(args[i]));
		new->push = 1;
		new->has_index = false;
		if (new == NULL)
		{
			ft_free_list(list);
			return (NULL);
		}
		ft_list_addback(&list, new);
		i++;
	}
	*size = i;
	free_mat(args);
	return (list);
}
