/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:48:40 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/07 20:39:20 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

void	ft_pointer_convert(char *str, va_list *param, int *nb_car)
{
	char				*s;
	unsigned long long	nb;
	t_flags				flag;

	initialize(&flag);
	check_flags(str, &flag, param);
	nb = va_arg(*param, long long);
	if (nb == 0 && flag.prec == -1 && flag.vide == 1)
		s = ft_strdup("");
	else
		s = ft_from_deci(nb, 'x');
	apply_pointer_flags(s, flag, nb_car);
	free(s);
}

void	neg_sign_pointer(char *s, t_flags flag, int len, int *nb_car)
{
	char	*str;

	str = malloc(len + 3);
	ft_memmove(str, "0x", 2);
	ft_memset(str + 2, '0', (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0));
	ft_memmove(str + 2 + (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0), s, ft_strlen(s));
	ft_memset(str + 2 + (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)),
			' ', len - 2 - (flag.prec > ft_strlen(s) ?
				flag.prec : ft_strlen(s)));
	str[len + 2] = '\0';
	ft_putstr(str);
	(*nb_car) += ft_strlen(str);
	free(str);
}

void	pos_sign_pointer(char *s, t_flags flag, int len, int *nb_car)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(len + 3);
	ft_memset(str, ' ', (flag.prec > ft_strlen(s) ?
				len - flag.prec : len - ft_strlen(s)) - 2);
	i = len - (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)) - 2;
	ft_memmove(str + (len == ft_strlen(s) || i < 0 ? 0 : i), "0x", 2);
	if (i < 0)
		i = 0;
	i += 2;
	while (i < len - ft_strlen(s))
	{
		str[i] = '0';
		i++;
	}
	ft_memmove(str + i, s, ft_strlen(s));
	str[len + 2] = '\0';
	ft_putstr(str);
	(*nb_car) += ft_strlen(str);
	free(str);
}

void	apply_pointer_flags(char *s, t_flags flag, int *nb_car)
{
	int		len;

	if (flag.width > flag.prec)
		len = flag.width;
	else
		len = flag.prec;
	if (ft_strlen(s) > len)
		len = ft_strlen(s);
	if (flag.sign)
		neg_sign_pointer(s, flag, len, nb_car);
	else
		pos_sign_pointer(s, flag, len, nb_car);
}
