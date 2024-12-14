/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:21:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/14 20:44:54 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

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

t_ab_on_top	select_best_rotation(t_movement_cost mc, t_stack *s, t_stack *d)
{
	t_ab_on_top	op;
	int			smallest;

	smallest = mc.double_rotate;
	op = (t_ab_on_top){.src = ROTATE, .dest = ROTATE, \
		.ref_cost = mc.ref_index, \
		.target_cost = mc.target_index, \
		.total_cost = mc.double_rotate};
	if (mc.double_rrotate < smallest)
		op = (t_ab_on_top){.src = RROTATE, .dest = RROTATE, \
			.ref_cost = s->len - mc.ref_index, \
			.target_cost = d->len - mc.target_index, \
			.total_cost = mc.double_rrotate};
	if (mc.opposite_src_rotate < smallest)
		op = (t_ab_on_top){.src = ROTATE, .dest = RROTATE, \
			.ref_cost = mc.ref_index, \
			.target_cost = d->len - mc.target_index, \
			.total_cost = mc.opposite_src_rotate};
	if (mc.opposite_src_rrotate < smallest)
		op = (t_ab_on_top){.src = RROTATE, .dest = ROTATE, \
			.ref_cost = s->len - mc.ref_index, \
			.target_cost = mc.target_index, \
			.total_cost = mc.opposite_src_rrotate};
	return (op);
}

t_ab_on_top	find_best_target(int reference, t_stack *s, t_stack *d, bool (*compare)(int, int))
{
	t_movement_cost	mc;

	mc.ref_index = get_index(reference, s->list);
	mc.target_index = get_index(find_target(reference, d, compare), d->list);
	if (mc.ref_index == -1 || mc.target_index == -1)
		ft_error(ERR_NO_NUMBER);
	mc.double_rotate = max(mc.ref_index, mc.target_index);
	mc.double_rrotate = max(s->len - mc.ref_index, d->len - mc.target_index);
	mc.opposite_src_rotate = mc.ref_index + (d->len - mc.target_index);
	mc.opposite_src_rrotate = (s->len - mc.ref_index) + mc.target_index;
	// printf("double rotate %d\n", mc.double_rotate);
	// printf("double rrotate %d\n", mc.double_rrotate);
	// printf("opposite src up %d\n", mc.opposite_src_rotate);
	// printf("opposite src down %d\n", mc.opposite_src_rrotate);
	return (select_best_rotation(mc, s, d));
}

t_ab_on_top	best_numbers_on_top(t_stack *src, t_stack *dest, bool (*compare)(int, int))
{
	t_number_list	*list;
	t_ab_on_top		current;
	t_ab_on_top		cheapest;

	list = src->list;
	cheapest = (t_ab_on_top){.total_cost = INT32_MAX};
	printlist(src);
	printlist(dest);
	while (list != NULL)
	{
		current = find_best_target(list->number, src, dest, compare);
		printf("target for %3d is %3d and cost %d\n", list->number, find_target(list->number, dest, compare), current.total_cost);
		if (current.total_cost < cheapest.total_cost)
			cheapest = current;
		list = list->next;
	}
	return (cheapest);
}
