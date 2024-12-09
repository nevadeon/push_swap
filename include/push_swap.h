/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:46:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/09 18:30:52 by ndavenne         ###   ########.fr       */
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
	ERROR,
	ERR_MAX
}	t_error;

typedef struct s_stack
{
	t_list	*list;
	int		len;
	int		min;
	int		max;
}	t_stack;

int		ft_push_swap(int argc, char *argv[]);

void	ft_error(t_error error_code);
void	check_args(int argc, char *argv[]);
void	check_duplicates(t_list *list);
void	parsing(int argc, char *argv[], t_stack *a, t_stack *b);
void	init_stacks(int argc, char *argv[], t_stack *a, t_stack *b);

void	ft_push(t_stack *src, t_stack *dest);
void	ft_swap(t_list **stack);
void	ft_rotate(t_list **stack);
void	ft_reverse_rotate(t_list **stack);

int		ft_find_max(t_list *list);
int		ft_find_min(t_list *list);

#endif
