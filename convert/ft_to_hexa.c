/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:43:48 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/20 23:00:59 by mlachheb         ###   ########.fr       */
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
	res = malloc(ft_nsize(n) + 3);
	res[i++] = '0';
	res[i++] = 'x';
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
