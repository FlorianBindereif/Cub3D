/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:24:20 by mac               #+#    #+#             */
/*   Updated: 2021/12/05 22:42:39 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *str, char c, int *start, int *w)
{
	int		words;
	int		confirm;
	int		i;

	w[1] = -1;
	*start = 0;
	words = 0;
	confirm = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			confirm = 1;
		if (confirm == 1 && str[i] == c)
		{
			words += 1;
			confirm = 0;
		}
		i++;
	}
	if (confirm == 1 && str[i] == '\0')
		words += 1;
	return (words);
}

char	**ft_freeman(int i, char **strarray)
{
	while (i >= 0)
	{
		free(strarray[i]);
		strarray[i] = NULL;
		i--;
	}
	free(strarray);
	strarray = NULL;
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**strarray;
	int		i;
	int		words[2];
	int		start;

	if (!s || s[0] == '\0')
		return (NULL);
	words[0] = ft_countwords(s, c, &start, words);
	strarray = ft_calloc(words[0] + 1, sizeof(char *));
	if (!strarray)
		return (NULL);
	i = 0;
	while (words[0] > ++words[1])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		strarray[words[1]] = ft_substr(s, start, i - start);
		if (!strarray[words[1]])
			return (ft_freeman(words[1] - 1, strarray));
	}
	return (strarray);
}
