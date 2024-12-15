/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:25:01 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/15 18:25:24 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_min_on_top(t_stack *stack)
{
	t_rotation		direction;

	if (get_index(stack->min, stack->list) < stack->len / 2)
		direction = ROTATE;
	else
		direction = RROTATE;
	while (stack->list->number != stack->min)
		rotate_with_print(stack, direction);
}

void	apply_instructions(t_stack *s, t_stack *d, t_rotation_instruction ri)
{
	while (ri.source_cost > 0 && ri.dest_cost > 0 && ri.dest == ri.src)
	{
		rotate_no_print(s, ri.src);
		rotate_no_print(d, ri.dest);
		ri.dest_cost--;
		ri.source_cost--;
		if (ri.src == ROTATE)
			ft_dprintf(STDOUT_FILENO, "rr\n");
		else
			ft_dprintf(STDOUT_FILENO, "rrr\n");
	}
	while (ri.source_cost > 0)
	{
		rotate_with_print(s, ri.src);
		ri.source_cost--;
	}
	while (ri.dest_cost > 0)
	{
		rotate_with_print(d, ri.dest);
		ri.dest_cost--;
	}
}
