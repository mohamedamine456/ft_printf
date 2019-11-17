/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:46:37 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/17 21:29:33 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list param;
	int		i;
	char	*s;
	char	*all;
	char	*tmp;

	va_start(param, str);
	i = 0;
	all = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '%')
			if (ft_isconvertion(&str[i + 1]))
			{
				tmp = s;
				s = ft_convert(&str[i]);
				free(tmp);
				all = ft_strjoin(all, s);
			}
		i++;
	}
	return (ft_strlen(all));
}
