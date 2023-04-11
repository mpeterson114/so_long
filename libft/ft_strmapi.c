/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:18:36 by mpeterso          #+#    #+#             */
/*   Updated: 2022/10/18 13:06:28 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[len] = '\0';
	return (new);
}

/*char  upperprac(unsigned int i, char c)
{
    static int indexArray[6] = {0};
    indexArray[i] = 1;
    if (c >= 'a' && c <= 'z')
	{
		return(c - 32);
	}
	return(c);
}
int main(void)
{
    char    s[] = "abcdef";
    printf("%s", ft_strmapi(s, &upperprac));
    return (0);
}*/