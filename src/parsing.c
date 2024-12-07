/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:26:16 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/07 11:43:08 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_digit_string(const char *str)
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

	if (argc < 2)
		ft_error(ERR_USAGE);
	if (argc == 2 && argv[1][0] == '\0')
		ft_error(ERR_EMPTY);
	i = 1;
	while (i < argc)
	{
		if (check_digit_string(argv[i]) == false)
			ft_error(ERR_INVALID_STRING);
		i++;
	}
}
