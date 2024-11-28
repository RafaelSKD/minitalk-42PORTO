/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaefer <rafaefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:50:24 by rafaefer          #+#    #+#             */
/*   Updated: 2024/10/30 16:47:53 by rafaefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft_btoc(char *bit)
{
	int		bits;
	int		i;
	char	c;

	i = 0;
	c = 0;
	bits = 7;
	while (bit[i])
	{
		if (bit[i] == '1')
			c = (c ^ 1 << bits);
		bits--;
		i++;
	}
	return (c);
}

char	*join_bit(char *bit, char n)
{
	int		i;
	char	*new;

	i = 0;
	if (!bit)
	{
		bit = (char *)malloc(1 * sizeof(char) + 1);
		bit[i] = n;
		bit[++i] = '\0';
		return (bit);
	}
	new = (char *)malloc((ft_strlen(bit) + 1) * sizeof(char) + 1);
	while (bit[i])
	{
		new[i] = bit[i];
		i++;
	}
	new[i] = n;
	new[++i] = '\0';
	free(bit);
	return (new);
}

void	handler(int signal)
{
	static char	*bit;
	static char	*str;

	if (signal == SIGUSR1)
		bit = join_bit(bit, '1');
	else
		bit = join_bit(bit, '0');
	if (ft_strlen(bit) == 8 && !ft_btoc(bit))
	{
		ft_printf("%s\n", str);
		free(str);
		free(bit);
		bit = NULL;
		str = NULL;
		return ;
	}
	if (ft_strlen(bit) == 8)
	{
		str = join_bit(str, ft_btoc(bit));
		free(bit);
		bit = NULL;
	}
	return ;
}

int	main(void)
{
	int	id;

	id = getpid();
	ft_printf("PID: %d\n", id);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
	return (0);
}
