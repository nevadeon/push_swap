/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:21:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/15 01:36:27 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_target(bool (*compare)(int, int))
{
	if (compare(0, 42) == ASCENDING_ORDER)
		return (INT32_MAX);
	else
		return (INT32_MIN);
}

int	find_target(int reference, t_stack *dest, bool (*compare)(int, int))
{
	t_number_list	*list;
	int				target;
	bool			found;

	found = false;
	target = init_target(compare);
	list = dest->list;
	while (list != NULL)
	{
		if (!compare(list->number, reference) && compare(list->number, target))
		{
			target = list->number;
			found = true;
		}
		list = list->next;
	}
	if (found == false)
	{
		if (compare(0, 42) == ASCENDING_ORDER)
			target = dest->min;
		else
			target = dest->max;
	}
	return (target);
}

// t_rotation_instruction	select_best_rotation(t_rotation_costs rc,
// 	t_stack *s, t_stack *d)
// {
// 	t_rotation_instruction	inst;
// 	int			smallest;

// 	smallest = rc.double_rotate;
// 	inst = (t_rotation_instruction){.src = ROTATE, .dest = ROTATE, \
// 		.source_cost = rc.source_index, \
// 		.dest_cost = rc.target_index, \
// 		.total_cost = rc.double_rotate};
// 	if (rc.double_rrotate < smallest)
// 		inst = (t_rotation_instruction){.src = RROTATE, .dest = RROTATE, \
// 			.source_cost = s->len - rc.source_index, \
// 			.dest_cost = d->len - rc.target_index, \
// 			.total_cost = rc.double_rrotate};
// 	if (rc.opposite_rotate < smallest)
// 		inst = (t_rotation_instruction){.src = ROTATE, .dest = RROTATE, \
// 			.source_cost = rc.source_index, \
// 			.dest_cost = d->len - rc.target_index, \
// 			.total_cost = rc.opposite_rotate};
// 	if (rc.opposite_rrotate < smallest)
// 		inst = (t_rotation_instruction){.src = RROTATE, .dest = ROTATE, \
// 			.source_cost = s->len - rc.source_index, \
// 			.dest_cost = rc.target_index, \
// 			.total_cost = rc.opposite_rrotate};
// 	return (inst);
// }

t_rotation_instruction select_best_rotation(t_rotation_costs rc,
	t_stack *s, t_stack *d)
{
	t_rotation_instruction instructions;
	int smallest;

	smallest = rc.double_rotate;
	if (rc.double_rrotate < smallest)
		smallest = rc.double_rrotate;
	if (rc.opposite_rotate < smallest)
		smallest = rc.opposite_rotate;
	if (rc.opposite_rrotate < smallest)
		smallest = rc.opposite_rrotate;

	if (smallest == rc.double_rotate)
		instructions = create_double_rotate(rc);
	else if (smallest == rc.double_rrotate)
		instructions = create_double_rrotate(rc, s, d);
	else if (smallest == rc.opposite_rotate)
		instructions = create_opposite_rotate(rc, d);
	else
		instructions = create_opposite_rrotate(rc, s, d);
	return (instructions);
}

// ft_dprintf(STDOUT_FILENO, "double rotate %d\n", rc.double_rotate);
// ft_dprintf(STDOUT_FILENO, "double rrotate %d\n", rc.double_rrotate);
// ft_dprintf(STDOUT_FILENO, "opposite src up %d\n", rc.opposite_rotate);
// ft_dprintf(STDOUT_FILENO, "opposite src down %d\n", rc.opposite_rrotate);
t_rotation_instruction	find_best_target(int reference, t_stack *s, t_stack *d,
	bool (*compare)(int, int))
{
	t_rotation_costs	rc;

	rc.source_index = get_index(reference, s->list);
	rc.target_index = get_index(find_target(reference, d, compare), d->list);
	if (rc.source_index == -1 || rc.target_index == -1)
		ft_error(ERR_NO_NUMBER);
	rc.double_rotate = max(rc.source_index, rc.target_index);
	rc.double_rrotate = max(s->len - rc.source_index, d->len - rc.target_index);
	rc.opposite_rotate = rc.source_index + (d->len - rc.target_index);
	rc.opposite_rrotate = (s->len - rc.source_index) + rc.target_index;
	return (select_best_rotation(rc, s, d));
}

//	ft_dprintf(STDOUT_FILENO, "target for %3d is %3d and cost %d\n",
// list->number, (list->number, dest, compare), current.total_cost);
t_rotation_instruction	find_best_instructions(t_stack *src, t_stack *dest,
	bool (*compare)(int, int))
{
	t_number_list			*list;
	t_rotation_instruction	current;
	t_rotation_instruction	cheapest;

	list = src->list;
	cheapest = (t_rotation_instruction){.total_cost = INT32_MAX};
	while (list != NULL)
	{
		current = find_best_target(list->number, src, dest, compare);
		if (current.total_cost < cheapest.total_cost)
			cheapest = current;
		list = list->next;
	}
	return (cheapest);
}
