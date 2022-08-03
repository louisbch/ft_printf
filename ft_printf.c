/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:32:19 by lbouchon          #+#    #+#             */
/*   Updated: 2022/08/03 13:07:09 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_args(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_printptr(va_arg(args, unsigned long));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_print_perc();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_search_args(args, format[i + 1]);
			i++;
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end (args);
	return (len);
}

#include <stdio.h>

int main ()
{
	char	str[] = "Je vais bien";
	
	ft_printf("%s\n", str);
	printf("%s\n", str);
	printf("\n");
	
	ft_printf("%p\n", "A20456");
	printf("%p\n", "A20456");
	printf("\n");
	
	ft_printf("%%\n");
	printf("%%\n");
	printf("\n");
	
	ft_printf("%d\n", 1045);
	printf("%d\n", 1045);
	printf("\n");
	
	ft_printf("%u\n", 1068);
	printf("%u\n", 1068);
	printf("\n");
	
	ft_printf("%c\n", 'B');
	printf("%c\n", 'B');
	printf("\n");
	
	ft_printf("%x\n", 146);
	printf("%x\n", 146);
}
