/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/10 22:37:02 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size3_stack(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->list->number;
	second = stack->list->next->number;
	third = stack->list->next->next->number;
	if (first > second && second < third && third > first)
		swap(&stack->list);
	if (first < second && second > third && third < first)
		reverse_rotate(&stack->list);
	if (first > second && second < third && third < first)
		rotate(&stack->list);
	if (first > second && second > third && third < first)
	{
		swap(&stack->list);
		reverse_rotate(&stack->list);
	}
	if (first < second && second > third && third > first)
	{
		reverse_rotate(&stack->list);
		swap(&stack->list);
	}
}

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

int	get_index(int value, t_number_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		if (list->number == value)
			return (i);
		list = list->next;
		i++;
	}
	return (-1);
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

// void	sort_stack(t_stack *src, t_stack *dest, bool (*compare)(int, int))
// {

// }

void	turk(t_stack *a, t_stack *b)
{
	while (a->len > 3 && b->len < 2)
		push(a, b);
	printlist(a, "a");
	printlist(b, "b");

	// sort_stack(a, b, is_descending);
	// sort_size3_stack(a);
	printf("target for %d is %d\n", a->list->number, find_target(a->list->number, b));
	printf("index is %d\n", get_index(find_target(a->list->number, b), b->list));

	// sort_stack(b, a, is_ascending);
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
