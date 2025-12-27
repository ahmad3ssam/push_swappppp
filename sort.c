/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:06:00 by ahhammad          #+#    #+#             */
/*   Updated: 2025/12/27 00:13:07 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	three_elems(t_stack *a)
{
	if (!a || a->size == 0)
		return ;
	while (1)
	{
		if (a->head->value > a->tail->value)
			rotate(a, 1);
		else if (a->head->value > a->head->next->value)
			swap(a, 1);
		else if (a->head->next->value > a->tail->value)
		{
			rotate(a, 1);
			swap(a, 1);
			rrotate(a, 1);
		}
		else
			break ;
	}
	if (a->size == 3)
	{
		a->head->index = 0;
		a->head->next->index = 1;
		a->tail->index = 2;
	}
}

static int	is_sorted(t_stack *a)
{
	t_node		*temp1;
	t_node		*temp2;

	if (!a || a->size <= 1)
		return (1);
	temp1 = a->head;
	temp2 = a->head->next;
	while (temp2 != NULL)
	{
		if (temp1->value > temp2->value)
			return (0);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return (1);
}

static int	check_in_tail0rhead(t_stack *a, t_stack *b, int x, int y)
{
	if ((x > 0 && x < a->size - 1) || (y > 0 && y < b->size - 1))
		return (0);
	if (x == (a->size - 1))
		rrotate(a, 1);
	if (y == (b->size - 1))
		rrotate(b, 1);
	pp(a, b);
	if (a->head->value > a->head->next->value)
	{
		swap(a, 1);
		a->head->index = 0;
		a->head->next->index = 1;
	}
	return (1);
}

static void    make_operas(t_stack *a, t_stack *b, int x, int y)
{
        while (!check_in_tail0rhead(a, b, x, y))
        {
                if ((x > (a->size / 2) && (a->size - 1) >= x) && (
                                (y > (b->size / 2)) && (b->size - 1) >= y))
                        op_rr(a, b, &x,&y);
                else if (((y > (b->size / 2)) && (b->size - 1) > y))
                        switch_op(b , 'r', &y);
                else if (((x > (a->size / 2) && (a->size - 1) > x)))
                        switch_op(a, 'r', &x);
                else if ((x <= (a->size / 2) && x > 0) && (y <= (b->size / 2) && y > 0))
                        op_r(a, b, &x, &y);
                else if (y <= (b->size / 2) && y > 0)
                        switch_op(b, 'R',&y);
                else if ((x <= (a->size / 2) && x > 0))
                        switch_op(a, 'R',&x);
        }
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int		index_a;
	int		index_b;
	t_node	*temp;

	if (is_sorted(a) || !b)
		return ;
	while (a->size > 3)
		pp(b, a);
	three_elems(a);
	while (b->size > 0)
	{
		temp = b->head;
		while (temp != NULL)
		{
			temp->cost = search_closer(a, temp, b->size);
			temp = temp->next;
		}
		index_b = lowest_cost(b);
		index_a = set_best_index(a, b, index_b);
		make_operas(a, b, index_a, index_b);
	}
	while (a->head->value > a->head->next->value)
		rotate(a, 1);
	while (a->head->value > a->tail->value)
		rotate(a, 1);
}
