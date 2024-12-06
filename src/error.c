/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:48:44 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/06 18:01:31 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*get_error_message(t_error error_code)
{
	static const char	*message[] = {\
		[ERR_OK] = "The impossible happened",\
		[ERR_USAGE] = "usage: push_swap int1 int2... | push_swap \"int1 int2\""
	};

	return (message[error_code]);
}

void	ft_error(t_error error_code)
{
	ft_dputstr(STDERR_FILENO, get_error_message(error_code));
	ft_free_arena();
	exit(error_code);
}
