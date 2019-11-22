/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:14:24 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/22 13:29:59 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "../libft/libft.h"

char	*ft_string_convert(char *str, va_list *param)
{
	char	*s;

	s = va_arg(*param, char *);
	str = NULL;
	return (s);
}
