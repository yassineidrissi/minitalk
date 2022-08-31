/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yassine1337idrissi@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 04:33:05 by yidrissi          #+#    #+#             */
/*   Updated: 2021/11/24 04:46:54 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			len_dest;

	i = 0;
	len_dest = ft_strlen(dest);
	if (len_dest >= size)
		return (ft_strlen(src) + size);
	while (size != 0 && src[i] != '\0' && (len_dest + i < size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (ft_strlen(src) + len_dest);
}
