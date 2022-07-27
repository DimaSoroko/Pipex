/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:08:15 by dsoroko           #+#    #+#             */
/*   Updated: 2022/07/26 16:09:02 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	process_id;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			errors("Pipe failed");
		process_id = fork();
		if (process_id == -1)
			errors("Fork failed");
		if (process_id == 0)
			child(argv, envp, fd);
		waitpid(process_id, NULL, 0);
		parent(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: ./pipex must containt 4 arguments\n", 1);
		ft_putstr_fd("Ex: ./pipex infile \"command_1\" \"command_2\" outfile\n", 1);
	}
	return (0);
}
