/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>   +#+  +:+       +#+        		  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:26:05 by afindo          #+#    #+#               */
/*   Updated: 2021/10/08 20:21:52 by afindo         ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	size_t	i;
	size_t	j;

	j_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!j_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		j_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		j_str[i] = s2[j];
		i++;
		j++;
	}
	j_str[i] = '\0';
	return (j_str);
}
