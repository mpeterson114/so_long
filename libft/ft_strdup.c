/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:39:19 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/18 13:04:27 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1) + 1;
	dst = malloc(len);
	if (dst == 0)
		return (NULL);
	ft_memcpy(dst, s1, len);
	return (dst);
}

/*int main()
{
	const char s1[] = "abcdef";
	printf("%s", ft_strdup(s1));
	return 0;}*/
