/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/12 18:26:49 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_ascending(int n1, int n2)
{
	return (n1 < n2);
}

bool	is_descending(int n1, int n2)
{
	return (n1 > n2);
}

bool	is_sorted(t_number_list *list, bool (*compare)(int, int))
{
	while (list->next != NULL)
	{
		if (compare(list->number, list->next->number) == false)
			return (false);
		list = list->next;
	}
	return (true);
}

// void	sort_stack(t_stack *src, t_stack *dest, bool (*compare)(int, int))
// {

// }
void	apply_single_rotation(t_number_list *list, t_rotation direction)
{

}

// void	apply_double(t_number_list *src, t_number_list *dest, t_operation op)
// {
// 	while (op.ref_cost > 0 && op.target_cost > 0)
// 	{
// 		apply_single_rotation(src, op.dest);
// 		apply_single_rotation(dest, op.dest);
// 		op.target_cost--;
// 		op.ref_cost--;
// 	}
// }

void	apply_operation(t_stack *src, t_stack *dest, t_operation op)
{
	while (op.ref_cost > 0 && op.target_cost > 0)
	{
		apply_single_rotation(src, op.dest);
		apply_single_rotation(dest, op.dest);
		op.target_cost--;
		op.ref_cost--;
	}
	while (op.ref_cost > 0)
	{
		apply_single_rotation(src, op.src);
		op.ref_cost--;
	}
	while (op.target_cost > 0)
	{
		apply_single_rotation(dest, op.dest);
		op.target_cost--;
	}
}

void	turk(t_stack *a, t_stack *b)
{
	while (a->len > 3 && b->len < 2)
		push(a, b);
	while (a->len > 3)
		apply_operation(a, b, find_cheapest_operation(a, b));
	sort_size3_stack(a);
}

void	push_swap(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	parsing(argc, argv, &a, &b);
	if (is_sorted(a.list, is_ascending) == false)
	{
		if (a.len == 2)
			swap(&a.list);
		else if (a.len == 3)
			sort_size3_stack(&a);
		else
			turk(&a, &b);
	}
}
