/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>   +#+  +:+       +#+       		  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:58:40 by afindo          #+#    #+#               */
/*   Updated: 2022/03/14 20:13:30 by afindo         ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_command(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		message(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_command(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		message(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
