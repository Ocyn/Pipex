/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:51:43 by jcuzin            #+#    #+#             */
/*   Updated: 2023/11/27 09:07:25 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_excve(t_data *data)
{
	if (close(data->pipe.fd[0]) == -1)
		ft_error_hub(9, NULL, data);
	dup2(data->file_in_fd, STDIN_FILENO);
	dup2(data->pipe.fd[1], STDOUT_FILENO);
	if (!data->shell_path || access(data->shell_path, F_OK) == -1)
		execve(data->exe_arg[0], data->exe_arg, data->v_env);
	else
		execve(data->shell_path, data->exe_arg, data->v_env);
	perror("zsh");
	ft_free_stab(data->exe_arg);
	if (close(data->file_in_fd) == -1)
		ft_error_hub(9, NULL, data);
	if (close(data->pipe.fd[1]) == -1)
		ft_error_hub(9, NULL, data);
	if (data->if_path == 0)
		ft_secure_free(&data->shell_path);
	ft_secure_free(&data->short_cmd_1);
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
	exit (0);
}

void	ft_command_1(t_data *data)
{
	data->short_cmd_1 = ft_shorter_cmd(data->input[1]);
	if (access(data->short_cmd_1, F_OK) == -1)
		ft_shell_path(data->short_cmd_1, data);
	else
		data->if_path = 1;
	data->exe_arg = ft_split(data->input[1], '\t');
	data->temp = ft_strjoin_all(data->exe_arg);
	ft_free_stab(data->exe_arg);
	data->exe_arg = ft_split(data->temp, ' ');
	ft_secure_free(&data->temp);
	data->file_in_fd = open(data->input[0], O_RDONLY);
	if (data->file_in_fd > 0 && (data->if_path == 1 || data->shell_path))
	{
		data->fork_id[0] = fork();
		if (data->fork_id[0] == -1)
			ft_error_hub(9, NULL, data);
		if (data->fork_id[0] == 0)
			ft_excve(data);
		if (close(data->file_in_fd) == -1)
			ft_error_hub(9, NULL, data);
	}
	ft_ending_cmd(1, data);
}
