/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:56:46 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/04 17:04:30 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

char	*ft_int_convert(char *str, va_list *param)
{
	char	*s;
	long	nb;
	int		moin;
	t_flags	flag;
	char	*tmp;

	moin = 0;
	tmp = s;
	s = ft_strdup("");
	initialize(&flag);
	check_flags(str, &flag, param);
	nb = va_arg(*param, int);
	if (nb < 0)
	{
		moin = 1;
		nb *= -1;
	}
	if (flag.prec == -1 && nb == 0)
		s = ft_strdup("");
	else
		s = ft_itoa(nb);
	s = apply_int_flags(s, flag, moin, str);
	free(tmp);
	return (s);
}

char	*neg_sign_int(char *s, t_flags flag, int len, int moin)
{
	char	*str;

	str = malloc(len + 1 + moin);
	if (moin)
		str[0] = '-';
	ft_memset(str + moin, '0', (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0));
	ft_memmove(str + (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0) + moin, ft_strdup(s), ft_strlen(s));
	ft_memset(str + moin + (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)),
			' ', len - (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)) - moin);
	str[len + (len == flag.width && len > (ft_strlen(s) + moin) ? 0 : moin)] = '\0';
	return (str);
}

int		check_prec_zero(t_flags flag, char *str)
{
	int		nb;
	
	while (*str != '.' && *str != 'd' && *str != '\0')
		str++;
	nb = ft_atoi(str + 1);
	if (nb == 0 && *(str + 1) != '*' && *(str + 1) != '0' &&
			flag.prec == flag.width && flag.zero && flag.width != 0)
		return (1);
	return (0);
}

char	*pos_sign_int(char *s, t_flags flag, int len, int moin, char *sttr)
{
	char	*str;
	char	*zero;
	char	*space;
	int		i;
	int		precc;

	i = 0;
	str = ft_strdup(s);
	zero = malloc((flag.prec > ft_strlen(s) ? flag.prec - ft_strlen(s) : 0) + 1);
	precc = check_prec_zero(flag, sttr);
	ft_memset(zero, '0', (flag.prec > ft_strlen(s) ? flag.prec -
				ft_strlen(s) : 0) - (precc && moin ? moin : 0));
	zero[(flag.prec > ft_strlen(s) ? flag.prec - ft_strlen(s) : 0)] = '\0';
	str = ft_strjoin(zero, str);
	if (moin)
		str = ft_strjoin("-", str);
	space = malloc((len > ft_strlen(str) ? len - ft_strlen(str) : 0) + 1);
	ft_memset(space, ' ', (len > ft_strlen(str) ? len - ft_strlen(str) : 0));
	space[(len > ft_strlen(str) ? len - ft_strlen(str) : 0)] = '\0';
	str = ft_strjoin(space, str);
	return (str);
}

char	*apply_int_flags(char *s, t_flags flag, int moin, char *str)
{
	int		len;

	if (!flag.prec && flag.zero && !flag.sign)
		flag.prec = flag.width;
	if (flag.width > flag.prec)
		len = flag.width;
	else
		len = flag.prec;
	if (ft_strlen(s) > len)
		len = ft_strlen(s);
	if (flag.sign)
		return (neg_sign_int(s, flag, len, moin));
	else
		return (pos_sign_int(s, flag, len, moin, str));
}
