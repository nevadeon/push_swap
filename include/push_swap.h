/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:46:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/07 11:43:05 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libndav.h"

//test
# include <stdio.h>

typedef enum e_error
{
	ERR_OK,
	ERR_USAGE,
	ERR_EMPTY,
	ERR_INVALID_STRING,
	ERR_MAX
}	t_error;

void	ft_error(t_error error_code);

#endif
