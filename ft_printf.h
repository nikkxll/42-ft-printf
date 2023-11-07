/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:22:18 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/07 17:12:42 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //DELETE

int		ft_putchar_fd(char c, int fd);
int		ft_putperc_fd(int fd);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_unsigned_to_str(unsigned int n);
int		ft_to_hex(unsigned int n, char format);
int		ft_itoa_write(int n);
int		ft_ptr_to_hex(void *ptr);
int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *s, int c);

#endif