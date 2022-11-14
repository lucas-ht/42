#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WRITE_ERROR -1

size_t	ft_strlen(const char *s);
int		ft_write_protect(int ft_put_result, int *c);
int		ft_is_base_valid(char *base);

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putlong_fd(long n, int fd);

int		ft_putlong_base_fd(long long n, char *base, int fd);
int		ft_putpointer_base_fd(long long n, char *base, int fd);

#endif
