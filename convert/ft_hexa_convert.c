/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:39:48 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/20 00:22:16 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

void	ft_hexa_convert(char *str, va_list *param, char conv, int *nb_car)
{
	char			*s;
	unsigned int	nb;
	t_flags			flag;

	initialize(&flag);
	check_flags(str, &flag, param);
	nb = va_arg(*param, unsigned int);
	s = ft_from_deci(nb, conv);
	if (flag.prec == -1 && nb == 0)
		s = ft_strdup("");
	if (flag.prec == -1 && flag.prec_etoile &&
			flag.width && flag.sign && nb == 0)
		s = ft_strdup("0");
	apply_hexa_flags(s, flag, nb_car);
	free(s);
}

void	neg_sign_hexa(char *s, t_flags flag, int len, int *nb_car)
{
	char	*zero;
	char	*space;

	zero = malloc((flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0) + 1);
	ft_memset(zero, '0', (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0));
	zero[(flag.prec > ft_strlen(s) ? flag.prec - ft_strlen(s) : 0)] = '\0';
	space = malloc(len - (flag.prec > ft_strlen(s) ?
				flag.prec : ft_strlen(s)) + 1);
	ft_memset(space, ' ', len - (flag.prec > ft_strlen(s) ?
				flag.prec : ft_strlen(s)));
	space[len - (flag.prec > ft_strlen(s) ?
			flag.prec : ft_strlen(s))] = '\0';
	ft_putstr(zero);
	ft_putstr(s);
	ft_putstr(space);
	(*nb_car) += ft_strlen(s) + ft_strlen(zero) + ft_strlen(space);
	free(space);
	free(zero);
}

void	pos_sign_hexa(char *s, t_flags flag, int len, int *nb_car)
{
	char	*zero;
	char	*space;

	space = malloc((flag.prec > ft_strlen(s) ?
				len - flag.prec : len - ft_strlen(s)) + 1);
	ft_memset(space, ' ', (flag.prec > ft_strlen(s) ?
				len - flag.prec : len - ft_strlen(s)));
	space[(flag.prec > ft_strlen(s) ?
			len - flag.prec : len - ft_strlen(s))] = '\0';
	zero = malloc(len - ft_strlen(s) - ft_strlen(space) + 1);
	ft_memset(zero, '0', len - ft_strlen(s) - ft_strlen(space));
	zero[len - ft_strlen(s) - ft_strlen(space)] = '\0';
	ft_putstr(space);
	ft_putstr(zero);
	ft_putstr(s);
	(*nb_car) += ft_strlen(s) + ft_strlen(zero) + ft_strlen(space);
	free(space);
	free(zero);
}

void	apply_hexa_flags(char *s, t_flags flag, int *nb_car)
{
	int		len;

	if ((!flag.prec || flag.prec_etoile) && flag.zero && !flag.sign)
		flag.prec = flag.width;
	if (flag.prec < -1 && flag.zero && flag.width > flag.prec && !flag.sign)
		flag.prec = flag.width;
	if (flag.width > flag.prec)
		len = flag.width;
	else
		len = flag.prec;
	if (ft_strlen(s) > len)
		len = ft_strlen(s);
	if (flag.sign)
		neg_sign_hexa(s, flag, len, nb_car);
	else
		pos_sign_hexa(s, flag, len, nb_car);
}
