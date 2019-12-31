/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:56:46 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/10 16:53:57 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

char	*g_sttr;
int		g_moin;

void	ft_int_convert(char *str, va_list *param, int *nb_car)
{
	char	*s;
	long	nb;
	t_flags	flag;

	g_moin = 0;
	initialize(&flag);
	check_flags(str, &flag, param);
	nb = va_arg(*param, int);
	if (nb < 0)
	{
		g_moin = 1;
		nb *= -1;
	}
	if (flag.prec == -1 && flag.vide == 1 && nb == 0)
		s = ft_strdup("");
	else
		s = ft_itoa(nb);
	g_sttr = str;
	apply_int_flags(s, flag, nb_car);
	free(s);
}

int		check_prec_zero(t_flags flag)
{
	int		nb;

	while (*g_sttr != '.' && *g_sttr != 'd' &&
			*g_sttr != 'i' && *g_sttr != '\0')
		g_sttr++;
	nb = ft_atoi(g_sttr + 1);
	if (nb == 0 && *(g_sttr + 1) != '*' && *(g_sttr + 1) != '0' &&
			flag.prec == flag.width && flag.zero && flag.width != 0)
		return (1);
	return (0);
}

void	neg_sign_int(char *s, t_flags flag, int len, int *nb_car)
{
	char	*space;
	char	*zero;
	int		precc;

	zero = malloc((flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0) + 1);
	precc = check_prec_zero(flag);
	ft_memset(zero, '0', (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0));
	zero[(flag.prec > ft_strlen(s) ? flag.prec - ft_strlen(s) : 0)] = '\0';
	space = malloc(len - (flag.prec >
				ft_strlen(s) ? flag.prec : ft_strlen(s)) - g_moin + 1);
	ft_memset(space, ' ', len - (flag.prec >
				ft_strlen(s) ? flag.prec : ft_strlen(s)) - g_moin);
	space[len - (flag.prec > ft_strlen(s) ?
			flag.prec : ft_strlen(s)) - g_moin] = '\0';
	if (g_moin)
		ft_putstr("-");
	ft_putstr(zero);
	ft_putstr(s);
	ft_putstr(space);
	(*nb_car) += ft_strlen(s) + ft_strlen(zero) + ft_strlen(space) + g_moin;
	free(space);
	free(zero);
}

void	pos_sign_int(char *s, t_flags flag, int len, int *nb_car)
{
	char	*space;
	char	*zero;
	int		precc;

	zero = malloc((flag.prec > ft_strlen(s) ? flag.prec
				- ft_strlen(s) : 0) + 1);
	precc = check_prec_zero(flag);
	ft_memset(zero, '0', (flag.prec > ft_strlen(s) ? flag.prec -
				ft_strlen(s) : 0) - (precc && g_moin ? g_moin : 0));
	zero[(flag.prec > ft_strlen(s) ? flag.prec - ft_strlen(s) : 0)] = '\0';
	space = malloc((len > ft_strlen(s) + ft_strlen(zero) + g_moin ?
				len - ft_strlen(s) + ft_strlen(zero) + g_moin : 0) + 1);
	ft_memset(space, ' ', (len > ft_strlen(s) + ft_strlen(zero) + g_moin ?
				len - (ft_strlen(s) + ft_strlen(zero) + g_moin) : 0));
	space[(len > ft_strlen(s) + ft_strlen(zero) + g_moin ?
			len - (ft_strlen(s) + ft_strlen(zero) + g_moin) : 0)] = '\0';
	ft_putstr(space);
	if (g_moin)
		ft_putstr("-");
	ft_putstr(zero);
	ft_putstr(s);
	(*nb_car) += ft_strlen(s) + ft_strlen(zero) + ft_strlen(space) + g_moin;
	free(space);
	free(zero);
}

void	apply_int_flags(char *s, t_flags flag, int *nb_car)
{
	int		len;

	if ((!flag.prec || flag.prec_etoile) && flag.zero && !flag.sign)
		flag.prec = flag.width;
	if (flag.prec < -1 && flag.zero && flag.width > flag.prec && !flag.sign)
		flag.prec = flag.width - g_moin;
	if (flag.width > flag.prec)
		len = flag.width;
	else
		len = flag.prec;
	if (ft_strlen(s) > len)
		len = ft_strlen(s);
	if (flag.sign)
		neg_sign_int(s, flag, len, nb_car);
	else
		pos_sign_int(s, flag, len, nb_car);
}
