/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:10:11 by ahhammad          #+#    #+#             */
/*   Updated: 2025/12/27 00:25:46 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/print/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
	char		name;
}	t_stack;

void	pp(t_stack *dest, t_stack *src);
void	ss(t_stack *a, t_stack *b);
void	swap(t_stack *stack, int print);
void	rotate(t_stack *stack, int print);
void	rr(t_stack *a, t_stack *b);
void	rrotate(t_stack *stack, int print);
void	rrr(t_stack *a, t_stack *b);

void	ft_sort(t_stack *a, t_stack *b);
int		lowest_cost(t_stack	*b);
int		all_costs(int size_a, int index_a, int size_b, int index_targ);
int		search_closer(t_stack *a, t_node *node, int size);


void	op_r(t_stack *a, t_stack *b, int *x, int *y);
void	op_rr(t_stack *a, t_stack *b, int *x, int *y);
void	switch_op(t_stack *stack, char c, int *num);

#endif
