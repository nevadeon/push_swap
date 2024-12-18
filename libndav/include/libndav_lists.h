/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libndav_lists.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:04:13 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 21:20:43 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNDAV_LIST_H
# define LIBNDAV_LIST_H

typedef struct s_list
{
	struct s_list	*next;
}	t_list;

typedef struct s_pointer_list
{
	struct s_pointer_list	*next;
	void					*content;
}	t_pointer_list;

typedef t_pointer_list	t_plist;

t_plist	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstdelone(t_plist *lst, void (*del)(void *));
void	ft_lstclear(t_plist **lst, void (*del)(void *));
void	ft_lstiter(t_plist *lst, void (*fnc)(void *));
t_plist	*ft_lstmap(t_plist *lst, void *(*fnc)(void *), void (*del)(void *));

#endif
