/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:22:18 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/06 16:37:52 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //DELETE

void	ft_putchar_fd(char c, int fd);
void	ft_putperc_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_unsigned_to_str(unsigned int n);
char	*ft_to_hex(unsigned int n, char format);
char	*ft_itoa(int n);
char	*ft_ptr_to_hex(void *ptr);

#endif