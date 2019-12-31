/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:43:32 by mlachheb          #+#    #+#             */
/*   Updated: 2019/12/07 21:25:41 by mlachheb         ###   ########.fr       */
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
	int vide;
	int prec_etoile;
}				t_flags;
void			ft_int_convert(char *str, va_list *param, int *nb_car);
void			ft_char_convert(char *str, va_list *param, int *nb_car);
void			ft_hexa_convert(char *str, va_list *param,
		char conv, int *nb_car);
void			ft_pointer_convert(char *str, va_list *param, int *nb_car);
void			ft_sint_convert(char *str, va_list *param, int *nb_car);
void			ft_unsint_convert(char *str, va_list *param, int *nb_car);
void			ft_string_convert(char *str, va_list *param, int *nb_car);
void			ft_percent_convert(char *str, va_list *param, int *nb_car);
char			*ft_from_deci(unsigned long long nb, char conv);
void			initialize(t_flags *fl);
void			check_char_flags(char *str, t_flags *fl, va_list *param);
void			apply_char_flags(char s, t_flags flag, int *nb_car);
void			check_flags(char *str, t_flags *fl, va_list *param);
void			apply_hexa_flags(char *s, t_flags flag, int *nb_car);
void			apply_pointer_flags(char *s, t_flags flag, int *nb_car);
void			apply_int_flags(char *s, t_flags flag, int *nb_car);
void			apply_sint_flags(char *s, t_flags flag, int *nb_car);
void			apply_string_flags(char *s, t_flags flag, int *nb_car);
void			apply_unsint_flags(char *s, t_flags flag, int *nb_car);
void			apply_percent_flags(char s, t_flags flag, int *nb_car);

#endif
