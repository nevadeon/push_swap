/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:26:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 20:43:32 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number_list	*list_from_tab(char	**tab)
{
	t_number_list	*list;
	t_number_list	*new_node;
	int				i;

	list = NULL;
	i = 0;
	while (tab[i] != NULL)
	{
		new_node = ft_number_list_new(ft_atoi(tab[i]));
		ft_lstadd_back((t_list **)&list, (t_list *)new_node);
		i++;
	}
	return (list);
}

t_number_list	*list_from_args(int argc, char *argv[])
{
	t_number_list	*list;
	t_number_list	*new_node;

	list = NULL;
	while (argc > 1)
	{
		new_node = ft_number_list_new(ft_atoi(argv[argc - 1]));
		ft_lstadd_front((t_list **)&list, (t_list *)new_node);
		argc--;
	}
	return (list);
}

void	init_stacks(int argc, char *argv[], t_stack *a, t_stack *b)
{
	t_number_list	*a_list;

	if (argc == 2)
		a_list = list_from_tab(ft_split(argv[1], ' '));
	else
		a_list = list_from_args(argc, argv);
	*a = (t_stack){
		.list = a_list,
		.name = 'a',
		.len = ft_lstsize((t_list *)a_list),
		.max = find_max(a_list),
		.min = find_min(a_list)
	};
	*b = (t_stack){
		.list = NULL,
		.name = 'b',
		.len = 0,
		.max = INT_MIN,
		.min = INT_MAX
	};
}

void	parsing(int argc, char *argv[], t_stack *a, t_stack *b)
{
	check_args(argc, argv);
	init_stacks(argc, argv, a, b);
	check_duplicates(a->list);
}
