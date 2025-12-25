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

void	pp(t_stack *dest, t_stack *src)
{
	t_node	*temp;
	int		i;

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
	temp = dest->head;
	i = 0;
	while (temp != NULL)
	{
		temp->index = i++;
		temp->cost = -1;
		temp = temp->next;
	}
	temp = src->head;
	i = 0;
	while (temp != NULL)
	{
		temp->index = i++;
		temp->cost = -1;
		temp = temp->next;
	}
	ft_printf("p%c\n", dest->name);
}
