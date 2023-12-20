/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_closing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:23:27 by jcuzin            #+#    #+#             */
/*   Updated: 2023/11/27 09:28:55 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_closing(t_data *data)
{
	int	err;

	err = 0;
	ft_secure_free(&data->short_cmd_1);
	ft_secure_free(&data->short_cmd_2);
	ft_secure_free(&data->temp);
	ft_secure_free(&data->temp2);
	ft_secure_free(&data->shell_path);
	if (data->file_in_fd > 0)
		close(data->file_in_fd);
	if (data->file_out_fd > 0)
		close(data->file_out_fd);
	if (data->fd != 0)
		err = close(data->fd);
	if (data->pipe.fd[0])
		err = close(data->pipe.fd[0]);
	if (data->pipe.fd[1])
		err = close(data->pipe.fd[1]);
	err = close(STDIN_FILENO);
	if (err == -1)
		perror("close");
	exit (0);
}

void	ft_perror(int code, t_data *data)
{
	if (code == 4)
		perror("zsh");
	else if (code == 9)
		perror("zsh");
	ft_closing(data);
}

void	ft_error_hub(int code, char *arg, t_data *data)
{
	if (code == 1)
	{
		ft_printf("zsh: Invalid format: ./pipex file1 cmd1 cmd2 file2\n");
		ft_closing(data);
	}
	if (data->err_code < 2)
	{
		if (code == -1)
			ft_printf("zsh: no such file or directory: %s\n", arg);
		if (code == -2)
			ft_printf("zsh: permission denied: %s\n", arg);
		if (code == -3)
			ft_printf("zsh: Missing or undefined environment variables\n");
		if (code == 3)
			ft_printf("zsh: command not found: %s\n", arg);
		data->err_code++;
	}
	else
		ft_perror(code, data);
}
