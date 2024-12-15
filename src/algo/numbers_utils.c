/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:18:50 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/15 02:35:32 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	min(int n1, int n2, int n3, int n4)
{
	int	min;

	min = n1;
	if (n2 < min)
		min = n2;
	if (n3 < min)
		min = n3;
	if (n4 < min)
		min = n4;
	return (min);
}

bool	is_ascending(int n1, int n2)
{
	return (n1 < n2);
}

bool	is_descending(int n1, int n2)
{
	return (n1 > n2);
}

bool	is_sorted(t_number_list *list, t_compare_function compare)
{
	while (list->next != NULL)
	{
		if (compare(list->number, list->next->number) == false)
			return (false);
		list = list->next;
	}
	return (true);
}
