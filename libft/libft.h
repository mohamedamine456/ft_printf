/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:36:18 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 18:57:39 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(long long n);
int		ft_isdigit(int c);
int		ft_isflag(int c);
char	ft_isformat(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_addchar(char *str, char c);
void	ft_strrev(char *str);
int		ft_nsize(long long n);
int		ft_atoi(char *str);

#endif
