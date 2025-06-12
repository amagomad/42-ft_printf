/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagomad <amagomad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:13:03 by amagomad          #+#    #+#             */
/*   Updated: 2025/05/16 14:31:24 by amagomad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	print_sign_only(t_flags flags, t_nbr *nbr, int n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		nbr->sign_printed = 1;
	}
	else if (flags.plus)
	{
		count += ft_putchar('+');
		nbr->sign_printed = 1;
	}
	else if (flags.space)
	{
		count += ft_putchar(' ');
		nbr->sign_printed = 1;
	}
	return (count);
}

void	init_nbr(t_nbr *nbr, t_flags flags, int len, int n)
{
	nbr->sign_printed = 0;
	nbr->has_sign = (n < 0 || flags.plus || flags.space);
	nbr->digits = len - (n < 0);
	if (flags.precision > nbr->digits)
		nbr->prec_pad = flags.precision - nbr->digits;
	else
		nbr->prec_pad = 0;
	nbr->total_len = nbr->has_sign + nbr->prec_pad + nbr->digits;
	if (flags.width > nbr->total_len)
		nbr->width_pad = flags.width - nbr->total_len;
	else
		nbr->width_pad = 0;
}

static int	print_with_zeros(t_flags flags, t_nbr *nbr, int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		nbr->sign_printed = 1;
	}
	else if (flags.plus)
	{
		count += ft_putchar('+');
		nbr->sign_printed = 1;
	}
	else if (flags.space)
	{
		count += ft_putchar(' ');
		nbr->sign_printed = 1;
	}
	while (nbr->width_pad-- > 0)
		count += ft_putchar('0');
	return (count);
}

static int	print_with_spaces(t_flags flags, t_nbr *nbr, int n)
{
	int	count;

	count = 0;
	while (nbr->width_pad-- > 0)
		count += ft_putchar(' ');
	if (n < 0)
	{
		count += ft_putchar('-');
		nbr->sign_printed = 1;
	}
	else if (flags.plus)
	{
		count += ft_putchar('+');
		nbr->sign_printed = 1;
	}
	else if (flags.space)
	{
		count += ft_putchar(' ');
		nbr->sign_printed = 1;
	}
	return (count);
}

int	print_sign_and_padding_left(t_flags flags, t_nbr *nbr, unsigned int n)
{
	if (flags.zero && !flags.dot)
		return (print_with_zeros(flags, nbr, n));
	else
		return (print_with_spaces(flags, nbr, n));
}
