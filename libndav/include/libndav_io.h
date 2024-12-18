/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libndav_io.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:11:00 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 21:21:17 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNDAV_IO_H
# define LIBNDAV_IO_H

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 4096
# endif

# define DEC "0123456789"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UPP "0123456789ABCDEF"

size_t	ft_dprintf(int fd, const char *format, ...);
size_t	ft_dputchar(int fd, char c);
size_t	ft_dputstr(int fd, const char *s);
size_t	ft_dputptr(int fd, void *p);
size_t	ft_dputlbase(int fd, long n, char *base);
size_t	ft_dputulbase(int fd, t_ulong ul, char *base);
void	ft_dputendl(int fd, const char *s);
void	ft_dputnbr(int fd, int n);

char	*get_next_line(int fd);

#endif
