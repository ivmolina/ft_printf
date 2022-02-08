/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmolina <ivmolina@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:30:32 by ivmolina          #+#    #+#             */
/*   Updated: 2022/02/08 12:18:47 by ivmolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_type(va_list ap, size_t *j, char c);
size_t	ft_strlen(const char *str);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putnbr_base(int nbr, char *base, int p);
size_t	ft_putnbr_base_n(unsigned long long nbr, char *base);

#endif