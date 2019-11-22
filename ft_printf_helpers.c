/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:46:41 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 13:32:09 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

char	ft_isconvertion(const char *str)
{
	int i;
	char c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isflag(str[i]))
			i++;
		else
		{
			if ((c = ft_isformat(str[i])))
				return (c);
			else
				return (c);
		}
	}
	return (c);
}

char	*ft_convert(const char **str, va_list *param, char conv)
{
	char	*s;

	(*str)++;
	s = (char *)*str;
	while (**str != conv)
		(*str)++;
	if (conv == 'd')
		return (ft_int_convert(s, param));
	if (conv == 'c')
		return (ft_char_convert(s, param));
	if (conv == 's')
		return (ft_string_convert(s, param));
	if (conv == 'i')
		return (ft_sint_convert(s, param));
	if (conv == 'u')
		return (ft_unsint_convert(s, param));
	if (conv == 'p')
		return (ft_pointer_convert(s, param));
	if (conv == 'x' || conv == 'X')
		return (ft_hexa_convert(s, param, conv));
	return (0);
}
