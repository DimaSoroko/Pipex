/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:52:14 by dsoroko           #+#    #+#             */
/*   Updated: 2022/07/22 12:52:00 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <assert.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h> 
# include <sys/errno.h>
# include "../libft/libft.h"

void	errors(char *error);
char	*search_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void	child(char **argv, char **envp, int *fd);
void	parent(char **argv, char **envp, int *fd);

#endif