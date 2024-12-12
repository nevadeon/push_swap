/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:21:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/12 18:35:46 by ndavenne         ###   ########.fr       */
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

t_operation	select_best_rotation(t_movement_cost mc, t_stack *s, t_stack *d)
{
	t_operation	op;

	mc.smallest = mc.double_rrotate;
	op = (t_operation){.src = RROTATE, .dest = RROTATE, \
		.ref_cost = s->len - mc.ref_index, \
		.target_cost = d->len - mc.target_index, \
		.total_cost = mc.double_rrotate};
	if (mc.double_rotate < mc.smallest)
		op = (t_operation){.src = ROTATE, .dest = ROTATE, \
			.ref_cost = mc.ref_index, \
			.target_cost = mc.target_index, \
			.total_cost = mc.double_rotate};
	if (mc.opposite_src_rotate < mc.smallest)
		op = (t_operation){.src = ROTATE, .dest = RROTATE, \
			.ref_cost = mc.ref_index, \
			.target_cost = d->len - mc.target_index, \
			.total_cost = mc.opposite_src_rotate};
	if (mc.opposite_src_rrotate < mc.smallest)
		op = (t_operation){.src = RROTATE, .dest = ROTATE, \
			.ref_cost = s->len - mc.ref_index, \
			.target_cost = mc.target_index, \
			.total_cost = mc.opposite_src_rrotate};
	return (op);
}

t_operation	find_best_instruction_set(int reference, t_stack *s, t_stack *d)
{
	t_movement_cost	mc;

	mc.ref_index = get_index(reference, s->list);
	mc.target_index = get_index(find_target(reference, d), d->list);
	if (mc.ref_index == -1 || mc.target_index == -1)
		ft_error(ERR_NO_NUMBER);
	mc.double_rotate = max(mc.ref_index, mc.target_index);
	mc.double_rrotate = max(s->len - mc.ref_index, d->len - mc.target_index);
	mc.opposite_src_rotate = mc.ref_index + (d->len - mc.target_index);
	mc.opposite_src_rrotate = (s->len - mc.ref_index) + mc.target_index;
	printf("double up %d\n", mc.double_rotate);
	printf("double down %d\n", mc.double_rrotate);
	printf("opposite src up %d\n", mc.opposite_src_rotate);
	printf("opposite src down %d\n", mc.opposite_src_rrotate);
	return (select_best_rotation(mc, s, d));
}

t_operation	find_cheapest_operation(t_stack *src, t_stack *dest)
{
	t_number_list	*list;
	t_operation		current;
	t_operation		cheapest;

	list = src->list;
	cheapest = (t_operation){.total_cost = INT32_MAX};
	while (list != NULL)
	{
		current = find_best_instruction_set(list->number, src, dest);
		printf("target for %3d is %3d and cost %d\n\n", list->number, find_target(list->number, dest), current.total_cost);
		if (current.total_cost < cheapest.total_cost)
			cheapest = current;
		list = list->next;
	}
	return (cheapest);
}
