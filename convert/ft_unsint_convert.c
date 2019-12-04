/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:19:39 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/04 17:07:04 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_unsint_convert(char *str, va_list *param)
{
	char    *s;
	unsigned int     nb;
	int     moin;
	t_flags flag;
	char	*tmp;

	moin = 0;
	tmp = s;
	s = ft_strdup("");
	initialize(&flag);
	check_flags(str, &flag, param);
	nb = va_arg(*param, int);
	s = ft_itoa(nb);
	s = apply_unsint_flags(s, flag);
	free(tmp);
	return (s);
}

char	*neg_sign_unsint(char *s, t_flags flag, int len)
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

char	*pos_sign_unsint(char *s, t_flags flag, int len)
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

char	*apply_unsint_flags(char *s, t_flags flag)
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
		return (neg_sign_unsint(s, flag, len));
	else
		return (pos_sign_unsint(s, flag, len));
}
