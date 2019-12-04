/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:02:21 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/29 22:49:41 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "convert/convert.h"

int		ft_printf(const char *str, ...);
char	ft_isconvertion(const char *str);
char	*ft_convert(const char **str, va_list *param, char conv);
int     ft_printf_helper(const char *str, va_list *param, char **all);

#endif
