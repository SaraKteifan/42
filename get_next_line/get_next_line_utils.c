/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:58:48 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/18 13:25:03 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(char *s1, char *s2)
{
	free (s1);
	free (s2);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*joined;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	joined = malloc(i + j + 1);
	if (!joined)
	{
		free_all(s1, s2);
		return (NULL);
	}
	k = -1;
	while (++k < i)
		joined[k] = s1[k];
	k--;
	while (++k < i + j)
		joined[k] = s2[k - i];
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}

char	*initialize_repo(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}
