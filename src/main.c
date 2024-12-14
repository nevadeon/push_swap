/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:46:22 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/14 21:00:51 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack 	*b;

	// push_swap(argc, argv);

	a = stack_from_string("7 64 47 42", 'a');
	b = stack_from_string("", 'b');
	turk(a, b);
	printlist(a);
	// printf("cheapest index: a %d | b %d\n", );
	return 0;
}
