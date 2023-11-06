/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:09:17 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/06 16:39:15 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_formats_check(const char *str, va_list args)
{
	if (*str == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*str == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*str == 'p')
		ft_putstr_fd(ft_ptr_to_hex(va_arg(args, void *)), 1);
	else if (*str == 'd' || *str == 'i')
		ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
	else if (*str == 'u')
		ft_putstr_fd(ft_unsigned_to_str(va_arg(args, unsigned int)), 1);
	else if (*str == 'x')
		ft_putstr_fd(ft_to_hex(va_arg(args, unsigned int), 'x'), 1);
	else if (*str == 'X')
		ft_putstr_fd(ft_to_hex(va_arg(args, unsigned int), 'X'), 1);
	else if (*str == '%')
		ft_putperc_fd(*str, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_formats_check(str, args);
		}
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (0);
}

int main(void)
{
    char c = 'A';
    char *str = "Hello, World!";
    int num = 3294967295;
    unsigned int u_num = 3294967295;
    void *ptr = (void *)"12345";
	unsigned int hex = 10000;

    ft_printf("This is a character: %c\n", c);
    printf("This is a character: %c\n", c);

    ft_printf("This is a string: %s\n", str);
    printf("This is a string: %s\n", str);

    ft_printf("This is a d integer: %d\n", num);
    printf("This is a d integer: %d\n", num);

	ft_printf("This is an i integer: %i\n", num);
    printf("This is an i integer: %i\n", num);

    ft_printf("This is an unsigned integer: %u\n", u_num);
    printf("This is an unsigned integer: %u\n", u_num);

    ft_printf("This is a pointer: %p\n", ptr);
    printf("This is a pointer: %p\n", ptr);

    ft_printf("Hexadecimal number (lowercase): %x\n", num);
    printf("Hexadecimal number (lowercase): %x\n", num);

    ft_printf("Hexadecimal number (uppercase): %X\n", num);
    printf("Hexadecimal number (uppercase): %X\n", num);

    ft_printf("This is a %% character: %%\n");
    printf("This is a %% character: %%\n");

    ft_printf("This %% is not special.\n");
    printf("This %% is not special.\n");
 return (0);
}
