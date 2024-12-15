/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:18:50 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/14 21:29:20 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
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
