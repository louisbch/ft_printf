/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:26:51 by lbouchon          #+#    #+#             */
/*   Updated: 2022/08/03 10:44:05 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, format);
		ft_put_hex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_printchar(nb + '0');
		else
		{
			if (format == 'x')
				ft_printchar(nb - 10 + 'a');
			if (format == 'X')
				ft_printchar(nb - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int nb, const char format)
{
	if (nb == 0)
		write(1, "0", 1);
	else
		ft_put_hex(nb, format);
	return (ft_hex_len(nb));
}
