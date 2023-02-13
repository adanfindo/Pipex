/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:16:21 by afindo            #+#    #+#             */
/*   Updated: 2022/03/18 13:36:13 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	creat_pipes(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nmbs - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			parent_free(pipex);
		i++;
	}
}

void	close_pipes(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_nmbs))
	{
		close(pipex->pipe[i]);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_ppxb	pipex;

	if (argc < args_in(argv[1], &pipex))
		return (message(ERR_INPUT));
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	pipex.cmd_nmbs = argc - 3 - pipex.here_doc;
	pipex.pipe_nmbs = 2 * (pipex.cmd_nmbs - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_nmbs);
	if (!pipex.pipe)
		message_error(ERR_PIPE);
	pipex.env_path = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.env_path, ':');
	if (!pipex.cmd_paths)
		pipe_free(&pipex);
	creat_pipes(&pipex);
	pipex.idx = -1;
	while (++(pipex.idx) < pipex.cmd_nmbs)
		child(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	parent_free(&pipex);
	return (0);
}
