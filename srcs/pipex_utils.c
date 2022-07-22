/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:08:04 by dsoroko           #+#    #+#             */
/*   Updated: 2022/07/22 12:51:40 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	errors(char *error)
{
	perror(error);
	exit(1);
}

char	*search_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*path_to_join;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_to_join = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_to_join, cmd);
		free(path_to_join);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (NULL);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = search_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		errors("Wrong Command");
	}
	if (execve(path, cmd, envp) == -1)
		errors("Error");
}
