/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:06:00 by ahhammad          #+#    #+#             */
/*   Updated: 2025/12/24 15:51:28 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elems(t_stack *a)
{
	if (!a || a->size == 0)
		return ;
	while (1)
	{
		if (a->head->value > a->tail->value)
			rotate(a, 1);
		else if (a->head->value > a->head->next->value)
			swap(a);
		else if (a->head->next->value > a->tail->value)
		{
			rotate(a, 1);
			swap(a);
			rrotate(a, 1);
		}
		else
			break ;
	}
}

int	is_sorted(t_stack *a)
{
	t_node	*temp1;
	t_node	*temp2;

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

int	find_min_b(t_stack *b, int *num)
{
	int		index;
	int		x;
	t_node	*temp;

	temp = b->head->next;
	index = 0;
	x = 1;
	*num = b->head->value;
	while (temp != NULL)
	{
		if (*num > temp->value)
		{
			index = x;
			*num = temp->value;
		}
		x++;
		temp = temp->next;
	}
	return (index);
}

int		all_costs(int size_a, int index_a, int size_b, int index_targ)
{
	if (index_a <= (size_a / 2) && index_targ <= (size_b / 2))
		return (index_a + index_targ);
	else if (index_a > (size_a / 2) && index_targ <= (size_b / 2))
		return ((size_a - index_a) + index_targ);
	else if (index_targ > (size_b / 2) && index_a <= (size_a / 2))
		return (index_a + (size_b - index_targ));
	else
		return ((size_a - index_a) + (size_b - index_targ));
}

int	ft_abs(int x, int y)
{
	if (x > y)
		return (x - y);
	return (y - x);
}

int	search_closer(t_stack *a, t_node *node, int size)
{
	int		diff;
	int		index;
	int		x;
	t_node	*temp;

	temp = a->head;
	x = 0;
	index = 0;
	diff = INT_MAX;
	while (temp != NULL)
	{
		if (diff >= ft_abs(temp->value, node->value))
		{
			index = x;
			diff = ft_abs(temp->value, node->value);
		}
		x++;
		temp = temp->next;
	}
	node->cost = all_costs(a->size, index, size, node->index);
	return (index);
}

int	check_in_tail0rhead(t_stack *a, t_stack *b, int x, int y)
{
	if ((x > 0 && x < a->size - 1) || (y > 0 && y < b->size - 1))
		return (0);
	if (x == 0 && y == 1)
	{
		swap(b);
		if (a->head->value < b->head->value)
			rotate(a, 1);
	}
	if ((x == a->size - 1) && (y == 0))
		if (a->tail->value > b->head->value)
			rrotate(a, 1);
	if ((y == (b->size - 1)) && (x == 0))
		rrotate(b, 1);
	pp(a, b);
	if (a->head->value > a->head->next->value)
		swap(a);
	return (1);
}

void	make_operas(t_stack *a, t_stack *b, int x, int y)
{
	while (!check_in_tail0rhead(a, b, x, y))
	{
		while ((x > (a->size / 2) && (a->size - 1) >= x) &&
			((y > (b->size / 2)) && (b->size - 1) >= y))
		{
			x++;
			y++;
			rrr(a, b);
		}
		while (((y > (b->size / 2)) && (b->size - 1) > y))
		{
			rrotate(b, 1);
			y++;
		}
		while (((x > (a->size / 2) && (a->size - 1) > x)))
		{
			rrotate(a, 1);
			x++;
		}
		while ((x <= (a->size / 2) && x > 0) && (y <= (b->size / 2) && y > 0))
		{
			x--;
			y--;
			rr(a, b);
		}
		while (y <= (b->size / 2) && y > 0)
		{
			rotate(b, 1);
			y--;
		}
		while ((x <= (a->size / 2) && x > 0))
		{
			rotate(a, 1);
			x--;
		}
	}
}
int		lowest_cost(t_stack	*b)
{
	int		index;
	int		lowest;
	t_node	*temp;

	index = 0;
	temp = b->head->next;
	lowest = b->head->cost;
	while (temp)
	{
		if (lowest > temp->cost)
		{
			index = temp->index;
			lowest = temp->cost;
		}
		temp = temp->next;
	}
	return (index);
}

int		set_best_index(t_stack *a, t_stack *b, int index)
{
	int		index_a;
	t_node	*temp;
	int		diff;
	int		x;
	t_node	*temp2;

	temp = b->head;
	index_a = 0;
	while (temp->index != index)
		temp = temp->next;
	temp2 = a->head;
	x = 0;
	index_a = 0;
	diff = INT_MAX;
	while (temp2 != NULL)
	{
		if (diff >= ft_abs(temp2->value, temp->value))
		{
			index_a = x;
			diff = ft_abs(temp2->value, temp->value);
		}
		x++;
		temp2 = temp2->next;
	}
	return (index_a);
}

void	sort(t_stack *a, t_stack *b)
{
	int	index_a;
	int	index_b;
	//int	num_b;
	t_node	*temp;

	if (is_sorted(a) || !b)
		return ;
	while (a->size > 3)
		pp(b, a);
	three_elems(a);
	while (b->size > 0)
	{
		temp = b->head;
		while (temp)
		{
			index_a = search_closer(a, temp, b->size);
			temp = temp->next;
		}
		index_b = lowest_cost(b);
		index_a = set_best_index(a, b, index_b);
		make_operas(a, b, index_a, index_b);
	}
	while (a->head->value > a->tail->value)
		rotate(a, 1);
}
