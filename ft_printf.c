/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 06:03:08 by yaharkat          #+#    #+#             */
/*   Updated: 2023/11/08 13:19:56 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_pointer(unsigned long long n)
{
	int	count;

	if (((void *)n) == ((void *)0))
		return (ft_putstr_fd("(nil)", 1));
	count = 0;
	count += ft_putstr_fd("0x", 1);
	count += ft_putnbr_base(n, HEX);
	return (count);
}

static int	proccess_conversion(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		return (ft_putchar_fd(va_arg(list, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(list, char *), 1));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(list, size_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(list, long), 1));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(list, unsigned int), "0123456789"));
	else if (c == 'x')
		return ((ft_putnbr_base(va_arg(list, unsigned int), HEX)));
	else if (c == 'X')
		return ((ft_putnbr_base(va_arg(list, unsigned int), MHEX)));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
		{
			count += proccess_conversion(s[i + 1], list);
			i++;
		}
		else
			count += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(list);
	return (count);
}
