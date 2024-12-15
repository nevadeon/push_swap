/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/15 00:51:15 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_min_on_top(t_stack *stack)
{
	t_rotation		direction;

	if (get_index(stack->min, stack->list) < stack->len / 2)
		direction = ROTATE;
	else
		direction = RROTATE;
	while (stack->list->number != stack->min)
		rotate_with_print(stack, direction);
}

void	apply_instructions(t_stack *s, t_stack *d, t_rotation_instruction ri)
{
	while (ri.source_cost > 0 && ri.dest_cost > 0 && ri.dest == ri.src)
	{
		rotate_no_print(s, ri.src);
		rotate_no_print(d, ri.dest);
		ri.dest_cost--;
		ri.source_cost--;
		if (ri.src == ROTATE)
			ft_dprintf(STDOUT_FILENO, "rr\n");
		else
			ft_dprintf(STDOUT_FILENO, "rrr\n");
	}
	while (ri.source_cost > 0)
	{
		rotate_with_print(s, ri.src);
		ri.source_cost--;
	}
	while (ri.dest_cost > 0)
	{
		rotate_with_print(d, ri.dest);
		ri.dest_cost--;
	}
}

void	turk(t_stack *a, t_stack *b)
{
	while (a->len > 3 && b->len < 2)
		push_with_print(a, b);
	while (a->len > 3)
	{
		apply_instructions(a, b, find_best_instructions(a, b, is_descending));
		push_with_print(a, b);
	}
	sort_size3_stack(a);
	while (b->len > 0)
	{
		apply_instructions(b, a, find_best_instructions(b, a, is_ascending));
		push_with_print(b, a);
	}
	put_min_on_top(a);
}

void	push_swap(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	parsing(argc, argv, &a, &b);
	if (is_sorted(a.list, is_ascending) == false)
	{
		if (a.len == 2)
			swap_with_print(&a);
		else if (a.len == 3)
			sort_size3_stack(&a);
		else
			turk(&a, &b);
	}
}
