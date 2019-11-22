/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helping_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:27:52 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 22:26:06 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "convert.h"
#include <stdio.h>

char	ft_to_char(int n, char conv)
{
	if (n >= 0 && n <= 9)
		return ((char)(n + '0'));
	else
	{
		if (conv == 'x')
			return ((char)(n - 10 + 'a'));
		if (conv == 'X')
			return ((char)(n - 10 + 'A'));
	}
	return (0);
}

char	*ft_from_deci(int n ,char conv)
{
	char	*res;
	int		i;
	long nn;

	i = 0;
	nn = n;
	res = malloc(ft_nsize(n) + 1);
	if (n == 0)
		res[i++] = ft_to_char(0, conv);
	while (n > 0)
	{
		res[i++] = ft_to_char(n % 16, conv);
		n /= 16;
	}
	res[i] = '\0';
	ft_strrev(res + 2);
	return (res);
}

void	initialize(t_flags *fl)
{
	(*fl).sign = 0;
	(*fl).width = 0;
	(*fl).point = 0;
	(*fl).prec = 0;
	(*fl).etoile1 = 0;
	(*fl).etoile2 = 0;
	(*fl).zero = 0;
}

void	check_flags(char *str, t_flags *fl, char conv)
{
	int i;

	i = 0;
	while (str[i] == '-')
	{
		(*fl).sign = 1;
		i++;
	}
	if (str[i] == '0')
	{
		(*fl).zero = 1;
		i++;
	}
	if (((*fl).width = ft_atoi(str + i)))
		i += ft_strlen(ft_itoa(ft_atoi(str + i)));
	if (str[i] == '*')
	{
		(*fl).etoile1 = 1;
		i++;
	}
	if (str[i] == '.')
	{
		(*fl).point = 1;
		i++;
	}
	if (((*fl).prec = ft_atoi(str + i)))
		i += ft_strlen(ft_itoa(ft_atoi(str + i)));
	if (str[i] == '*')
	{
		(*fl).etoile2 = 1;
		i++;
	}
}
