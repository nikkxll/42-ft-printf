/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:49:12 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/07 20:07:50 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putperc_fd(int fd)
{
	return (write(fd, "%", 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		if (ft_putstr_fd("(null)", fd) < 0)
			return (-1);
		return (6);
	}
	while (*s)
	{
		if (ft_putchar_fd(*s++, fd) < 0)
			return (-1);
		len++;
	}
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*ptr;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	ptr = dest;
	while (*s1 != '\0')
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	*dest = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}