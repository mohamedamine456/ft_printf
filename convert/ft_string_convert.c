/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:14:24 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/04 17:06:36 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*ft_string_convert(char *str, va_list *param)
{
	char	*s;
	t_flags	flag;
	char	*tmp;

	tmp = s;
	s = ft_strdup("");
	initialize(&flag);
	check_flags(str, &flag, param);
	s = va_arg(*param, char *);
	if (flag.prec == -1)
		s = ft_strdup("");
	if (s == NULL)
		s = ft_strdup("(null)");
	if (flag.prec <= ft_strlen(s) && flag.prec > 0)
		s = ft_substr(s, 0, flag.prec);
	s = apply_string_flags(s, flag);
	free(tmp);
	return (s);
}

char	*neg_sign_string(char *s, int len)
{
	char	*str;

	str = malloc(len + 1);
	ft_memmove(str, ft_strdup(s), ft_strlen(s));
	ft_memset(str + ft_strlen(s), ' ', len - ft_strlen(s));
	str[len] = '\0';
	return (str);
}

char	*pos_sign_string(char *s, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(len + 1);
	ft_memset(str, ' ', len - ft_strlen(s));
	ft_memmove(str + len - ft_strlen(s), ft_strdup(s), ft_strlen(s));
	str[len] = '\0';
	return (str);
}

char	*apply_string_flags(char *s, t_flags flag)
{
	int		len;

	if (ft_strlen(s) > flag.width)
		len = ft_strlen(s);
	else
		len = flag.width;
	if (flag.sign)
		return (neg_sign_string(s, len));
	else
		return (pos_sign_string(s, len));
}
