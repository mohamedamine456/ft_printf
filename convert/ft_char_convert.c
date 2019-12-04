/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:38:12 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/04 17:00:41 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include <stdio.h>

char	*ft_char_convert(char *str, va_list *param)
{
	char	*s;
	t_flags	flag;
	char	*tmp;

	s = ft_strdup("");
	initialize(&flag);
	check_flags(str, &flag, param);
	tmp = s;
	s = ft_addchar(s, va_arg(*param, int));
	s = apply_char_flags(s, flag);
	free(tmp);
	return (s);
}

char	*apply_char_flags(char *s, t_flags flag)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (ft_strlen(s) < flag.width)
		len = flag.width;
	else
		len = ft_strlen(s);
	str = malloc(len + 1);
	if (flag.sign)
	{
		str = ft_memmove(str, ft_strdup(s), ft_strlen(s));
		while (i + ft_strlen(s) < len)
		{
			str[i + ft_strlen(s)] = ' ';
			i++;
		}
	}
	else
	{
		ft_memset(str, ' ', len - ft_strlen(s));
		ft_memmove(str + len - ft_strlen(s), s, ft_strlen(s));
	}
	str[len] = '\0';
	return (str);
}
