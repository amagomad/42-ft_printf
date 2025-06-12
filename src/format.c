/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:13:03 by amagomad          #+#    #+#             */
/*   Updated: 2025/06/12 19:59:08 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	init_widthanddot(t_flags *flags, const char *format, int *i)
{
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		flags->width = flags->width * 10 + (format[*i] - '0');
		(*i)++;
	}
	if (format[*i] == '.')
	{
		flags->dot = 1;
		(*i)++;
		flags->precision = 0;
		while (format[*i] >= '0' && format[*i] <= '9')
		{
			flags->precision = flags->precision * 10 + (format[*i] - '0');
			(*i)++;
		}
	}
	return ((*i));
}

static int	init_flags(t_flags *flags, const char *format, int *i)
{
	while (format[*i] == '+' || format[*i] == ' '
		|| format[*i] == '#' || format[*i] == '0'
		|| format[*i] == '-')
	{
		if (format[*i] == ' ')
			flags->space = 1;
		if (format[*i] == '+')
		{
			flags->plus = 1;
			flags->space = 0;
		}
		if (format[*i] == '#')
			flags->hash = 1;
		if (format[*i] == '0')
			flags->zero = 1;
		if (format[*i] == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		(*i)++;
	}
	return ((*i));
}

static void	flags_zero(t_flags *flags)
{
	flags->dot = 0;
	flags->hash = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->width = 0;
	flags->zero = 0;
}

int	handle_format(va_list *args, const char *format, int *i)
{
	int				count;
	static int		init;
	static t_func	dispatch[128];
	t_flags			flags;

	count = 0;
	flags_zero(&flags);
	if (!init)
	{
		init_dispatch(dispatch);
		init = 1;
	}
	(*i) = init_flags(&flags, format, i);
	(*i) = init_widthanddot(&flags, format, i);
	if (dispatch[(int)format[*i]])
		count += dispatch[(int)format[*i]](args, flags, format[*i]);
	return (count);
}

int	print_format(va_list args, const char *format)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_format(&args, format, &i);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}
