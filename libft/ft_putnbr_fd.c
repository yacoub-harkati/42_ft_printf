/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:00:18 by yaharkat          #+#    #+#             */
/*   Updated: 2023/11/07 21:11:40 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compute_len(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 0;
	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	else if (n == 0)
		return (ft_putchar_fd('0', fd));
	else
	{
		if (n < 0)
		{
			sign = ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n < 10)
		{
			ft_putchar_fd((n + 48), fd);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd((n % 10) + 48, fd);
		}
	}
	return (compute_len(n) + sign);
}
