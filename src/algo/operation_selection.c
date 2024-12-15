/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:21:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/15 02:37:57 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_target(t_compare_function compare)
{
	if (compare(0, 42) == ASCENDING_ORDER)
		return (INT32_MAX);
	else
		return (INT32_MIN);
}

int	find_target(int reference, t_stack *dest, t_compare_function compare)
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

t_rotation_instruction	select_best_rotation(t_rotation_costs rc)
{
	t_rotation_instruction	instructions;
	int						smallest;

	smallest = min(rc.double_rotate, rc.double_rrotate, \
		rc.opposite_rotate, rc.opposite_rrotate);
	if (smallest == rc.double_rotate)
		instructions = create_double_rotate(rc);
	else if (smallest == rc.double_rrotate)
		instructions = create_double_rrotate(rc);
	else if (smallest == rc.opposite_rotate)
		instructions = create_opposite_rotate(rc);
	else
		instructions = create_opposite_rrotate(rc);
	return (instructions);
}

t_rotation_instruction	find_best_target(int reference, t_stack *s, t_stack *d,
	t_compare_function compare)
{
	t_rotation_costs	rc;
	int					source_index;
	int					target_index;

	source_index = get_index(reference, s->list);
	target_index = get_index(find_target(reference, d, compare), d->list);
	if (source_index == -1 || target_index == -1)
		ft_error(ERR_NO_NUMBER);
	rc.source_rotate = source_index;
	rc.source_rrotate = s->len - source_index;
	rc.target_rotate = target_index;
	rc.target_rrotate = d->len - target_index;
	rc.double_rotate = max(rc.source_rotate, rc.target_rotate);
	rc.double_rrotate = max(rc.source_rrotate, rc.target_rrotate);
	rc.opposite_rotate = rc.source_rotate + rc.target_rrotate;
	rc.opposite_rrotate = rc.source_rrotate + rc.target_rotate;
	return (select_best_rotation(rc));
}

//	ft_dprintf(STDOUT_FILENO, "target for %3d is %3d and cost %d\n",
// list->number, (list->number, dest, compare), current.total_cost);
t_rotation_instruction	find_best_instructions(t_stack *src, t_stack *dest,
	t_compare_function compare)
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
