/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/12 15:30:31 by ndavenne         ###   ########.fr       */
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




void	turk(t_stack *a, t_stack *b)
{
	while (a->len > 3 && b->len < 2)
		push(a, b);
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
