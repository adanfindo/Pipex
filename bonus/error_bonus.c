/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:15:23 by afindo            #+#    #+#             */
/*   Updated: 2022/03/18 13:36:13 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	message(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	message_pipe(char *arg)
{
	write(2, ERR_CMD, ft_strlen(ERR_CMD));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
}

void	message_error(char *err)
{
	perror(err);
	exit (1);
}
