/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_on_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:58:04 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/17 09:00:39 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_min_on_top(t_stack *stack)
{
	t_rotation		direction;

	if (get_index(stack->min, stack->list) <= stack->len / 2)
		direction = ROTATE;
	else
		direction = REVERSE_ROTATE;
	while (stack->list->number != stack->min)
		rotate(stack, direction);
}
