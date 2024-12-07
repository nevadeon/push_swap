/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:26:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/07 15:49:37 by ndavenne         ###   ########.fr       */
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
		n = malloc(sizeof(int *));
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
		n = malloc(sizeof(int *));
		*n = ft_atoi(argv[argc - 1]);
		ft_lstadd_front(&list, ft_lstnew(n));
		argc--;
	}
	return (list);
}

t_list	*parsing(int argc, char *argv[])
{
	if (argc == 2)
		return (list_from_tab(ft_split(argv[1], ' ')));
	else
		return (list_from_args(argc, argv));
}
