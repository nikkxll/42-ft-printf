/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:04:02 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/06 11:21:21 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void	ft_uns_char_cpy(char *dest, char src, int *position)
{
	dest[(*position)++] = src;
}

static int	ft_uns_num_len(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static void	ft_uns_str_extractor(char *str, unsigned int nb, int *position)
{
	if (nb < 10)
	{
		ft_uns_char_cpy(str, nb + '0', position);
	}
	else
	{
		ft_uns_str_extractor(str, nb / 10, position);
		ft_uns_char_cpy(str, (nb % 10) + '0', position);
	}
}

char	*ft_unsigned_to_str(unsigned int n)
{
	char	*str;
	int		len;
	int		position;

	len = ft_uns_num_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	position = 0;
	ft_uns_str_extractor(str, n, &position);
	str[position] = '\0';
	return (str);
}

