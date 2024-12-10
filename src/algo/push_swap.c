/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/10 13:48:48 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_number_list *list, const char *name)
{
	printf("%s -> ", name);
	while (list != NULL)
	{
		printf("%2d ", list->number);
		list = list->next;
	}
	printf("\n");
}

void	sort_size3_stack(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->list->number;
	second = stack->list->next->number;
	third = stack->list->next->next->number;
	if (first > second && second < third && third > first)
		ft_swap(&stack->list);
	if (first < second && second > third && third < first)
		ft_reverse_rotate(&stack->list);
	if (first > second && second < third && third < first)
		ft_rotate(&stack->list);
	if (first > second && second > third && third < first)
	{
		ft_swap(&stack->list);
		ft_reverse_rotate(&stack->list);
	}
	if (first < second && second > third && third > first)
	{
		ft_reverse_rotate(&stack->list);
		ft_swap(&stack->list);
	}
}

void	turk(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_push(a, b);

	// printf("list a: len %d max %d min %d\n", a->len, a->max, a->min);
	// printlist(a->list);
	// printf("list b: len %d max %d min %d\n", b->len, b->max, b->min);
	// printlist(b->list);
}

int	ft_push_swap(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	parsing(argc, argv, &a, &b);
	printlist(a.list, "a");
	sort_size3_stack(&a);
	printlist(a.list, "a");
	// turk(&a, &b);
	return (0);
}
