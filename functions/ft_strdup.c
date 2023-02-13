/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 22:06:30 by afindo            #+#    #+#             */
/*   Updated: 2022/03/18 10:16:46 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strdup(const char *src)
{
	char	*cp;
	size_t	i;

	i = 0;
	cp = (char *)malloc(ft_strlen(src) + 1);
	if (!cp)
		return (NULL);
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
