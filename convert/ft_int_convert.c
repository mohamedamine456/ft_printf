/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:56:46 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/27 13:54:00 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

char	*ft_int_convert(char *str, va_list *param)
{
	char	*s;
	int		nb;
	t_flags	flag;

	s = ft_strdup("");
	initialize(&flag);
	check_flags(str, &flag, param);
	nb = va_arg(*param, int);
	s = ft_itoa(nb);
	s = apply_int_flags(s, flag);
	return (s);
}

char	*neg_sign_int(char *s, t_flags flag, int len)
{
	char	*str;
	int		j;

	j = 0;
	if (s[j] == '-')
		j++;
	str = malloc(len + 1 + j);
	if (j)
		str[0] = '-';
	ft_memset(str + j, '0', (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0) + j);
	ft_memmove(str + (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s + j) : 0) + j, ft_strdup(s + j), ft_strlen(s + j));
	ft_memset(str + (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)),
			' ', len - (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)));
	str[len + j] = '\0';
	return (str);
}

char	*pos_sign_int(char *s, t_flags flag, int len)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s[j] == '-')
		j++;
	str = malloc(len + 1 + j);
	ft_memset(str, ' ', len - (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(
					s + j)) - (flag.width > flag.prec && len > ft_strlen(s + j) ? j : 0));
	i = len - (flag.prec > ft_strlen(s) ? flag.prec :
			ft_strlen(s + j)) - (flag.width > flag.prec && len
			> ft_strlen(s + j) ? j : 0);
	if (s[0] == '-')
		str[i] = s[0];
	while (i < len - ft_strlen(s + (flag.prec > ft_strlen(s + j) ? j : 0)) -
			(flag.width >= flag.prec && len > ft_strlen(s + j) ? j : 0))
	{
		str[i + j] = '0';
		i++;
	}
	ft_memmove(str + i + j, ft_strdup(s + j), ft_strlen(s));
	str[len + j] = '\0';
	return (str);
}

char	*apply_int_flags(char *s, t_flags flag)
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
		return (neg_sign_int(s, flag, len));
	else
		return (pos_sign_int(s, flag, len));
}
