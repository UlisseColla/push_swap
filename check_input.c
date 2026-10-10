/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:59:54 by ucolla            #+#    #+#             */
/*   Updated: 2026/10/10 18:51:00 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mat(char **mat)
{
	int	y;

	y = 0;
	while (mat[y])
	{
		free(mat[y]);
		y++;
	}
	free(mat);
}

int	check_dup(char **mat, int y)
{
	int	a;
	int	n1;
	int	n2;

	a = y;
	n1 = ft_atoi(mat[a]);
	y++;
	while (mat[y])
	{
		n2 = ft_atoi(mat[y]);
		if (n1 - n2 == 0)
			return (1);
		y++;
	}
	return (0);
}

int	check_sign_and_chars(char **mat, int i, int j)
{
	if (mat[i][j] == '-' && ft_strlen(mat[i]) == 1)
		return (1);
	else if (mat[i][j] == '-')
		j++;
	while (mat[i][j])
	{
		if ((mat[i][j] < 48) || (mat[i][j] > 57))
			return (1);
		j++;
	}
	return (0);
}

void	check_input_helper(char ***mat)
{
	free_mat(*mat);
	*mat = NULL;
}

int	check_input(char *str)
{
	char	**mat;
	int		i;
	long	n;

	i = 0;
	if (check_white_space(str) == 1)
		return (1);
	mat = ft_split(str, ' ');
	while (mat[i])
	{
		n = ft_atol(mat[i]);
		if (check_sign_and_chars(mat, i, 0) == 1 || n > INT_MAX || n < INT_MIN)
			return (check_input_helper(&mat), 1);
		i++;
	}
	i = 0;
	while (mat[i])
	{
		if (check_dup(mat, i) == 1)
			return (check_input_helper(&mat), 1);
		i++;
	}
	return (check_input_helper(&mat), 0);
}
