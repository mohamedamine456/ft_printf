/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:19:39 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/07 21:07:14 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

void	ft_unsint_convert(char *str, va_list *param, int *nb_car)
{
	char			*s;
	unsigned int	nb;
	int				moin;
	t_flags			flag;

	moin = 0;
	initialize(&flag);
	check_flags(str, &flag, param);
	nb = va_arg(*param, int);
	if (flag.prec == -1 && flag.vide == 1 && nb == 0)
		s = ft_strdup("");
	else
		s = ft_itoa(nb);
	apply_unsint_flags(s, flag, nb_car);
	free(s);
}

void	neg_sign_unsint(char *s, t_flags flag, int len, int *nb_car)
{
	char	*str;

	str = malloc(len + 1);
	ft_memset(str, '0', (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0));
	ft_memmove(str + (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0), s, ft_strlen(s));
	ft_memset(str + (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)),
			' ', len - (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)));
	str[len] = '\0';
	ft_putstr(str);
	(*nb_car) += ft_strlen(str);
	free(str);
}

void	pos_sign_unsint(char *s, t_flags flag, int len, int *nb_car)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(len + 1);
	ft_memset(str, ' ', (flag.prec > ft_strlen(s) ?
				len - flag.prec : len - ft_strlen(s)));
	i = len - (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s));
	while (i < len - ft_strlen(s))
	{
		str[i] = '0';
		i++;
	}
	ft_memmove(str + len - ft_strlen(s), s, ft_strlen(s));
	str[len] = '\0';
	ft_putstr(str);
	(*nb_car) += ft_strlen(str);
	free(str);
}

void	apply_unsint_flags(char *s, t_flags flag, int *nb_car)
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
		neg_sign_unsint(s, flag, len, nb_car);
	else
		pos_sign_unsint(s, flag, len, nb_car);
}
