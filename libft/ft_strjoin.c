/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yassine1337idrissi@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:13:46 by yidrissi          #+#    #+#             */
/*   Updated: 2021/12/01 08:19:48 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const	*s2)
{
	char	*f;
	char	*se;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	se = (char *)s2;
	f = (char *)s1;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ptr)
		return (ptr);
	while (f && f[i] != '\0')
		ptr[i++] = f[j++];
	j = 0;
	while (se && se[j] != '\0')
		ptr[i++] = se[j++];
	ptr[i] = '\0';
	return (ptr);
}

/*
int main(void)
{
	char 	*s1 = "yassime";
	char 	*s2 = "dse";
	printf ("%s", ft_strjoin(s1, s2));
}
*/