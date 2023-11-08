/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:09:28 by yaharkat          #+#    #+#             */
/*   Updated: 2023/11/08 13:19:37 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

# define HEX "0123456789abcdef"
# define MHEX "0123456789ABCDEF"

int	ft_printf(const char *s, ...);
int	ft_putnbr_base(size_t nbr, char *base);

#endif