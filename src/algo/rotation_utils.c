/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:31:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/15 02:36:03 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rotation_instruction	create_double_rotate(t_rotation_costs rc)
{
	return ((t_rotation_instruction){
		.src = ROTATE,
		.dest = ROTATE,
		.source_cost = rc.source_rotate,
		.dest_cost = rc.target_rotate,
		.total_cost = rc.double_rotate
	});
}

t_rotation_instruction	create_double_rrotate(t_rotation_costs rc)
{
	return ((t_rotation_instruction){
		.src = RROTATE,
		.dest = RROTATE,
		.source_cost = rc.source_rrotate,
		.dest_cost = rc.target_rrotate,
		.total_cost = rc.double_rrotate
	});
}

t_rotation_instruction	create_opposite_rotate(t_rotation_costs rc)
{
	return ((t_rotation_instruction){
		.src = ROTATE,
		.dest = RROTATE,
		.source_cost = rc.source_rotate,
		.dest_cost = rc.target_rrotate,
		.total_cost = rc.opposite_rotate
	});
}

t_rotation_instruction	create_opposite_rrotate(t_rotation_costs rc)
{
	return ((t_rotation_instruction){
		.src = RROTATE,
		.dest = ROTATE,
		.source_cost = rc.source_rrotate,
		.dest_cost = rc.target_rotate,
		.total_cost = rc.opposite_rrotate
	});
}
