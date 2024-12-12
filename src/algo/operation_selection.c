/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:21:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/12 15:30:18 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	find_target(int reference, t_stack *dest)
{
	t_number_list	*list;
	int				target;
	bool			found;

	found = false;
	target = INT32_MIN;
	list = dest->list;
	while (list != NULL)
	{
		if (list->number < reference && list->number > target)
		{
			target = list->number;
			found = true;
		}
		list = list->next;
	}
	if (found == false)
		target = dest->max;
	return (target);
}

t_operation	select_best_rotation(t_movement_cost cost, t_operation op)
{
	op.cost = cost.double_rrotate;
	op.rotation_instruction = DOUBLE_RROTATE;
	if (cost.double_rotate < op.cost)
	{
		op.cost = cost.double_rotate;
		op.rotation_instruction = DOUBLE_ROTATE;
	}
	if (cost.opposite_src_rotate < op.cost)
	{
		op.cost = cost.opposite_src_rotate;
		op.rotation_instruction = OPPOSITE_SRC_ROTATE;
	}
	if (cost.opposite_src_rrotate < op.cost)
	{
		op.cost = cost.opposite_src_rrotate;
		op.rotation_instruction = OPPOSITE_SRC_RROTATE;
	}
	return (op);
}

t_operation	find_best_instruction_set(int reference, t_stack *s, t_stack *d)
{
	t_operation		op;
	t_movement_cost	cost;

	op.nb_index = get_index(reference, s->list);
	op.target_index = get_index(find_target(reference, d), d->list);
	if (op.nb_index == -1 || op.target_index == -1)
		ft_error(ERR_NO_NUMBER);
	cost.double_rotate = max(op.nb_index, op.target_index);
	cost.double_rrotate = max(s->len - op.nb_index, d->len - op.target_index);
	cost.opposite_src_rotate = op.nb_index + d->len - op.target_index;
	cost.opposite_src_rrotate = s->len - op.nb_index + op.target_index;
	// printf("double up %d\n", cost.double_rotate);
	// printf("double down %d\n", cost.double_rrotate);
	// printf("opposite src up %d\n", cost.opposite_src_rotate);
	// printf("opposite src down %d\n", cost.opposite_src_rrotate);
	return (select_best_rotation(cost, op));
}

t_operation	find_cheapest(t_stack *src, t_stack *dest)
{
	t_number_list	*list;
	t_operation		current;
	t_operation		cheapest;

	list = src->list;
	cheapest = (t_operation){
		.cost = INT32_MAX,
		.nb_index = -1,
		.target_index = -1,
		.rotation_instruction = INIT_VALUE
	};
	while (list != NULL)
	{
		current = find_best_instruction_set(list->number, src, dest);
		// printf("target for %3d is %3d and cost %d\n\n", list->number, find_target(list->number, dest), current.cost);
		if (current.cost < cheapest.cost)
			cheapest = current;
		list = list->next;
	}
	return (cheapest);
}
