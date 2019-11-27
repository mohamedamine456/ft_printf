/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:43:32 by mlachheb          #+#    #+#             */
/*   Updated: 2019/11/26 05:50:11 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H
# include <stdarg.h>
# include "../libft/libft.h"

typedef	struct	s_flags
{
	int	sign;
	int	width;
	int	prec;
	int	zero;
}				t_flags;
char			*ft_int_convert(char *str, va_list *param);
char			*ft_char_convert(char *str, va_list *param);
char			*ft_hexa_convert(char *str, va_list *param, char conv);
char			*ft_pointer_convert(char *str, va_list *param);
char			*ft_sint_convert(char *str, va_list *param);
char			*ft_unsint_convert(char *str, va_list *param);
char			*ft_string_convert(char *str, va_list *param);
char			*ft_from_deci(long long nb, char conv);
void			initialize(t_flags *fl);
void			check_char_flags(char *str, t_flags *fl, va_list *param);
char			*apply_char_flags(char *s, t_flags flag);
void			check_flags(char *str, t_flags *fl, va_list *param);
char			*apply_hexa_flags(char *s, t_flags flag);
char			*apply_pointer_flags(char *s, t_flags flag);
char            *apply_int_flags(char *s, t_flags flag);

#endif
