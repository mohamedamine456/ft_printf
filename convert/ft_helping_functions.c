/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helping_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:27:52 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/04 17:03:21 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

char	ft_to_char(unsigned long long n, char conv)
{
	if (n <= 9)
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

char	*ft_from_deci(unsigned long long n, char conv)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	tmp = res;
	res = malloc(ft_nsize(n) + 1);
	if (n == 0)
		res[i++] = ft_to_char(0, conv);
	while (n > 0)
	{
		res[i++] = ft_to_char(n % 16, conv);
		n /= 16;
	}
	res[i] = '\0';
	ft_strrev(res);
	free(tmp);
	return (res);
}

void	initialize(t_flags *fl)
{
	(*fl).sign = 0;
	(*fl).width = 0;
	(*fl).prec = 0;
	(*fl).zero = 0;
}

void	check_flags2(char *str, t_flags *fl, va_list *param)
{
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			(*fl).prec = va_arg(*param, int);
			str++;
		}
		else if (((*fl).prec = ft_atoi(str)) >= 0)
		{
			if ((!ft_isdigit(*str) || (*fl).prec == 0))
				(*fl).prec = -1;
			str += ft_strlen(ft_itoa(ft_atoi(str)));
		}
	}
}

void	check_flags(char *str, t_flags *fl, va_list *param)
{
	while (*str == '-')
	{
		(*fl).sign = 1;
		str++;
	}
	while (*str == '0')
	{
		(*fl).zero = 1;
		str++;
	}
	if (*str == '*')
	{
		(*fl).width = va_arg(*param, int);
		if ((*fl).width == 0)
			(*fl).zero = 1;
		if ((*fl).width < 0)
		{
			(*fl).sign = 1;
			(*fl).width *= -1;
		}
		str++;
	}
	else if (((*fl).width = ft_atoi(str)))
		str += ft_strlen(ft_itoa(ft_atoi(str)));
	check_flags2(str, fl, param);
}
