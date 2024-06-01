/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:16:47 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:16:49 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(int f)
{
	printf("\033[0;31mError:\033[0m ");
	if (f == 1)
		return (printf("There must be at least one player and only one.\n"));
	if (f == 2)
		return (printf("There must be at least one coin.\n"));
	if (f == 3)
		return (printf("What you gonna do...?\n"));
	if (f == 4)
		return (printf("You don't give a damn\n"));
	if (f == 5)
		return (printf("Your fly is down... Check the walls\n"));
	if (f == 6)
		return (printf("Something went wrong with the images\n"));
	if (f == 7)
		return (printf("No such map\n"));
	return (1);
}
