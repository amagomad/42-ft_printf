/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:37:02 by amagomad          #+#    #+#             */
/*   Updated: 2025/05/14 05:55:26 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/put.h"

char	*ft_uitoa_base(unsigned int n, int uppercase)
{
	char	*base;
	char	buf[9];
	int		i;
	char	*result;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 8;
	buf[i] = '\0';
	if (n == 0)
		buf[--i] = '0';
	while (n)
	{
		buf[--i] = base[n % 16];
		n /= 16;
	}
	result = ft_strdup(&buf[i]);
	return (result);
}
