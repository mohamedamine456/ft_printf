/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:29:45 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/07 20:39:08 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

void	ft_percent_convert(char *str, va_list *param, int *nb_car)
{
	t_flags	flag;
	char	s;

	initialize(&flag);
	check_flags(str, &flag, param);
	s = '%';
	apply_percent_flags(s, flag, nb_car);
}

void	neg_sign_percent(char s, t_flags flag, int len, int *nb_car)
{
	char	*space;
	char	*zero;

	zero = malloc((flag.prec > 1 ? flag.prec - 1 : 0) + 1);
	ft_memset(zero, '0', (flag.prec > 1 ? flag.prec - 1 : 0));
	zero[(flag.prec > 1 ? flag.prec - 1 : 0)] = '\0';
	space = malloc((len > ft_strlen(zero) + 1 ?
				len - ft_strlen(zero) - 1 : 0) + 1);
	ft_memset(space, ' ', (len > ft_strlen(zero) + 1 ?
				len - ft_strlen(zero) - 1 : 0));
	space[(len > ft_strlen(zero) + 1 ? len - ft_strlen(zero) - 1 : 0)] = '\0';
	ft_putstr(zero);
	ft_putchar(s);
	ft_putstr(space);
	(*nb_car) += ft_strlen(space) + ft_strlen(zero) + 1;
	free(space);
	free(zero);
}

void	pos_sign_percent(char s, t_flags flag, int len, int *nb_car)
{
	char	*space;
	char	*zero;

	zero = malloc((flag.prec > 1 ? flag.prec - 1 : 0) + 1);
	ft_memset(zero, '0', (flag.prec > 1 ? flag.prec - 1 : 0));
	zero[(flag.prec > 1 ? flag.prec - 1 : 0)] = '\0';
	space = malloc((len > ft_strlen(zero) + 1 ?
				len - ft_strlen(zero) - 1 : 0) + 1);
	ft_memset(space, ' ', (len > ft_strlen(zero) + 1 ?
				len - ft_strlen(zero) - 1 : 0));
	space[(len > ft_strlen(zero) + 1 ? len - ft_strlen(zero) - 1 : 0)] = '\0';
	ft_putstr(space);
	ft_putstr(zero);
	ft_putchar(s);
	(*nb_car) += ft_strlen(space) + ft_strlen(zero) + 1;
	free(space);
	free(zero);
}

void	apply_percent_flags(char s, t_flags flag, int *nb_car)
{
	int		len;

	if (flag.width > 0 && flag.zero && !flag.sign)
		flag.prec = flag.width;
	else
		flag.prec = 0;
	if (flag.prec > flag.width && flag.width == 0)
		len = flag.prec;
	else
		len = flag.width;
	if (len < 1)
		len = 1;
	if (flag.sign)
		neg_sign_percent(s, flag, len, nb_car);
	else
		pos_sign_percent(s, flag, len, nb_car);
}
