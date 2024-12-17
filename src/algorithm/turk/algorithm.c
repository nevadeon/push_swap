/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/17 08:54:40 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk(t_stack *a, t_stack *b)
{
	while (a->len > 3 && b->len < 2)
		push(a, b);
	while (a->len > 3)
	{
		apply_instructions(a, b, find_best_instructions(a, b, is_descending));
		push(a, b);
	}
	sort_size3_stack(a);
	while (b->len > 0)
	{
		apply_instructions(b, a, find_best_instructions(b, a, is_ascending));
		push(b, a);
	}
	put_min_on_top(a);
}
