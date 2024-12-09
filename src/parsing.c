/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:26:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/09 19:08:02 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	init_stacks(int argc, char *argv[], t_stack *a, t_stack *b)
{
	t_list	*a_list;

	if (argc == 2)
		a_list = list_from_tab(ft_split(argv[1], ' '));
	else
		a_list = list_from_args(argc, argv);
	*a = (t_stack){
		.list = a_list,
		.len = ft_lstsize(a_list),
		.max = ft_find_max(a_list),
		.min = ft_find_min(a_list)
	};
	*b = (t_stack){
		.list = NULL,
		.len = 0,
		.max = INT32_MIN,
		.min = INT32_MAX
	};
}

void	parsing(int argc, char *argv[], t_stack *a, t_stack *b)
{
	check_args(argc, argv);
	init_stacks(argc, argv, a, b);
	check_duplicates(a->list);
}
