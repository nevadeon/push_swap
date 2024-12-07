/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:48:44 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/07 12:13:36 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*get_error_message(t_error error_code)
{
	static const char	*message[] = {\
		[ERR_OK] = "The impossible happened", \
		[ERROR] = "Error", \
		[ERR_MAX] = "Ft_error was called with out of bound index"
	};

	return (message[error_code]);
}

void	ft_error(t_error error_code)
{
	if (error_code > ERR_MAX)
		ft_error(ERR_MAX);
	ft_dputendl(STDERR_FILENO, (char *) get_error_message(error_code));
	ft_free_arena();
	exit(error_code);
}
