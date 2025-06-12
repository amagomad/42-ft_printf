/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nashxo <nashxo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:00:57 by amagomad          #+#    #+#             */
/*   Updated: 2025/05/14 05:02:41 by nashxo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

# include <stdlib.h>
# include <unistd.h>
# include "char.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_uputnbr(unsigned int n);
int		ft_putnbr(int n);
int		ft_putptr(void *ptr);
char	*ft_uitoa_base(unsigned int n, int uppercase);
int		ft_puthex(unsigned long long n, int uppercase);
int		ft_putstr(char *s);
int		ft_putchar(char c);

#endif