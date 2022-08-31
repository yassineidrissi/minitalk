/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yassine1337idrissi@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:01:10 by yidrissi          #+#    #+#             */
/*   Updated: 2021/11/24 09:03:08 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int	len;
	int	mod;

	len = 1;
	if (nbr > 0)
		mod = nbr / 10;
	else
	{
		mod = -nbr / 10;
		len++;
	}	
	while (mod > 0)
	{
		len++;
		mod = mod / 10;
	}
	return (len);
}

static char	*ft_reverse(char *src)
{
	char	temp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((const char *)src);
	while (i < len / 2)
	{
		temp = src[i];
		src[i] = src[len - 1 - i];
		src[len - 1 - i] = temp;
		i++;
	}
	return (src);
}

static char	*ft_handle(int z)
{
	if (z == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*result;
	int		temp;
	int		mod;
	int		i;

	i = 0;
	temp = n;
	if (n == 0 || n == -2147483648)
		return (ft_handle(n));
	if (temp < 0)
		temp = -temp;
	result = (char *)malloc(ft_nbrlen(n) + 1);
	if (!result)
		return (0);
	while (temp > 0)
	{
		mod = temp % 10;
		result[i] = mod + '0';
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_reverse(result));
}
