/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/10 15:03:51 by ndavenne         ###   ########.fr       */
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

void	turk(t_stack *a, t_stack *b)
{
	push(a, b);
	push(a, b);

	// sort(a, reverse);
	// sort(a, normal);
}

int	push_swap(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	parsing(argc, argv, &a, &b);
	printlist(&a, "a");
	sort_size3_stack(&a);
	printlist(&a, "a");
	// turk(&a, &b);
	return (0);
}
