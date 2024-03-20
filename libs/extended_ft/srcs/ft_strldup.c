/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:17:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/20 14:33:02 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_ft.h"

char	*ft_strldup(const char *s1, size_t len)
{
	char	*out;

	out = galloc(len);
	if (out == NULL)
		return (NULL);
	ft_strlcpy(out, s1, len);
	return (out);
}
