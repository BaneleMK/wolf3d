/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malstrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:13:24 by bmkhize           #+#    #+#             */
/*   Updated: 2018/08/21 15:21:36 by bmkhize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_delmstrjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	c;

	if (!s1 || !s2)
		return (NULL);
	c = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2;
	if (!(str = (char *)malloc(sizeof(char) * c)))
		return (NULL);
	if (s1 && s2)
	{
		str[0] = '\0';
		ft_strlcat(str, s1, c);
		ft_strlcat(str, "|", c);
		ft_strlcat(str, s2, c);
	}
	free((void *)s1);
	return (str);
}
