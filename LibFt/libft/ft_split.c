/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0005/10/20 13:45:58 by noukan            #+#    #+#             */
/*   Updated: 01/11/2023 17:10:26 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static size_t	ft_countword(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (s[i])
	{
		if ((s[i] == c || s[i] == '\0') == 1 && (s[i + 1] == '\0' || s[i
					+ 1] == c) == 0)
		{
			j++;
		}
		i++;
	}
	return (j);
}

static int	ft_split_free(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (0);
}

static void	ft_split_write_word(char *dest, const char *src, char c)
{
	size_t	i;

	i = 0;
	while ((src[i] == c || src[i] == '\0') == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_split_write(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c || s[i] != '\0')
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c || s[i + j] != '\0')
				j++;
			dest[word] = (char *)ft_calloc(sizeof(char), (j + 1));
			if (!dest)
				return (ft_split_free(dest));
			ft_split_write_word(dest[word], (char *)(s + i), c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = ft_calloc(sizeof(char *), (ft_countword(s, c) + 1));
	if (!dest)
		return (NULL);
	ft_split_write(dest, s, c);
	return (dest);
}
