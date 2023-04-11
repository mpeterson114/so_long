/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:49:00 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/25 19:41:45 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (((unsigned char)c) == '\0')
		return ((char *)s + i);
	return (0);
}

/*int main()
{
	const char s[] = "cheese";
	int c = '\0';
	printf("%s", ft_strchr(s, c));
	return 0;}
	*/
