/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 05:56:16 by jcuzin            #+#    #+#             */
/*   Updated: 2023/11/27 07:07:13 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_shell_path_core(char **var, char *command, char *f_cmd, t_data *data)
{
	data->temp2 = ft_strjoin(var[data->i], "/");
	if (!data->temp2)
		ft_error_hub(9, NULL, data);
	f_cmd = ft_strjoin(data->temp2, command);
	if (!f_cmd)
		ft_error_hub(9, NULL, data);
	ft_secure_free(&data->temp2);
	data->i++;
	if (access(f_cmd, F_OK) == -1)
		ft_secure_free(&f_cmd);
	else
	{
		data->shell_path = ft_strdup(f_cmd);
		if (!data->shell_path)
			ft_error_hub(9, NULL, data);
		ft_secure_free(&f_cmd);
	}
}

void	ft_shell_path(char *command, t_data *data)
{
	char	**var;
	char	*f_cmd;

	var = NULL;
	f_cmd = NULL;
	data->shell_path = NULL;
	while (data->v_env[data->i] && \
	ft_strncmp(data->v_env[data->i], "PATH=", 5) != 0)
		data->i++;
	if (data->v_env[data->i] \
	&& ft_strncmp(data->v_env[data->i], "PATH=", 5) == 0)
	{
		data->temp2 = ft_strtrim(data->v_env[data->i], "PATH=");
		var = ft_split(data->temp2, ':');
		ft_secure_free(&data->temp2);
		data->i = 0;
		while (var[data->i] && !data->shell_path)
			ft_shell_path_core(var, command, f_cmd, data);
		ft_free_stab(var);
	}
	if (!data->shell_path && access(command, F_OK) == -1 \
	&& ft_strchr(command, '/') != NULL)
		ft_error_hub(-1, command, data);
	else if (!data->shell_path && access(command, F_OK) == -1)
		ft_error_hub(3, command, data);
}
