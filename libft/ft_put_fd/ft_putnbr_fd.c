/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachan <yachan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:12:27 by yachan            #+#    #+#             */
/*   Updated: 2024/08/29 17:40:24 by yachan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;
	long	lnum;

	lnum = n;
	if (lnum == 0)
		write(fd, "0", 1);
	else
	{
		if (lnum < 0)
		{
			lnum *= -1;
			write(fd, "-", 1);
		}
		if (lnum >= 10)
			ft_putnbr_fd(lnum / 10, fd);
		num = '0' + lnum % 10;
		write(fd, &num, 1);
	}
}

/*
int	main(void)
{
	for (int i = 0; i < 3003; i++)
	{
		ft_putnbr_fd(i, 1);
		write(1, "\n", 1);
	}
}
*/