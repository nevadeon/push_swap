/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:46:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/10 15:41:06 by ndavenne         ###   ########.fr       */
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

typedef struct s_number_list
{
	struct s_number_list	*next;
	int						number;
}	t_number_list;

typedef struct s_stack
{
	t_number_list	*list;
	int				len;
	int				min;
	int				max;
}	t_stack;

/* parsing */
void			parsing(int argc, char *argv[], t_stack *a, t_stack *b);
void			init_stacks(int argc, char *argv[], t_stack *a, t_stack *b);
void			check_args(int argc, char *argv[]);
void			check_duplicates(t_number_list *list);

/* algo */
void			push_swap(int argc, char *argv[]);

/* operations */
void			push(t_stack *src, t_stack *dest);
void			swap(t_number_list **list);
void			rotate(t_number_list **list);
void			reverse_rotate(t_number_list **list);

/* list utils */
t_list			*ft_lstprevlast(t_list *lst);
t_number_list	*ft_number_list_new(int number);
void			printlist(t_stack *stack, const char *name);
int				find_min(t_number_list *list);
int				find_max(t_number_list *list);

void			ft_error(t_error error_code);

#endif
