/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:15:01 by yachan            #+#    #+#             */
/*   Updated: 2024/10/21 15:16:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
*locates the (first occurence) of char in a str
*return value: a substr starting from the (first occurence) of char 
* returns NULL if char is not found
*/
char	*ft_strchr(const char *s, int c)
{
	char	ref;
	char	*temp;

	ref = (char)c;
	temp = (char *)s;
	while (*temp)
	{
		if (*temp == ref)
			return (temp);
		temp++;
	}
	if (c == '\0')
		return (temp);
	return (NULL);
}
