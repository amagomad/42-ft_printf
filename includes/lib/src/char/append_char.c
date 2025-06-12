/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:13:03 by amagomad          #+#    #+#             */
/*   Updated: 2025/05/14 01:06:31 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

char	*append_char(char *old_str, char c)
{
	int		len;
	char	*new_str;
	int		i;

	len = 0;
	if (old_str)
		len = ft_strlen(old_str);
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (old_str && old_str[i])
	{
		new_str[i] = old_str[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = '\0';
	if (old_str)
		free(old_str);
	return (new_str);
}
