/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_selection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:21:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 20:44:43 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_target(t_compare_function compare)
{
	if (compare == is_ascending)
		return (INT_MAX);
	else if (compare == is_descending)
		return (INT_MIN);
	return (ft_error(ERROR_COMPARE_FUNCTION), 0);
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
		if (compare == is_ascending)
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

t_rotation_instruction	rotation_instructions(
	int reference, t_stack *src, t_stack *dest, t_compare_function compare)
{
	t_rotation_costs	rc;
	int					source_index;
	int					target_index;

	source_index = get_index(reference, src->list);
	target_index = get_index(find_target(reference, dest, compare), dest->list);
	if (source_index == -1 || target_index == -1)
		ft_error(ERROR_NO_NUMBER);
	rc.source_rotate = source_index;
	rc.source_rrotate = src->len - source_index;
	rc.target_rotate = target_index;
	rc.target_rrotate = dest->len - target_index;
	rc.double_rotate = max(rc.source_rotate, rc.target_rotate);
	rc.double_rrotate = max(rc.source_rrotate, rc.target_rrotate);
	rc.opposite_rotate = rc.source_rotate + rc.target_rrotate;
	rc.opposite_rrotate = rc.source_rrotate + rc.target_rotate;
	return (select_best_rotation(rc));
}

t_rotation_instruction	find_best_instructions(t_stack *src, t_stack *dest,
	t_compare_function compare)
{
	t_number_list			*list;
	t_rotation_instruction	current;
	t_rotation_instruction	cheapest;

	list = src->list;
	cheapest = (t_rotation_instruction){.total_cost = INT_MAX};
	while (list != NULL)
	{
		current = rotation_instructions(list->number, src, dest, compare);
		if (current.total_cost < cheapest.total_cost)
			cheapest = current;
		list = list->next;
	}
	return (cheapest);
}

//	ft_dprintf(STDOUT_FILENO, "target for %3d is %3d and cost %d\n",
// list->number, (list->number, dest, compare), current.total_cost);
