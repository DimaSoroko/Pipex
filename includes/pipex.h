/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoroko <dsoroko@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:52:14 by dsoroko           #+#    #+#             */
/*   Updated: 2022/07/26 16:04:55 by dsoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
** perror
*/
# include <stdio.h> 
/*
** open
*/
# include <fcntl.h>
/*
** dup2, close, STDIN_FILENO, fork, access
*/
# include <unistd.h> 
/*
** free, exit
*/
# include <stdlib.h>
/*
** waitpid
*/
# include <sys/wait.h>
/*
** pid_t
*/
# include <sys/types.h>
/*
** libft.h
*/
# include "../libft/libft.h"

void	errors(char *error);
char	*search_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void	child(char **argv, char **envp, int *fd);
void	parent(char **argv, char **envp, int *fd);

#endif