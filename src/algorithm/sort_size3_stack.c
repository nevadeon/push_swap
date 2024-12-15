/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size3_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:21:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/14 21:29:23 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size3_stack(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (stack->len < 3)
		return ;
	first = stack->list->number;
	second = stack->list->next->number;
	third = stack->list->next->next->number;
	if (first > second && second < third && third > first)
		swap_with_print(stack);
	if (first < second && second > third && third < first)
		rotate_with_print(stack, RROTATE);
	if (first > second && second < third && third < first)
		rotate_with_print(stack, ROTATE);
	if (first > second && second > third && third < first)
	{
		swap_with_print(stack);
		rotate_with_print(stack, RROTATE);
	}
	if (first < second && second > third && third > first)
	{
		rotate_with_print(stack, RROTATE);
		swap_with_print(stack);
	}
}
