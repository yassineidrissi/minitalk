/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yassine1337idrissi@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:27:20 by yidrissi          #+#    #+#             */
/*   Updated: 2021/11/29 22:50:21 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t	len)
{
	char		*a;
	char		*b;
	size_t		i;
	size_t		j;
	size_t		n;

	n = len;
	a = (char *)haystack;
	b = (char *)needle;
	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)&haystack[i]);
	while (a[i] && i < n)
	{
		j = 0;
		while (b[j] == a[i + j] && a[j] && i + j < n)
		{
			if (!b[j + 1])
				return (&a[i]);
			j++;
		}
		i++;
	}
	return (0);
}
