/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:09:17 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/07 20:04:19 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// 	return (1);
// }

// int	ft_putperc_fd(int fd)
// {
// 	write(fd, "%", 1);
// 	return (1);
// }

static int	ft_formats_check(const char *str, va_list args)
{
	if (*str == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (*str == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (*str == 'p')
		return (ft_ptr_to_hex(va_arg(args, void *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_itoa_write(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_unsigned_to_str(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (ft_to_hex(va_arg(args, unsigned int), 'x'));
	else if (*str == 'X')
		return (ft_to_hex(va_arg(args, unsigned int), 'X'));
	else if (*str == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	int		temp;
	int		temp_str;

	length = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX%", *str))
			{
				temp = ft_formats_check(str, args);
				if (temp < 0)
					return (-1);
				length += temp;
			}
		}
		else
		{
			temp_str = ft_putchar_fd(*str, 1);
			if (temp_str < 0)
				return (-1);
			length++;
		}
		str++;
	}
	va_end(args);
	return (length);
}

// int main(void)
// {
// 	int i = 0;
// 	int j = 0;
//     char c = 'A';
    // char *str = NULL;
//     int num = 3294967295;
//     unsigned int u_num = 3294967295;
//     void *ptr = (void *)"12345";
// 	unsigned int hex = 10000;

// 	int num1 = 0;

//     num1 = ft_printf("%c ", 'x');
//     printf("%c", 'x');
// 	printf("%d", num1);

    // ft_printf(" NULL %s NULL \n", NULL);
    // printf(" NULL %s NULL ", NULL);

//     ft_printf("This is a d integer: %d\n", num);
//     printf("This is a d integer: %d\n", num);

// 	ft_printf("This is an i integer: %i\n", num);
//     printf("This is an i integer: %i\n", num);

//     ft_printf("This is an unsigned integer: %u\n", u_num);
//     printf("This is an unsigned integer: %u\n", u_num);

    // i = ft_printf("\x01\x02\a\v\b\f\r\n");
    // j = printf("\x01\x02\a\v\b\f\r\n");
	// printf("%d\n", i);
	// printf("%d\n", j);

    // ft_printf("Hexadecimal number (lowercase): %x\n", num);
    // printf("Hexadecimal number (lowercase): %x\n", num);

    // ft_printf("%X", -10);
    // printf("%X", -10);

    // ft_printf("%%%c", 'x');
    // printf("%%%c", 'x');

//     ft_printf("%%c\n");
//     printf("%%c\n");
//  	return (0);
// }
