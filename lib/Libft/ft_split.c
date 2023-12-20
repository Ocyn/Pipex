/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:47:35 by jcuzin            #+#    #+#             */
/*   Updated: 2023/11/23 18:29:00 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_of_word(char const *s, char c, int cur)
{
	int	len;

	len = 0;
	while (s[cur] != c && s[cur])
	{
		cur++;
		len++;
	}
	return (len);
}

static size_t	ft_word_nb(char const *s, char c)
{
	size_t	index;
	int		word;

	index = 0;
	word = 0;
	while (s && s[index])
	{
		if (s && s[index] != c)
			word++;
		while (s[index] && s[index] != c)
			index++;
		if (s[index])
			index++;
	}
	return (word);
}

static	void	ft_free_all(char **tab, size_t index)
{
	while (index)
	{
		free(tab[index]);
		index--;
	}
	free(tab);
}

static char	**ft_main_loop(char **tab_s, size_t word_nb, char const *s, char c)
{
	size_t	i_tab;
	size_t	i_s;
	size_t	word_len;

	i_s = 0;
	i_tab = 0;
	while (i_tab < word_nb)
	{
		if (s[i_s] != c)
		{
			word_len = ft_size_of_word(s, c, i_s);
			tab_s[i_tab] = ft_substr(s, i_s, word_len);
			if (tab_s[i_tab] == NULL)
				return (ft_free_all(tab_s, i_tab), NULL);
			i_tab++;
			i_s += word_len;
		}
		i_s++;
	}
	tab_s[word_nb] = 0;
	return (tab_s);
}

char	**ft_split(char const *s, char c)
{
	size_t		word_nb;
	char		**tab_s;

	word_nb = ft_word_nb(s, c);
	if (!s || !c)
		return (NULL);
	tab_s = ft_calloc(word_nb + 1, sizeof(tab_s));
	if (tab_s == NULL)
		return (NULL);
	return (ft_main_loop(tab_s, word_nb, s, c));
}
