/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:38:12 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/20 22:43:54 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

char	*ft_char_convert(char *str, int nb)
{
	char	*s;
	char	c;

	c = nb;
	s = malloc(2);
	//s = ft_apply_char_flags(c);
	s[0] = c;
	s[1] = '\0';
	return (s);
}
