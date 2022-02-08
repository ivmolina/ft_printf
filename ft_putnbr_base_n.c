/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmolina <ivmolina@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:23:14 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/07 16:31:13 by ivmolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base_n(unsigned long long nbr, char *base)
{
	unsigned long long	m;
	char				c;
	int					i;

	m = ft_strlen(base);
	i = 0;
	if (nbr >= m)
		i += ft_putnbr_base_n((nbr / m), base);
	c = base[nbr % m];
	i++;
	write(1, &c, 1);
	return (i);
}
