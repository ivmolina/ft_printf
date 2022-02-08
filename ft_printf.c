/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmolina <ivmolina@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:44:33 by ivmolina          #+#    #+#             */
/*   Updated: 2022/02/08 12:18:03 by ivmolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_type(va_list ap, size_t *j, char c);

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	j;
	va_list	ap;
	char	*str2;

	i = 0;
	j = 0;
	str2 = (char *)str;
	va_start(ap, str);  // The argument last is the name of the last argument before the variable argument list, that is, the last argument of which the calling function knows the type. 
						// Es el ultimo argumento para saber con cual debe comenzar a empezar a leer el primer argumento de la lista.
	while (str2 && i < ft_strlen(str))
	{
		if (*str2 == '%')
		{
			str2++;
			ft_print_type(ap, &j, *str2);
			i++;
		}
		else
			j = j + ft_putchar_fd(*str2, 1);
		str2++;
		i++;
	}
	va_end (ap);
	return (j);
}

void	ft_print_type(va_list ap, size_t *j, char c)
{
	if (c == 'c')
		*j += ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		*j += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (c == 'p')
	{
		*j += ft_putstr_fd("0x", 1);
		*j += ft_putnbr_base_n((unsigned long long)va_arg(ap, void *),
				"0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		*j += ft_putnbr_base(va_arg(ap, int), "0123456789", 1);
	else if (c == 'u')
		*j += ft_putnbr_base(va_arg(ap, int), "0123456789", 0);
	else if (c == 'x')
		*j += ft_putnbr_base(va_arg(ap, int), "0123456789abcdef", 0);
	else if (c == 'X')
		*j += ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF", 0);
	else
		*j += ft_putchar_fd(c, 1);
}
