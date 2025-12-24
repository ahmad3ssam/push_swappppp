/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:10:23 by ahhammad          #+#    #+#             */
/*   Updated: 2025/12/24 14:18:27 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size <= 1)
		return ;
	temp = stack->head->next;
	stack->head->next = temp->next;
	temp->next = stack->head;
	stack->head = temp;
	if (stack->size == 2)
		stack->tail = temp->next;
	ft_printf("s%c\n", stack->name);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
