/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:19:16 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/29 03:03:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

# include "list.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "vector3.h"
# include "euler.h"
# include "ternary.h"
# include "dict.h"

# define WRITE_ERROR -1

// ctype
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isnumber(char *s);
int			ft_isint(long n);
int			ft_ishex(int c);
int			ft_iswhite(int c);

// string
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_strlower(char *s);

// stdlib
long		ft_atoi(const char *str);
uint64_t	ft_atoi_hex(const char *str);
void		*ft_calloc(size_t count, size_t size);

// ft
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin3(char const *s1, char const *s2, char const *s3);
char		*ft_strjoin_free(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char *charset);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
int			ft_is_base_valid(char *base);
int			ft_free_split(char **s);
int			ft_count(char *str, char *charset);
int			ft_striter_if(char *s, int (*f)(int));
int			ft_split_len(char **str);
char		**ft_split_copy(char **str);
char		**ft_split_ncopy(char **str, int n);
char		*ft_split_last(char **str);
void		*ft_split_error(char **strs, int i);
char		**ft_split_insert(char **strs, char *str, int i);
char		**ft_split_pop(char **strs, int i);
char		**ft_split_reverse(char **strs);
void		ft_split_print(char *name, char **strs);

// put
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putlong_fd(long n, int fd);
int			ft_putlong_base_fd(long long n, char *base, int fd);
int			ft_putpointer_base_fd(long long n, char *base, int fd);
int			ft_write_protect(int ft_put_result, int *c);

#endif
