/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:30:07 by jcuzin            #+#    #+#             */
/*   Updated: 2023/11/26 08:41:15 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_file(t_data *data)
{
	int	fd;

	fd = 0;
	if (access(data->input[0], F_OK) == -1)
		ft_error_hub(-1, data->input[0], data);
	else if (access(data->input[0], F_OK | R_OK) == -1)
		ft_error_hub(-2, data->input[0], data);
	if (access(data->input[3], F_OK) == -1)
	{
		fd = open(data->input[3], O_CREAT | O_RDWR, 00700);
		close(fd);
		return (0);
	}
	else if (access(data->input[3], F_OK | W_OK) != -1)
	{
		unlink(data->input[3]);
		fd = open(data->input[3], O_CREAT | O_RDWR, 00700);
		close(fd);
	}
	else if (access(data->input[3], F_OK | W_OK) == -1)
		ft_error_hub(-2, data->input[3], data);
	return (0);
}

char	*ft_shorter_cmd(char *long_cmd)
{
	char	*short_cmd;
	int		index1;
	int		index2;

	if (!long_cmd)
		return (NULL);
	index1 = 0;
	index2 = 0;
	short_cmd = NULL;
	while (long_cmd[index2] == ' ' || long_cmd[index2] == '\t')
		index2++;
	while (long_cmd[index2 + index1] && (long_cmd[index2 + index1] != ' ' \
	&& long_cmd[index2 + index1] != '\t'))
		index1++;
	short_cmd = malloc(sizeof(char) * (index1 + 1));
	if (!short_cmd)
		return (NULL);
	short_cmd[index1] = 0;
	index1 = 0;
	while (long_cmd[index2] \
	&& (long_cmd[index2] != ' ' && long_cmd[index2] != '\t'))
		short_cmd[index1++] = long_cmd[index2++];
	return (short_cmd);
}

void	ft_parsing(t_data *data)
{
	if (data->arg_nb != 4)
		ft_error_hub(1, NULL, data);
	if (ft_check_file(data) == -1)
		ft_error_hub(9, NULL, data);
}
