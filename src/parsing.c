/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:26:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/09 18:18:29 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	*a = (t_stack){
		.list = NULL,
		.len = 0,
		.max = INT32_MIN,
		.min = INT32_MAX
	};
	*b = (t_stack){
		.list = NULL,
		.len = 0,
		.max = INT32_MIN,
		.min = INT32_MAX
	};
}

t_list	*list_from_tab(char	**tab)
{
	t_list	*list;
	int		*n;
	int		i;

	list = NULL;
	i = 0;
	while (tab[i] != NULL)
	{
		n = malloc(sizeof(int));
		*n = ft_atoi(tab[i]);
		ft_lstadd_back(&list, ft_lstnew(n));
		i++;
	}
	return (list);
}

t_list	*list_from_args(int argc, char *argv[])
{
	t_list	*list;
	int		*n;

	list = NULL;
	while (argc > 1)
	{
		n = malloc(sizeof(int));
		*n = ft_atoi(argv[argc - 1]);
		ft_lstadd_front(&list, ft_lstnew(n));
		argc--;
	}
	return (list);
}

void	parsing(int argc, char *argv[], t_stack *a, t_stack *b)
{
	check_args(argc, argv);
	init_stacks(a, b);
	if (argc == 2)
		a->list = list_from_tab(ft_split(argv[1], ' '));
	else
		a->list = list_from_args(argc, argv);
	a->len = ft_lstsize(a->list);
	a->max = ft_find_max(a->list);
	a->min = ft_find_min(a->list);
	check_duplicates(a->list);
}
