/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <afindo@student.42.fr>   +#+  +:+       +#+       		  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:09:50 by afindo          #+#    #+#               */
/*   Updated: 2022/03/14 21:56:59 by afindo         ###   ########.fr         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "here_doc"

typedef struct s_ppxb
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		idx;
}t_ppxb;

void	close_pipes(t_ppxb *pipex);

void	child(t_ppxb pipex, char **argv, char **envp);

void	parent_free(t_ppxb *pipex);
void	child_free(t_ppxb *pipex);
void	pipe_free(t_ppxb *pipex);

char	*find_path(char **envp);
void	get_infile(char **argv, t_ppxb *pipex);
void	get_outfile(char *argv, t_ppxb *pipex);

int		args_in(char *arg, t_ppxb *pipex);
void	here_doc(char *argv, t_ppxb *pipex);

void	message_error(char *err);
void	message_pipe(char *arg);
int		message(char *err);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
