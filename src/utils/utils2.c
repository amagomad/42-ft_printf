/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:13:03 by amagomad          #+#    #+#             */
/*   Updated: 2025/06/12 15:19:46 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	hex_padding_left(t_flags flags, char *str, int prefix, int *len)
{
	int		count;

	count = 0;
	(*len) = ft_strlen(str);
	if (flags.precision > (*len))
		(*len) = flags.precision;
	(*len) += prefix;
	if (!flags.minus)
	{
		while (flags.width > (*len))
		{
			count += ft_putchar(' ');
			flags.width--;
		}
	}
	return (count);
}

int	hex_write_number(t_flags flags, unsigned int n, char spec, char **str)
{
	int		count;

	count = 0;
	if (flags.hash && n != 0)
	{
		if (spec == 'X')
			count += ft_putstr("0X");
		else
			count += ft_putstr("0x");
	}
	while (flags.precision > (int)ft_strlen((*str)))
	{
		count += ft_putchar('0');
		flags.precision--;
	}
	count += ft_putstr((*str));
	free((*str));
	return (count);
}

int	hex_padding_right(t_flags flags, int len)
{
	int		count;

	count = 0;
	if (flags.minus)
	{
		while (flags.width > len)
		{
			count += ft_putchar(' ');
			flags.width--;
		}
	}
	return (count);
}

int	unsigned_write_with_padding(t_flags flags, int len, char *str)
{
	int		count;

	count = 0;
	if (flags.precision > len)
		len = flags.precision;
	if (!flags.minus)
	{
		while (flags.width > len)
		{
			count += ft_putchar(' ');
			flags.width--;
		}
	}
	while (flags.precision > (int)ft_strlen(str))
	{
		count += ft_putchar('0');
		flags.precision--;
	}
	count += ft_putstr(str);
	return (count);
}

int	str_minus(t_flags flags, char *str)
{
	int		len;
	int		count;

	count = 0;
	len = ft_strlen(str);
	if (flags.dot && flags.precision < len)
		len = flags.precision;
	if (!flags.minus)
	{
		while (flags.width > len)
		{
			count += ft_putchar(' ');
			flags.width--;
		}
	}
	count += write(1, str, len);
	if (flags.minus)
	{
		while (flags.width > len)
		{
			count += ft_putchar(' ');
			flags.width--;
		}
	}
	return (count);
}
