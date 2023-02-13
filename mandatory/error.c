/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>   +#+  +:+       +#+        		  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:43:45 by afindo          #+#    #+#               */
/*   Updated: 2022/03/14 13:28:06 by afindo         ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	message(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	message_error(char *err)
{
	perror(err);
	exit (1);
}
