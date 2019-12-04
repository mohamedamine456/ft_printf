/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:48:40 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/04 17:05:04 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

char	*ft_pointer_convert(char *str, va_list *param)
{
	char				*s;
	unsigned long long	nb;
	t_flags				flag;
	char				*tmp;

	tmp = s;
	s = ft_strdup("");
	initialize(&flag);
	check_flags(str, &flag, param);
	nb = va_arg(*param, long long);
	s = ft_from_deci(nb, 'x');
	s = apply_pointer_flags(s , flag);
	free(tmp);
	return (s);
}

char	*neg_sign_pointer(char *s, t_flags flag, int len)
{
	char	*str;

	str = malloc(len + 3);
	ft_memmove(str, ft_strdup("0x"), 2);
	ft_memset(str + 2, '0', (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0));
	ft_memmove(str + 2 + (flag.prec > ft_strlen(s) ?
				flag.prec - ft_strlen(s) : 0), ft_strdup(s), ft_strlen(s));
	ft_memset(str + 2 + (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)),
			' ', len - 2 - (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)));
	str[len + 2] = '\0';
	return (str);
}

char	*pos_sign_pointer(char *s, t_flags flag, int len)
{
	char    *str;
	int     i;
	
	i = 0;
	str = malloc(len + 3);
	ft_memset(str, ' ', (flag.prec > ft_strlen(s) ?
				len - flag.prec : len - ft_strlen(s)) - 2);
	i = len - (flag.prec > ft_strlen(s) ? flag.prec : ft_strlen(s)) - 2;
	ft_memmove(str + (len == ft_strlen(s) || i < 0 ? 0 : i), ft_strdup("0x"), 2);
	if (i < 0)
		i = 0;
	i += 2;
	while (i < len - ft_strlen(s))
	{
		str[i] = '0';
		i++;
	}
	ft_memmove(str + i, ft_strdup(s), ft_strlen(s));
	str[len + 2] = '\0';
	return (str);
}

char	*apply_pointer_flags(char *s, t_flags flag)
{
	char	*str;
	int		len;

	if (flag.width > flag.prec)
		len = flag.width;
	else
		len = flag.prec;
	if (ft_strlen(s) > len)
		len = ft_strlen(s);
	str = malloc(len + 1);
	if (flag.sign)
		return (neg_sign_pointer(s, flag, len));
	else
		return (pos_sign_pointer(s, flag, len));
	str[len] = '\0';
	return (str);
}
