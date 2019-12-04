/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:46:37 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/04 16:58:31 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list param;
	char	*all;

	va_start(param, str);
	all = ft_strdup("");
	ft_printf_helper(str, &param, &all);
	va_end(param);
	ft_putstr(all);
	return (ft_strlen(all));
}

int		ft_printf_helper(const char *str, va_list *param, char **all)
{
	char	*s;
	char	conv;
	char	*tmp;

	while (*str)
	{
		if (*str == '%' && (conv = ft_isconvertion(str + 1)))
		{
			tmp = s;
			s = ft_convert(&str, param, conv);
			tmp = *all;
			*all = ft_strjoin(*all, s);
			free(tmp);
		}
		else
		{
			if (*str == '%' && *(str + 1) == '%')
				str++;
			tmp = *all;
			*all = ft_addchar(*all, *str);
			free(tmp);
		}
		str++;
	}
	return (ft_strlen(*all));
}
