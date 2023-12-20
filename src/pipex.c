/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:51:43 by jcuzin            #+#    #+#             */
/*   Updated: 2023/11/27 13:18:59 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_debug(char *test)
{
	ft_printf("\nDEBUG=\"%s\"\n", test);
}

void	ft_init(int argc, char **argv, char **env, t_data *data)
{
	data->shell_path = NULL;
	data->v_env = env;
	if (argc > 1)
	{
		data->arg_nb = (argc - 1);
		data->input = argv + 1;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	ft_bzero_libft(&data, sizeof(data));
	ft_init(argc, argv, env, &data);
	ft_parsing(&data);
	if (pipe(data.pipe.fd) == -1)
		ft_error_hub(8, NULL, &data);
	ft_command_1(&data);
	ft_command_2(&data);
	if (close(data.pipe.fd[1]) == -1)
		ft_error_hub(6, NULL, &data);
	if (close(data.pipe.fd[0]) == -1)
		ft_error_hub(6, NULL, &data);
	waitpid(data.fork_id[1] - 1, 0, 0);
	waitpid(data.fork_id[1], 0, 0);
	ft_closing(&data);
	return (0);
}
