/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:13:03 by amagomad          #+#    #+#             */
/*   Updated: 2025/06/12 20:02:35 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "lib/includes/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_flags
{
	int		plus;
	int		space;
	int		hash;
	int		width;
	int		zero;
	int		minus;
	int		dot;
	int		precision;
}	t_flags;

typedef struct s_nbr
{
	int		sign_printed;
	int		has_sign;
	int		digits;
	int		prec_pad;
	int		total_len;
	int		width_pad;
}	t_nbr;

	// MAPPING

typedef int		(*t_func)(va_list *args, t_flags flags, char spec);
int				ft_printf(const char *format, ...);

void			init_dispatch(t_func *dispatch);
int				print_nbr(va_list *args, t_flags flags, char spec);
int				print_str(va_list *args, t_flags flags, char spec);
int				print_char(va_list *args, t_flags flags, char spec);
int				print_unsigned(va_list *args, t_flags flags, char spec);
int				print_hex(va_list *args, t_flags flags, char spec);
int				print_ptr(va_list *args, t_flags flags, char spec);
int				print_percent(va_list *args, t_flags flags, char spec);

	// UTILS

int				print_format(va_list args, const char *format);
int				handle_format(va_list *args, const char *format, int *i);
int				str_minus(t_flags flags, char *str);
int				hex_padding_right(t_flags flags, int len);
int				unsigned_write_with_padding(t_flags flags, int len, char *str);
void			init_nbr(t_nbr *nbr, t_flags flags, int len, int n);
int				print_sign_only(t_flags flags, t_nbr *nbr, int n);
int				print_sign_and_padding_left(t_flags flags, t_nbr *nbr,
					unsigned int n);
int				hex_padding_left(t_flags flags, char *str, int prefix,
					int *len);
int				hex_write_number(t_flags flags, unsigned int n, char spec,
					char **str);

#endif