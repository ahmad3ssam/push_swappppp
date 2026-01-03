/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_undup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammad <ahhammad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:21:51 by ahhammad          #+#    #+#             */
/*   Updated: 2026/01/03 16:24:33 by ahhammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	undup(t_stack *stack, int num)
{
	t_node	*temp;

	temp = stack->head;
	while (temp != NULL)
	{
		if (temp->value == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}
