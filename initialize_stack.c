/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:10:22 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/12 11:37:30 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strjoin_ps(char *s1, char *s2)
{
	char	*ret;
	size_t	a;
	size_t	b;

	ret = (char *)ft_calloc_gnl(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1,
			sizeof(char));
	a = 0;
	b = 0;
	while (s1 && s1[a] != '\0')
	{
		ret[a] = s1[a];
		a++;
	}
	while (s2 && s2[b] != '\0')
	{
		ret[a] = s2[b];
		a++;
		b++;
	}
	ret[a] = '\0';
	free(s1);
	return (ret);
}

int	check_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

static int	many_parameters(char **av, t_stack **stack, t_ls *ls)
{
	char	*str;
	char	*str2;
	int		i;
	int		j;

	str = NULL;
	str2 = NULL;
	i = 0;
	j = 0;
	while (av[j])
	{
		if (check_white_space(av[j]) == 1)
			return (1);
		j++;
	}
	while (av[++i])
	{
		str = ft_strjoin(av[i], " ");
		str2 = ft_strjoin_ps(str2, str);
		free(str);
	}
	if (check_input(str2) != 0)
		return (free(str2), 1);
	*stack = ft_create_list(str2, ls);
	return (free(str2), 0);
}

static int	check_argv(char **argv, int argc, t_stack **stack, t_ls *ls)
{
	if (argc < 2)
		return (2);
	else if (argc == 2)
	{
		if (ft_strlen(argv[1]) < 1)
			return (1);
		if (check_input(argv[1]) == 1)
			return (1);
		*stack = ft_create_list(argv[1], ls);
		return (0);
	}
	else if (ft_strlen(argv[1]) < 1)
		return (1);
	else
		return (many_parameters(argv, stack, ls));
}

int	initialize_stack(t_stack **stack, char **argv, int argc, t_ls *ls)
{
	int	i;

	i = check_argv(argv, argc, stack, ls);
	if (i == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else if (i == 2)
		return (2);
	index_stack_init(stack, 1, 1);
	return (0);
}
