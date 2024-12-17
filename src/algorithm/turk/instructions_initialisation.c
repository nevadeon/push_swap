/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_initialisation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:31:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/17 09:00:39 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rotation_instruction	create_double_rotate(t_rotation_costs rc)
{
	return ((t_rotation_instruction){
		.source_direction = ROTATE,
		.dest_direction = ROTATE,
		.source_cost = rc.source_rotate,
		.dest_cost = rc.target_rotate,
		.total_cost = rc.double_rotate
	});
}

t_rotation_instruction	create_double_rrotate(t_rotation_costs rc)
{
	return ((t_rotation_instruction){
		.source_direction = REVERSE_ROTATE,
		.dest_direction = REVERSE_ROTATE,
		.source_cost = rc.source_rrotate,
		.dest_cost = rc.target_rrotate,
		.total_cost = rc.double_rrotate
	});
}

t_rotation_instruction	create_opposite_rotate(t_rotation_costs rc)
{
	return ((t_rotation_instruction){
		.source_direction = ROTATE,
		.dest_direction = REVERSE_ROTATE,
		.source_cost = rc.source_rotate,
		.dest_cost = rc.target_rrotate,
		.total_cost = rc.opposite_rotate
	});
}

t_rotation_instruction	create_opposite_rrotate(t_rotation_costs rc)
{
	return ((t_rotation_instruction){
		.source_direction = REVERSE_ROTATE,
		.dest_direction = ROTATE,
		.source_cost = rc.source_rrotate,
		.dest_cost = rc.target_rotate,
		.total_cost = rc.opposite_rrotate
	});
}
