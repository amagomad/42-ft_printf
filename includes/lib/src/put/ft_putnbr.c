/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:20:00 by amagomad          #+#    #+#             */
/*   Updated: 2025/05/14 05:55:18 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/put.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_putstr("-2147483648");
		return (count);
	}
	else
	{
		if (n < 0)
		{
			count += ft_putchar('-');
			n = -n;
		}
		if (n > 9)
		{
			count += ft_putnbr(n / 10);
		}
		count += ft_putchar((n % 10 + '0'));
	}
	return (count);
}
