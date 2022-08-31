/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yassine1337idrissi@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:08:17 by yidrissi          #+#    #+#             */
/*   Updated: 2021/11/29 05:49:22 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_malloc(const char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			len++;
		}
		while (str[i] == c && str[i] != '\0')
			i++;
	}
	return (len + 1);
}

static char	*ft_add_mot(const char *str, int i, int j)
{
	int		len_mot;
	int		k;
	char	*mot;

	mot = 0;
	len_mot = (j - i + 1) + 1;
	mot = (char *)malloc (len_mot * sizeof(char));
	if (!mot)
		return (0);
	k = 0;
	while (k < len_mot - 1)
	{
		mot[k] = str[i + k];
		k++;
	}
	mot[k] = '\0';
	return (mot);
}

static void	ft_init(int *i, int *j, int *k)
{
	*i = 0;
	*j = 0;
	*k = 0;
}

char	**ft_free_result(char **result, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	ft_init(&i, &j, &k);
	result = (char **)malloc (ft_size_malloc (str, c) * sizeof(char *));
	if (!result || !str)
		return (0);
	while (str && str[i] != '\0')
	{
		j = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (i != j)
			result[k++] = ft_add_mot(str, j, i - 1);
		if (i != j && !result[k - 1])
			return (ft_free_result(result, k));
		while (str[i] == c && str[i] != '\0')
			i++;
	}
	result[k] = 0;
	return (result);
}
