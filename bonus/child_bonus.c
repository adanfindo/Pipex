/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:15:00 by afindo            #+#    #+#             */
/*   Updated: 2022/03/18 13:36:13 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

static void	ft_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	child(t_ppxb p, char **argv, char **envp)
{
	p.pid = fork();
	if (!p.pid)
	{
		if (p.idx == 0)
			ft_dup2(p.infile, p.pipe[1]);
		else if (p.idx == p.cmd_nmbs - 1)
			ft_dup2(p.pipe[2 * p.idx - 2], p.outfile);
		else
			ft_dup2(p.pipe[2 * p.idx - 2], p.pipe[2 * p.idx + 1]);
		close_pipes(&p);
		p.cmd_args = ft_split(argv[2 + p.here_doc + p.idx], ' ');
		p.cmd = get_command(p.cmd_paths, p.cmd_args[0]);
		if (!p.cmd)
		{
			message_pipe(p.cmd_args[0]);
			child_free(&p);
			exit(1);
		}
		execve(p.cmd, p.cmd_args, envp);
	}
}
