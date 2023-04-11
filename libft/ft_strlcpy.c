/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:01:07 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/25 19:59:46 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (*src != '\0' && i < (dstsize - 1))
		{
			*dst++ = *src++;
			i++;
		}
	}
	if (i < dstsize)
		*dst = '\0';
	while (*src++)
		i++;
	return (i);
}

/*int main()
{
	const char src[] = "";
	char dst[] = "World";
	size_t dstsize = 5;
	printf("%zu", ft_strlcpy(dst, src, dstsize));
	return 0;
}*/