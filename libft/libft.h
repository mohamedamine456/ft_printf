/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:36:18 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/06 16:01:13 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

char	*ft_strdup(const char *s1);
char	*ft_itoa(long long n);
int		ft_isdigit(int c);
int		ft_isflag(int c);
void	ft_putchar(int c);
char	ft_isformat(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_addchar(char *str, char c);
void	ft_strrev(char *str);
int		ft_nsize(long long n);
int		ft_atoi(char *str);
void	*ft_memset(void *str, int c, int n);
void	*ft_memmove(void *dest, const void *src, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_display_spaces(int len);
void	ft_display_zeros(int len);

#endif
