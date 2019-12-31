/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:14:24 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/07 23:26:32 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "../libft/libft.h"
#include <stdio.h>

void	ft_string_convert(char *str, va_list *param, int *nb_car)
{
	char	*s;
	t_flags	flag;

	initialize(&flag);
	check_flags(str, &flag, param);
	s = va_arg(*param, char *);
	if (flag.prec == -1)
		s = "";
	if (s == NULL)
		s = "(null)";
	if (flag.prec <= ft_strlen(s) && flag.prec > 0)
		s = ft_substr(s, 0, flag.prec);
	apply_string_flags(s, flag, nb_car);
}

void	neg_sign_string(char *s, int len, int *nb_car)
{
	char	*str;

	str = malloc(len + 1);
	ft_memmove(str, s, ft_strlen(s));
	ft_memset(str + ft_strlen(s), ' ', len - ft_strlen(s));
	str[len] = '\0';
	ft_putstr(str);
	(*nb_car) += ft_strlen(str);
	free(str);
}

void	pos_sign_string(char *s, int len, int *nb_car)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(len + 1);
	ft_memset(str, ' ', len - ft_strlen(s));
	ft_memmove(str + len - ft_strlen(s), s, ft_strlen(s));
	str[len] = '\0';
	ft_putstr(str);
	(*nb_car) += ft_strlen(str);
	free(str);
}

void	apply_string_flags(char *s, t_flags flag, int *nb_car)
{
	int		len;

	if (ft_strlen(s) > flag.width)
		len = ft_strlen(s);
	else
		len = flag.width;
	if (flag.sign)
		neg_sign_string(s, len, nb_car);
	else
		pos_sign_string(s, len, nb_car);
}
