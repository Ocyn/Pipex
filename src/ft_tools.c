/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 06:38:08 by jcuzin            #+#    #+#             */
/*   Updated: 2023/11/27 06:36:15 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_stab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_secure_free(&tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	ft_secure_free(char **target)
{
	if (*target != NULL)
	{
		free(*target);
		*target = NULL;
	}
}

void	ft_ending_cmd(int order, t_data *data)
{
	if (order == 1)
		ft_secure_free(&data->short_cmd_1);
	else
		ft_secure_free(&data->short_cmd_2);
	ft_free_stab(data->exe_arg);
	if (data->if_path == 0)
		ft_secure_free(&data->shell_path);
	data->if_path = 0;
	data->shell_path = NULL;
	data->exe_arg = NULL;
}

char	*ft_strjoin_all(char **tab)
{
	int		index[4];
	char	*res;

	index[2] = 0;
	index[3] = 0;
	index[1] = 0;
	index[0] = 0;
	while (tab[index[2]])
		index[1] += ft_strlen(tab[index[2]++]);
	index[2] = 0;
	res = ft_calloc(index[1] + 2, sizeof(char));
	if (!res)
		return (NULL);
	res[index[1]] = 0;
	while (tab && tab[index[2]])
	{
		index[0] = 0;
		while (tab && tab[index[2]][index[0]] && index[3] <= index[1])
			res[index[3]++] = tab[index[2]][index[0]++];
		index[2]++;
	}
	return (res);
}
