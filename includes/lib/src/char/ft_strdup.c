/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 07:59:01 by amagomad          #+#    #+#             */
/*   Updated: 2025/05/14 01:05:30 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	i = ft_strlen((char *)s);
	copy = malloc(sizeof(char) * i + 1);
	if (copy != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			copy[i] = s[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}
