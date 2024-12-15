/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:31:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/15 01:34:55 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rotation_instruction create_double_rotate(t_rotation_costs rc)
{
	return ((t_rotation_instruction){
		.src = ROTATE,
		.dest = ROTATE,
		.source_cost = rc.source_index,
		.dest_cost = rc.target_index,
		.total_cost = rc.double_rotate
	});
}

t_rotation_instruction create_double_rrotate(t_rotation_costs rc, t_stack *s, t_stack *d)
{
	return ((t_rotation_instruction){
		.src = RROTATE,
		.dest = RROTATE,
		.source_cost = s->len - rc.source_index,
		.dest_cost = d->len - rc.target_index,
		.total_cost = rc.double_rrotate
	});
}

t_rotation_instruction create_opposite_rotate(t_rotation_costs rc, t_stack *d)
{
	return ((t_rotation_instruction){
		.src = ROTATE,
		.dest = RROTATE,
		.source_cost = rc.source_index,
		.dest_cost = d->len - rc.target_index,
		.total_cost = rc.opposite_rotate
	});
}

t_rotation_instruction create_opposite_rrotate(t_rotation_costs rc, t_stack *s, t_stack *d)
{
	return ((t_rotation_instruction){
		.src = RROTATE,
		.dest = ROTATE,
		.source_cost = s->len - rc.source_index,
		.dest_cost = rc.target_index,
		.total_cost = rc.opposite_rrotate
	});
}
