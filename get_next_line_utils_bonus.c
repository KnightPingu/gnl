/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:48:38 by dpeyrat           #+#    #+#             */
/*   Updated: 2020/11/30 12:48:40 by dpeyrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
		i++;
	if (!(dup = malloc(i + 1)))
		return (0);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = -1;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (s1[i])
		i++;
	while (s2[++j])
		i++;
	if (!(join = malloc(i + 1)))
		return (0);
	i = 0;
	j = -1;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[++j])
		join[i + j] = s2[j];
	join[i + j] = 0;
	return (join);
}
