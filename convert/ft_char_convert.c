/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:38:12 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/25 14:44:45 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

char	*ft_char_convert(char *str, va_list *param)
{
	char	*s;
	t_flags	flag;

	s = ft_strdup("");
	initialize(&flag);
	check_flags(str, &flag, param);
	s = ft_addchar(s, va_arg(*param, int));
	s = apply_char_flags(s, flag);
	return (s);
}

char	*apply_char_flags(char *s, t_flags flag)
{
	char	*str;
	int		len;

	if (ft_strlen(s) < flag.width)
		len = flag.width;
	else
		len = ft_strlen(s);
	str = malloc(len + 1);
	if (flag.sign)
	{
		str = ft_strdup(s);
		ft_memset(str + ft_strlen(s), ' ', len - ft_strlen(s));
	}
	else
	{
		ft_memset(str, ' ', len - ft_strlen(s));
		ft_memmove(str + len - ft_strlen(s), s, ft_strlen(s));
	}
	str[len] = '\0';
	return (str);
}
