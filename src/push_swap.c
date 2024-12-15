/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:16:44 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/15 18:16:56 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_free_arena();
}
