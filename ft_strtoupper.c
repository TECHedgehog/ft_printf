/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:32:12 by bazuara           #+#    #+#             */
/*   Updated: 2020/03/10 12:53:57 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtoupper(char *str)
{
	int c;

	c = 0;
	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		c++;
		str++;
	}
	return (str - c);
}
