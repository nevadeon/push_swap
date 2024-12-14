/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/14 21:07:18 by ndavenne         ###   ########.fr       */
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

// void	apply_double(t_number_list *src, t_number_list *dest, t_ab_on_top op)
// {
// 	while (op.ref_cost > 0 && op.target_cost > 0)
// 	{
// 		apply_single_rotation(src, op.dest);
// 		apply_single_rotation(dest, op.dest);
// 		op.target_cost--;
// 		op.ref_cost--;
// 	}
// }

void rotate_no_print(t_stack *stack, t_rotation direction)
{
	if (direction == ROTATE)
		rotate(&stack->list);
	else
		reverse_rotate(&stack->list);
}

void rotate_with_print(t_stack *stack, t_rotation direction)
{
	rotate_no_print(stack, direction);
	if (direction == ROTATE)
		printf("r%c\n", stack->name);
	else
		printf("rr%c\n", stack->name);
}

void	put_ab_on_top(t_stack *src, t_stack *dest, t_ab_on_top op)
{
	while (op.ref_cost > 0 && op.target_cost > 0 && op.dest == op.src)
	{
		rotate_no_print(src, op.src);
		rotate_no_print(dest, op.dest);
		op.target_cost--;
		op.ref_cost--;
		if (op.src == ROTATE)
			printf("rr\n");
		else
			printf("rrr\n");
	}
	while (op.ref_cost > 0)
	{
		rotate_with_print(src, op.src);
		op.ref_cost--;
	}
	while (op.target_cost > 0)
	{
		rotate_with_print(dest, op.dest);
		op.target_cost--;
	}
}

void	push_with_print(t_stack *src, t_stack *dest)
{
	push(src, dest);
	printf("p%c\n", src->name);
}

void	swap_with_print(t_stack *stack)
{
	swap(&stack->list);
	printf("s%c", stack->name);
}

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

void	turk(t_stack *a, t_stack *b)
{
	while (a->len > 3 && b->len < 2)
		push_with_print(a, b);
	while (a->len > 3)
	{
		put_ab_on_top(a, b, best_numbers_on_top(a, b, is_descending));
		push_with_print(a, b);
	}
	sort_size3_stack(a);
	while (b->len > 0)
	{
		put_ab_on_top(b, a, best_numbers_on_top(b, a, is_ascending));
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
