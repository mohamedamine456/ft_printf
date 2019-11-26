/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_trait.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 22:59:46 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/25 00:26:42 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*apply_flags(char *s, t_flags flag)
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
		if (flag.zero)
			ft_memset(str + ft_strlen(s), '0', len - ft_strlen(s));
		else
			ft_memset(str + ft_strlen(s), ' ', len - ft_strlen(s));
	}
	else
	{
		if (flag.zero)
			ft_memset(str, '0', len - ft_strlen(s));
		else
			ft_memset(str, ' ', len - ft_strlen(s));
		ft_memmove(str + len - ft_strlen(s), s, ft_strlen(s));
	}
	str[len] = '\0';
	return (str);
}
