/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarraya <mjarraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 13:33:17 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/13 15:05:32 by mjarraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char	*ft_fdf_read(char *file)
{
	int		fd;
	char	*line;
	char	*new;

	fd = open(file, O_RDONLY);
	new = "";
	while (get_next_line(fd, &line) > 0)
	{
		new = ft_strjoin(new, line);
		new = ft_strjoin(new, "\n");
		free(line);
	}
	return (new);
}
int		ft_count_numbers(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			cnt++;
			while (ft_isdigit(str[i]) && str[i])
				i++;
		}
		i++;
	}
	return (cnt);
}
int		ft_get_next_nbr(char *s)
{
	int		i;
	char	*num;

	i = 0;
	while (ft_isdigit(s[i]) && s[i])
		i++;
	num = malloc(sizeof(char) * i + 1);
	i = 0;
	while (ft_isdigit(s[i]) && s[i])
	{
		num[i] = s[i];
		i++;
	}
	num[i] = '\0';
	return (ft_atoi(num));
}

void	init_fdf(t_fdf *fdf)
{
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
}

t_fdf	*ft_fdf_parse(char *map)
{
	int			i;
	t_fdf		*fdf;
	int	pos;

	pos = 0;
	i = 0;
	fdf = (t_fdf *)malloc(sizeof(t_fdf) * ft_count_numbers(map));
	while (map[i])
	{
		if (ft_isdigit(map[i]))
		{
			fdf[pos].z = ft_get_next_nbr(&map[i]);
			pos++;
			i++;
		}
		i++;
	}
	i = 0;
	while (i < pos)
	{
		//printf("point %d, y = %d\n", i, fdf[i].z);
		i++;
	}
	return (fdf);
}

int		main(int argc, char **argv)
{
	char	*map;
	int	i;
	t_fdf	*fdf;

	map = ft_fdf_read(argv[1]);
	fdf = ft_fdf_parse(map);
	i = 0;
	while (i < 209)
	{
		printf("point %d, y = %d\n", i, fdf[i].z);
		i++;
	}
	return (0);
}
