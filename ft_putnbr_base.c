/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmolina <ivmolina@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:23:14 by potero-d          #+#    #+#             */
/*   Updated: 2022/02/07 16:25:03 by ivmolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(int nbr, char *base, int p)
{
	unsigned int	m;
	unsigned int	n;
	char			c;
	size_t			i;

	m = ft_strlen(base);
	i = 0;
	if (p == 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = nbr * -1;
			i++;
		}
	}
	n = nbr;
	if (n >= m)
		i += ft_putnbr_base((n / m), base, p);
	c = base[n % m];
	i++;
	write(1, &c, 1);
	return (i);
}
