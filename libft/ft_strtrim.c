/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yassine1337idrissi@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:22:57 by yidrissi          #+#    #+#             */
/*   Updated: 2021/12/01 06:16:27 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkisthere(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isstar(char *str, char *s)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_checkisthere(s, str[i]))
			return (i);
		i++;
	}
	return (0);
}

int	ft_isend(char *str, char *s)
{
	int		len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (!ft_checkisthere(s, str[len - 1]))
			return (len);
		len--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const	*set)
{
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = ft_isstar((char *)s1, (char *)set);
	end = ft_isend((char *)s1, (char *)set);
	return (ft_substr(s1, start, end - start));
}
