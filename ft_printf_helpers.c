/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:46:41 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/19 13:11:45 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_isconvertion(const char *str)
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

char	*ft_convert(const char *str, va_list *param, char conv)
{
	if (conv == 'd')
		return (ft_int_convert(str, va_arg(*param, int)));
	if (conv == 'c')
		return (ft_char_convert(str, va_arg(*param, int)));
	if (conv == 's')
		return (ft_string_convert(str, va_arg(*param, char *)));
	if (conv == 'i')
		return (ft_sint_convert(str, va_arg(*param, int)));
	if (conv == 'u')
		return (ft_unsint_convert(str, va_arg(*pram, unsigned int)));
	if (conv == 'p')
		return (ft_pointer_convert(str, va_arg(*param, int)));
	if (conv == 'x' || conv == 'X')
		return (ft_hexa_convert(str, va_arg(*param, int)));
	return (0);
}
