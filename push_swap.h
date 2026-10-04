/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:37:03 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/06 19:36:24 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct t_double_node
{
	int						value;
	int						index;
	int						push;
	int						chunk;
	bool					has_index;
	struct t_double_node	*next;
	struct t_double_node	*prev;
}	t_stack;

typedef struct s_operator
{
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_operator;

typedef struct s_list_size
{
	int	list_a;
	int	list_b;
}	t_ls;

# define CHUNK_1_4 0
# define CHUNK_2_3 1

t_stack	*ft_create_node(int value);
t_stack	*ft_create_list(char *str_args, t_ls *ls);
t_stack	*ft_list_last(t_stack *list);
t_stack	*ft_list_find_node(t_stack *list, int value);
void	ft_free_list(t_stack *list);
void	ft_list_addfront(t_stack **list, t_stack *new);
void	ft_list_addback(t_stack **list, t_stack *new);
int		ft_list_size(t_stack **list);

/* Push */
void	pa(t_stack **stack, t_stack **node, int i, t_ls *ls);
void	pb(t_stack **stack, t_stack **node, int i, t_ls *ls);
/* Swap */
void	sa(t_stack **stack, int i);
void	sb(t_stack **stack, int i);
void	ss(t_stack **stack_a, t_stack **stack_b, int i);
/* Rotate */
void	ra(t_stack **stack, int i);
void	rb(t_stack **stack, int i);
void	rr(t_stack **stack_a, t_stack **stack_b, int i);
/* Reverse rotate */
void	rra(t_stack **stack, int i);
void	rrb(t_stack **stack, int i);
void	rrr(t_stack **stack_a, t_stack **stack_b, int i);

/* Utils */
void	index_stack_init(t_stack **stack, int i, int c);
void	index_push_init(t_stack *stack, int *lis);
void	show_stack(t_stack **stack);
void	free_mat(char **mat);
void	counter_rr_rrr(t_operator **operator);
int		moves_counter(int moves, t_stack *stack_a, int index);
int		find_smallest(t_stack *stack);
int		find_biggest(t_stack *stack);
int		check_order(t_stack **stack);
int		check_input(char *str);

/* initialize_stack */
int		initialize_stack(t_stack **stack, char **argv, int argc, t_ls *ls);
int		check_white_space(char *str);

/* --- Sorting --- */
void	ft_two_numbers(t_stack **stack_a);
void	ft_three_numbers(t_stack **stack_a);
void	ft_four_numbers(t_stack **stack_a, t_stack **stack_b);
void	ft_five_numbers(t_stack **stack_a, t_stack **stack_b);
void	push_smallest(t_stack **stack_a, t_stack **stack_b);
void	sorting(t_stack **stack_a, t_stack **stack_b, t_ls *ls);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, int flag, t_ls *ls);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	check_efficiency(t_stack *b, t_stack *a, t_operator *operator);
void	eff_counter(t_stack *a, t_stack *b, int index, t_operator **value);
int		eff_counter_no_save(t_stack *stack_a, t_stack *stack_b, int index);
int		find_eff(t_stack *stack, int index);
int		find_value(t_stack *stack, int value);
int		find_smallest_after_index(t_stack *stack, int index);
int		find_biggest_before_index(t_stack *stack, int index);

#endif
