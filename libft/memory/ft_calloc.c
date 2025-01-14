/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:02:33 by yachan            #+#    #+#             */
/*   Updated: 2024/11/09 19:59:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
dynamically allocates memory and sets allocated bytes to 0
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*holder;
	size_t	total_size;

	if ((size && (nmemb > UINT_MAX / size)) || (nmemb && (size > UINT_MAX
				/ nmemb)))
		return (NULL);
	total_size = nmemb * size;
	holder = malloc(total_size);
	if (!holder)
		return (NULL);
	ft_memset(holder, 0, total_size);
	return (holder);
}
