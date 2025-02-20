/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:52:22 by fmorenil          #+#    #+#             */
/*   Updated: 2024/07/29 16:16:36 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	words_count(char *line, char c)
{
	char	**array;
	int		i;

	array = ft_split(line, c);
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (i);
}

void	ft_free_matrix(char **num, int i)
{
	while (num[i])
		free(num[i++]);
	free(num);
}
