/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaffroy <asaffroy@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:50:08 by asaffroy          #+#    #+#             */
/*   Updated: 2021/11/08 11:06:12 by asaffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_c_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*tab;
	size_t		i;
	size_t		start;
	size_t		end;

	start = 0;
	if (!s1)
		return (NULL);
	while (s1[start] && ft_c_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_c_in_set(s1[end - 1], set))
		end--;
	tab = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (start < end)
		tab[i++] = s1[start++];
	tab[i] = 0;
	return (tab);
}
