/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:16:56 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:17:00 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	bad_extension(char **argv)
{
	int		i;
	bool	b_one;
	bool	b_two;
	bool	b_three;
	bool	b_four;

	i = ft_strlen(argv[1]);
	b_one = argv[1][i - 4] != '.';
	b_two = argv[1][i - 3] != 'b';
	b_three = argv[1][i - 2] != 'e';
	b_four = argv[1][i - 1] != 'r';
	if (b_one | b_two | b_three | b_four)
	{
		ft_printf("\033[0;31mError:\033[0m invalid type of arguments\n");
		return (1);
	}
	else
		return (0);
}

int	invalid_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("\033[0;31mError:\033[0m invalid number of arguments\n");
		return (1);
	}
	if (bad_extension(argv))
		return (1);
	if (invalid_images())
		return (ft_error(6));
	return (0);
}
