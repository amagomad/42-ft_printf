/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappiing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:13:03 by amagomad          #+#    #+#             */
/*   Updated: 2025/06/12 20:00:36 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	print_str(va_list *args, t_flags flags, char spec)
{
	char	*str;
	int		count;

	count = 0;
	(void)spec;
	str = va_arg(*args, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	count += str_minus(flags, str);
	return (count);
}

int	print_char(va_list *args, t_flags flags, char spec)
{
	char	c;
	int		count;

	count = 0;
	(void)spec;
	c = (char)va_arg(*args, int);
	if (!flags.minus)
		while (--flags.width > 0)
			count += ft_putchar(' ');
	count += ft_putchar(c);
	if (flags.minus)
		while (--flags.width > 0)
			count += ft_putchar(' ');
	return (count);
}

int	print_ptr(va_list *args, t_flags flags, char spec)
{
	(void)spec;
	(void)flags;
	return (ft_putptr(va_arg(*args, void *)));
}

int	print_percent(va_list *args, t_flags flags, char spec)
{
	(void)spec;
	(void)flags;
	(void)args;
	return (ft_putchar('%'));
}

void	init_dispatch(t_func *dispatch)
{
	dispatch['d'] = print_nbr;
	dispatch['i'] = print_nbr;
	dispatch['s'] = print_str;
	dispatch['c'] = print_char;
	dispatch['u'] = print_unsigned;
	dispatch['x'] = print_hex;
	dispatch['X'] = print_hex;
	dispatch['p'] = print_ptr;
	dispatch['%'] = print_percent;
}
