/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:35:18 by lbouchon          #+#    #+#             */
/*   Updated: 2022/08/03 10:56:08 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printchar(int c);
int		ft_print_perc(void);
int		ft_printstr(char *str);
int		ft_search_args(va_list args, const char format);
int		ft_printnbr(int n);
int		ft_print_hex(unsigned int nb, const char format);
int		ft_print_unsigned(unsigned int nb);
int		ft_printptr(unsigned long nb);
int		ft_printf(const char *format, ...);

int		ft_ptr_len(unsigned long nb);
void	ft_putptr(unsigned long nb);
void	ft_putstr(char *str);
int		ft_hex_len(unsigned int nb);
void	ft_put_hex(unsigned int nb, const char format);
char	*ft_itoa(int n);

#endif