/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:49:59 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/09 15:56:35 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_list *list, char name)
{
	printf("list %c :\n", name);
	while (list != NULL)
	{
		printf("%d\n", *((int *)list->content));
		list = list->next;
	}
	printf("----\n");
}

int	ft_push_swap(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	check_args(argc, argv);
	a = parsing(argc, argv);
	check_duplicates(a);
	b = NULL;
	printlist(a, 'a');
	ft_swap(&a);
	printlist(a, 'a');
	return (0);
}
