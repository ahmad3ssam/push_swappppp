/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:09:57 by ahhammad          #+#    #+#             */
/*   Updated: 2026/01/03 17:13:43 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	free_all(t_stack *a, t_stack *b, int check)
{
	t_node	*temp;
	t_node	*current;

	current = NULL;
	if (a)
		current = a->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(a);
	if (b)
		current = b->head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(b);
	if (check == -1)
		write(2, "Error\n", 6);
	return (0);
}

static void	push_a(t_stack *a, t_node *node)
{
	if (!(a)->head)
	{
		(a)->head = node;
		(a)->tail = node;
		(a)->size = 1;
	}
	else
	{
		node->next = (a)->head;
		(a)->head = node;
		(a)->size += 1;
	}
}

static int	create_a(t_stack *a, char **list, int index)
{
	long	num;
	t_node	*node;

	while (index > 0)
	{
		num = ft_atoi(list[index]);
		if (num == LONG_MAX || undup(a, num) == 1)
			return (-1);
		node = malloc(sizeof(t_node));
		if (!node)
			return (-1);
		node -> value = num;
		node -> index = index - 1;
		node -> cost = -1;
		node -> next = NULL;
		push_a(a, node);
		index--;
	}
	return (1);
}

static t_stack	*stack(char name)
{
	t_stack		*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp)
	{
		temp->head = NULL;
		temp->tail = NULL;
		temp->size = 0;
		temp->name = name;
	}
	return (temp);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (-1);
	a = stack ('a');
	b = stack ('b');
	if (!a || !b)
		return (free_all(a, b, 1));
	if (create_a(a, argv, argc - 1) == -1)
		return (free_all(a, b, -1));
	ft_sort(a, b);
	return (free_all(a, b, 1));
}
