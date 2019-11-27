/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:39:48 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/26 15:42:52 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

char	*ft_hexa_convert(char *str, va_list *param, char conv)
{
	char			*s;
	unsigned int	nb;
	t_flags			flag;

	s = ft_strdup("");
	initialize(&flag);
	check_flags(str, &flag, param);
	nb = va_arg(*param, unsigned int);
	s = ft_from_deci(nb, conv);
	s = apply_hexa_flags(s, flag);
	return (s);
}

char	*neg_sign_hexa(char *s, t_flags flag, int len)
{
	char	*str;

	str = malloc(len + 1);
	ft_memset(str, '0', (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0));
	ft_memmove(str + (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0), ft_strdup(s), ft_strlen(s));
	ft_memset(str + (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)),
			' ', len - (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)));
	str[len] = '\0';
	return (str);
}

char	*pos_sign_hexa(char *s, t_flags flag, int len)
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
	ft_memmove(str + len - ft_strlen(s), ft_strdup(s), ft_strlen(s));
	str[len] = '\0';
	return (str);
}

char	*apply_hexa_flags(char *s, t_flags flag)
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
		return (neg_sign_hexa(s, flag, len));
	else
		return (pos_sign_hexa(s, flag, len));
}
