/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size3_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:21:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/12 15:22:01 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size3_stack(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->list->number;
	second = stack->list->next->number;
	third = stack->list->next->next->number;
	if (first > second && second < third && third > first)
		swap(&stack->list);
	if (first < second && second > third && third < first)
		reverse_rotate(&stack->list);
	if (first > second && second < third && third < first)
		rotate(&stack->list);
	if (first > second && second > third && third < first)
	{
		swap(&stack->list);
		reverse_rotate(&stack->list);
	}
	if (first < second && second > third && third > first)
	{
		reverse_rotate(&stack->list);
		swap(&stack->list);
	}
}
