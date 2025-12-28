/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:09:59 by ahhammad          #+#    #+#             */
/*   Updated: 2025/12/25 15:34:19 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_index(t_stack *stack)
{
	t_node	*node;
	int		i;

	if (stack->size == 0)
		return ;
	node = stack->head;
	i = 0;
	while (node)
	{
		node->index = i;
		i++;
		node = node->next;
	}
}

void	pp(t_stack *dest, t_stack *src)
{
	t_node	*temp;

	if (!src || !src->head)
		return ;
	temp = src->head;
	if (src -> head == src->tail)
		src->tail = NULL;
	src -> head = temp -> next;
	temp -> next = dest->head;
	dest -> head = temp;
	if (dest->tail == NULL)
		dest->tail = temp;
	dest->size++;
	src->size--;
	ft_printf("p%c\n", dest->name);
	reset_index(dest);
	reset_index(src);
}
