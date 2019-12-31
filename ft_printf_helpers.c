/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:46:41 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/10 17:36:16 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

char	ft_isconvertion(const char *str)
{
	int		i;
	char	c;

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

void	ft_convert(const char **str, va_list *param, char conv, int *nb_car)
{
	char	*s;

	(*str)++;
	s = (char *)*str;
	while (**str != conv)
		(*str)++;
	if (conv == 'd')
		ft_int_convert(s, param, nb_car);
	if (conv == 'c')
		ft_char_convert(s, param, nb_car);
	if (conv == 's')
		ft_string_convert(s, param, nb_car);
	if (conv == 'i')
		ft_int_convert(s, param, nb_car);
	if (conv == 'u')
		ft_unsint_convert(s, param, nb_car);
	if (conv == 'p')
		ft_pointer_convert(s, param, nb_car);
	if (conv == 'x' || conv == 'X')
		ft_hexa_convert(s, param, conv, nb_car);
	if (conv == '%')
		ft_percent_convert(s, param, nb_car);
}
