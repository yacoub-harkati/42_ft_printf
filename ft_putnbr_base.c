/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 06:42:21 by yaharkat          #+#    #+#             */
/*   Updated: 2023/11/08 13:19:48 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(size_t nbr, char *base)
{
	size_t	base_len;
	int		count;

	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += ft_putchar_fd(base[nbr % base_len], 1);
	return (count);
}
