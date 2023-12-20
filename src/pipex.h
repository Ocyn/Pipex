/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:51:43 by jcuzin            #+#    #+#             */
/*   Updated: 2023/11/27 07:10:59 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "lib/ft_ext.h"
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	char				*pipe;
	int					id;
	int					fd[2];
}	t_pipe;

typedef struct s_data
{
	t_pipe				pipe;
	char				**input;
	int					file_in_fd;
	int					file_out_fd;
	char				**exe_arg;
	char				*shell_path;
	char				*short_cmd_1;
	char				*short_cmd_2;
	char				**v_env;
	char				*temp;
	char				*temp2;
	int					arg_nb;
	int					fork_id[2];
	int					i;
	int					err_code;
	int					fd;
	int					if_path;
}	t_data;

void			ft_parsing(t_data *data);
void			ft_command_1(t_data *data);
void			ft_command_2(t_data *data);
void			ft_ending_cmd(int order, t_data *data);
void			ft_error_hub(int code, char *arg, t_data *data);
void			ft_closing(t_data *data);
void			ft_secure_free(char **target);
void			ft_free_stab(char **tab);
char			*ft_shorter_cmd(char *long_cmd);
void			ft_shell_path(char *command, t_data *data);
void			ft_exception_error(int code, char *arg);
char			*ft_strjoin_all(char **tab);
char			*ft_set_command(char *file, char *cmd);
char			**ft_assemble_args(char *file, char *cmd, t_data *data);
char			**ft_split_pipex(char *s, char *in);

void			ft_debug(char *test);

#endif