/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:55:09 by ahhammad          #+#    #+#             */
/*   Updated: 2026/01/03 15:55:48 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	x = all_costs(a->size, index, size, node->index);
	return (x);
}

int	all_costs(int size_a, int index_a, int size_b, int index_targ)
{
	if (index_a <= (size_a / 2) && index_targ <= (size_b / 2))
		return (max(index_a,index_targ));// make fun max
	else if (index_a > (size_a / 2) && index_targ <= (size_b / 2))
		return ((size_a - index_a) + index_targ);
	else if (index_targ > (size_b / 2) && index_a <= (size_a / 2))
		return (index_a + (size_b - index_targ));
	else
		return (max((size_a - index_a),(size_b - index_targ)));// make fun max
}

int	lowest_cost(t_stack	*b)
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

int	set_best_index(t_stack *a, t_stack *b, int index)
{
	int		index_a;
	int		diff;
	int		x;
	t_node	*temp;
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

void	final_touch(t_stack *a)
{
	t_node	*temp;
	int		i;
	int		value;

	if (!a || a->size <= 3)
		return ;
	temp = a->head->next;
	value = a->head->value;
	i = 0;
	while (temp && value < temp->value)
	{
		value = temp->value;
		i++;
		temp = temp->next;
	}
	while (i < a->size / 2 && i >= 0)
	{
		rotate(a, 1);
		i--;
	}
	while (i >= a->size / 2 && i < a->size -1)
	{
		rrotate(a, 1);
		i++;
	}
}
