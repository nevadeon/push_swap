/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libndav_strings.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:09:17 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/18 21:46:50 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNDAV_STRINGS_H
# define LIBNDAV_STRINGS_H

size_t	ft_strlen(const char *s);
size_t	ft_strclen(const char *str, char c, bool include_char);

void	ft_strcpy(char *dest, const char *src);
int		ft_strlcpy(char *dest, const char *src, size_t d_size);

void	ft_strcat(char *dest, const char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t d_size);
void	ft_strccat(char *dest, const char *src, char c, bool include_char);

char	*ft_strdup(const char *s);
char	*ft_strcdup(const char *str, char c, bool include_char);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsjoin(int n, ...);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
