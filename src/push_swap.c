/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/07 15:49:45 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_list *list)
{
	while (list != NULL)
	{
		printf("%d\n", *((int *)list->content));
		list = list->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	check_args(argc, argv);
	a = parsing(argc, argv);
	check_duplicates(a);
	b = NULL;
	printlist(a);
	return (0);
}
