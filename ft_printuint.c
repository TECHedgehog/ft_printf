/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:37:39 by bazuara           #+#    #+#             */
/*   Updated: 2020/04/05 22:09:41 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_printuint(const char *str, va_list args, int **count,
		t_flags **flags)
{
	long int				i;
	unsigned long long	int abs;
	char					*num;
	char					*filler;
	char					*temp;

	i = va_arg(args, long int);
	if (i < 0)
		abs = -i;
	else
		abs = i;
	if (i == 0 && (*flags)->precission == 0 && (*flags)->has_precission == 1)
		num = ft_strjoin("", "");
	else
		num = ft_uitoa(abs);
		//aplicar ceros de precission
	if ((*flags)->precission >= ft_strlen(num) && (*flags)->precission > 0)
	{
		filler = ft_calloc(max_int((*flags)->precission, (*flags)->width) -
				ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->precission - ft_strlen(num));
		temp = num;
		num = ft_strjoin(filler, temp);
		free(filler);
		free(temp);
	}
	//aplicar ceros de width
	if ((*flags)->width > ft_strlen(num) && (*flags)->is_zero == 1)
	{
		filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, '0', (*flags)->width - ft_strlen(num));
		temp = num;
		if ((*flags)->is_minus == 0)
			num = ft_strjoin(filler, temp);
		else
			num = ft_strjoin(temp, filler);
		free(filler);
		free(temp);
	}
	//aplicar el menos
	if (i < 0)
	{
		if (*num == '0' && (*flags)->width == ft_strlen(num))
			*num = '-';
		else if (*num != '-')
		{
			temp = num;
			num = ft_strjoin("-", temp);
			free (temp);
		}
	}
	//aplicar espacios
	if ((*flags)->width > ft_strlen(num))
	{
		filler = ft_calloc((*flags)->width - ft_strlen(num) + 1, sizeof(char));
		ft_memset(filler, ' ', (*flags)->width - ft_strlen(num));
		temp = num;
		if ((*flags)->is_minus == 0)
			num = ft_strjoin(filler, temp);
		else
			num = ft_strjoin(temp, filler);
		free(filler);
		free(temp);
	}
	ft_putstr_fd(num, 1);
	(*(*count)) += ft_strlen(num);
	str++;
	free(num);
	return (str);
}
