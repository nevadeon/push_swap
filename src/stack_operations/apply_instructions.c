/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:25:01 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/17 08:59:21 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_instructions(t_stack *s, t_stack *d, t_rotation_instruction ri)
{
	while ((ri.source_cost > 0 && ri.dest_cost > 0)
		&& (ri.source_direction == ri.dest_direction))
	{
		double_rotate(s, d, ri.source_direction);
		ri.dest_cost--;
		ri.source_cost--;
	}
	while (ri.source_cost > 0)
	{
		rotate(s, ri.source_direction);
		ri.source_cost--;
	}
	while (ri.dest_cost > 0)
	{
		rotate(d, ri.dest_direction);
		ri.dest_cost--;
	}
}
