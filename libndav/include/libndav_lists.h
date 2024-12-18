/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libndav_lists.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:04:13 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 21:51:47 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNDAV_LISTS_H
# define LIBNDAV_LISTS_H

typedef struct s_list
{
	struct s_list	*next;
}	t_list;

typedef struct s_pointer_list
{
	struct s_pointer_list	*next;
	void					*content;
}	t_pointer_list;

typedef void	(*t_delete_function)(void *);
typedef void	*(*t_transform_function)(void *);
typedef void	(*t_apply_function)(void *);

t_pointer_list	*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
size_t			ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new_node);
void			ft_lstadd_back(t_list **lst, t_list *new_node);
void			ft_lstdelone(t_pointer_list *lst, t_delete_function delete);
void			ft_lstclear(t_pointer_list **lst, t_delete_function delete);
void			ft_lstiter(t_pointer_list *lst, t_apply_function apply);
t_pointer_list	*ft_lstmap(t_pointer_list *lst, t_transform_function convert, \
												t_delete_function delete);

#endif
