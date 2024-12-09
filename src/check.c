/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:29:10 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/07 16:29:08 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_string_digits(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == false && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

void	check_args(int argc, char *argv[])
{
	int	i;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		ft_error(ERROR);
	i = 1;
	while (i < argc)
	{
		if (is_string_digits(argv[i]) == false)
			ft_error(ERROR);
		i++;
	}
}

void	verify_number(t_list *list, int n)
{
	while (list != NULL)
	{
		if (*((int *)list->content) == n)
			ft_error(ERROR);
		list = list->next;
	}
}

void	check_duplicates(t_list *list)
{
	while (list->next != NULL)
	{
		verify_number(list->next, *((int *)list->content));
		list = list->next;
	}
}
