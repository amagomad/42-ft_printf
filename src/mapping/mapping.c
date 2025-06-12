/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:13:03 by amagomad          #+#    #+#             */
/*   Updated: 2025/06/12 20:01:09 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	print_padding_right(t_flags flags, t_nbr *nbr)
{
	int		count;

	count = 0;
	if (flags.minus)
	{
		while (flags.width > nbr->total_len)
		{
			count += ft_putchar(' ');
			flags.width--;
		}
	}
	return (count);
}

int	print_nbr(va_list *args, t_flags flags, char spec)
{
	int		n;
	int		count;
	char	*str;
	int		len;
	t_nbr	nbr;

	(void)spec;
	count = 0;
	n = va_arg(*args, int);
	if (flags.dot && flags.precision == 0 && n == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(n);
	len = ft_strlen(str);
	init_nbr(&nbr, flags, len, n);
	if (!flags.minus)
		count += print_sign_and_padding_left(flags, &nbr, n);
	else
		count += print_sign_only(flags, &nbr, n);
	while (nbr.prec_pad--)
		count += ft_putchar('0');
	count += ft_putstr(str + (n < 0 && nbr.sign_printed));
	free(str);
	count += print_padding_right(flags, &nbr);
	return (count);
}

int	print_unsigned(va_list *args, t_flags flags, char spec)
{
	unsigned int	n;
	char			*str;
	int				len;
	int				count;

	n = va_arg(*args, unsigned int);
	count = 0;
	(void)spec;
	if (flags.dot && flags.precision == 0 && n == 0)
		str = ft_strdup("");
	else
		str = ft_uitoa(n);
	len = ft_strlen(str);
	count += unsigned_write_with_padding(flags, len, str);
	free(str);
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

int	print_hex(va_list *args, t_flags flags, char spec)
{
	unsigned int	n;
	char			*str;
	int				len;
	int				count;
	int				prefix;

	n = va_arg(*args, unsigned int);
	prefix = 0;
	if (flags.hash && n != 0)
		prefix = 2;
	if (flags.dot && flags.precision == 0 && n == 0)
		str = ft_strdup("");
	else
		str = ft_uitoa_base(n, spec == 'X');
	count = hex_padding_left(flags, str, prefix, &len);
	count += hex_write_number(flags, n, spec, &str);
	count += hex_padding_right(flags, len);
	return (count);
}
