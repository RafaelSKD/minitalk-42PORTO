/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaefer <rafaefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:50:13 by rafaefer          #+#    #+#             */
/*   Updated: 2024/10/30 16:46:40 by rafaefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_sleep(int len)
{
	if (len <= 10000)
		return (50);
	else if (len <= 30000)
		return (100);
	else if (len <= 60000)
		return (300);
	else if (len <= 100000)
		return (500);
	else
		return (10000);
}

void	bit_sender(char *str, int id)
{
	char	temp;
	int		bits;
	int		len;
	int		i;

	len = ft_strlen(str) + 1;
	i = 0;
	bits = 7;
	while (len--)
	{
		temp = str[i];
		while (bits >= 0)
		{
			if (temp >> bits & 1)
				kill(id, SIGUSR1);
			else
				kill(id, SIGUSR2);
			bits--;
			usleep(ft_sleep(ft_strlen(str)));
		}
		i++;
		bits = 7;
	}
	usleep(ft_strlen(str));
	return ;
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (ft_printf("Error\nInvalid number of arguments.\n"
				"Correct format: ./client <PID> <MESSAGE>\n"));
	bit_sender(av[2], ft_atoi(av[1]));
	return (0);
}
