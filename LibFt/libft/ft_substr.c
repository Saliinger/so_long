/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0005/10/20 09:16:28 by noukan            #+#    #+#             */
/*   Updated: 2023/11/01 08:59:57 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substr_2(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;
	char	*void_str;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		void_str = (char *)malloc(1);
		if (!void_str)
			return (NULL);
		void_str[0] = '\0';
		return (void_str);
	}
	d = (char *)malloc(len + 1);
	if (!d)
		return (NULL);
	while (i < len)
	{
		d[i] = s[start + i];
		++i;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	return (ft_substr_2(s, start, len));
}
