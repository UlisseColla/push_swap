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

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
	int				index;
	int				push;
	int				chunk;
	bool			has_index;
}	t_node;

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

typedef struct s_stack
{
	t_node	**stack;
	int		size;
}	t_stack;

typedef struct s_size_helper
{
	t_node	*node;
	int		size;
}	t_helper;

# define CHUNK_1_4 0
# define CHUNK_2_3 1

t_node	*ft_create_node(int value);
t_node	*ft_create_list(char *str_args, int *size);
t_node	*ft_list_last(t_node *list);
t_node	*ft_list_find_node(t_node *list, int value);
void	ft_free_list(t_node *list);
void	ft_list_addfront(t_node **list, t_node *new);
void	ft_list_addback(t_node **list, t_node *new);
int		ft_list_size(t_node **list);

/* Push */
void	pa(t_stack *stack_a, t_stack *stack_b, int i);
void	pb(t_stack *stack_b, t_stack *stack_a, int i);
/* Swap */
void	sa(t_stack *a, int i);
void	sb(t_stack *b, int i);
void	ss(t_stack *a, t_stack *b, int i);
/* Rotate */
void	ra(t_stack *s, int i);
void	rb(t_stack *s, int i);
void	rr(t_stack *stack_a, t_stack *stack_b, int i);
/* Reverse rotate */
void	rra(t_stack *s, int i);
void	rrb(t_stack *s, int i);
void	rrr(t_stack *stack_a, t_stack *stack_b, int i);

/* Utils */
void	index_stack_init(t_node **stack, int i, int c);
/* void	index_push_init(t_node *stack, int *lis); */
void	show_stack(t_node **stack);
void	free_mat(char **mat);
void	counter_rr_rrr(t_operator **operator);
int		moves_counter(int moves, t_node *stack_a, int index);
int		find_smallest(t_node *stack);
int		find_biggest(t_node *stack);
int		check_order(t_node **stack);
int		check_input(char *str);

/* initialize_stack */
int		initialize_stack(t_stack *stack, char **argv, int argc);
int		check_white_space(char *str);

/* --- Sorting --- */
void	ft_two_numbers(t_stack *a);
void	ft_three_numbers(t_stack *a);
void	ft_four_numbers(t_stack *a, t_stack *b);
void	ft_five_numbers(t_stack *stack_a, t_stack *stack_b);
void	push_smallest(t_stack *stack_a, t_stack *stack_b);
void	sorting(t_stack *stack_a, t_stack *stack_b);
void	push_a_to_b(t_stack *stack_a, t_stack *stack_b, int c_1, int c_2);
void	push_b_to_a(t_stack *s_b, t_stack *s_a);
void	check_efficiency(t_helper *h_b, t_helper *h_a, t_operator *operator);
void	eff_counter(t_helper *a, t_helper *b, int index, t_operator **operator);
int		eff_counter_no_save(t_helper *h_a, t_helper *h_b, int index);
/* int		find_eff(t_node *stack, int index); */
int		find_value(t_node *stack, int value);
int		find_smallest_after_index(t_node *stack, int index);
int		find_biggest_before_index(t_node *stack, int index);

#endif
