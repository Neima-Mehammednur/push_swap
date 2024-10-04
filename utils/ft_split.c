/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neali <neali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:53:13 by neali             #+#    #+#             */
/*   Updated: 2024/10/04 15:55:13 by neali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	string_marker;

	count = 0;
	string_marker = 0;
	while (*s)
	{
		if (*s != c && string_marker == 0)
		{
			string_marker = 1;
			count++;
		}
		else if (*s == c)
			string_marker = 0;
		s++;
	}
	return (count);
}

static int	create_word(char **array, int position, size_t buffer)
{
	int	i;

	i = 0;
	array[position] = malloc(buffer);
	if (!array[position])
	{
		free_array(array);
		return (1);
	}
	return (0);
}

static int	create_array(char **array, char const *s, char c)
{
	size_t	word_len;
	int		i;

	i = 0;
	while (*s)
	{
		word_len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			word_len++;
			s++;
		}
		if (word_len)
		{
			if (create_word(array, i, word_len + 1))
				return (1);
			ft_strlcpy(array[i], s - word_len, word_len + 1);
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_counter;

	if (!s)
		return (NULL);
	word_counter = count_words(s, c) + 1;
	array = (char **)malloc((word_counter) * sizeof(char *));
	if (!array)
		return (NULL);
	array[word_counter - 1] = NULL;
	if (create_array(array, s, c) == 1)
		return (NULL);
	return (array);
}
