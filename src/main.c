/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:46:22 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/12 14:58:24 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(void)
{
	t_stack	*a;
	t_stack *b;

	// push_swap(argc, argv);

	a = stack_from_string("-38 10 7 42");
	b = stack_from_string("25 0 99");
	printlist(a, "a");
	printlist(b, "b");
	printf("cheapest from a to b is %d\n\n", find_cheapest(a, b).nb_index);
	return 0;
}
