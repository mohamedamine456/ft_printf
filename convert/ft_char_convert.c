/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:38:12 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 22:27:41 by mlachheb         ###   ########.fr       */
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
	check_flags(str, &flag, 'c');
	if (flag.etoile1)
		flag.etoile1 = va_arg(*param, int);
	if (flag.etoile2)
		flag.etoile2 = va_arg(*param, int);
	printf("\n|sign :%d|\n", flag.sign);
	printf("\n|width :%d|\n", flag.width);
	printf("\n|point :%d|\n", flag.point);
	printf("\n|precision :%d|\n", flag.prec);
	printf("\n|etoile1 :%d|\n", flag.etoile1);
	printf("\n|etoile2 :%d|\n", flag.etoile2);
	printf("\n|zero :%d|\n", flag.zero);
	s = ft_addchar(s, va_arg(*param, int));
	return (s);
}
