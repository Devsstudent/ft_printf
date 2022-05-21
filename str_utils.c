/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:58:50 by odessein          #+#    #+#             */
/*   Updated: 2022/05/21 14:39:28 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
//IDEA : Maybe just make 1 function take the char to find in params !
t_Bool	ft_check_addsign(char *str)
{
	while (*(str))
	{
		if (*str == '+')
			return (true);
		str++;
	}
	return (false);
}

t_Bool	ft_check_dieze(char *str, int index)
{
	while (str[index])
	{
		if (str[index] == '#')
			return (true);
		index++;
	}
	return (false)
}

t_Bool	ft_is_digit(char c)
{
	if (c < 58 && c > 47)
		return (true);
	return (false);
}

t_Bool	ft_check_space(char *str, int index)
{
	while (str[index])
	{
		if (str[index] == '#')
			return (true);
		index++;
	}
	return (false)
}

size_t	ft_strlen_special(char *s, char *pattern))
{
	size_t	size;
	int	i;
	char	*to_free
	int	len;
	int	buff_idx;

	size = 0;
	i = 0;
	while (pattern[i] != '\0')
	{
		if (pattern[i] == '.' && pattern[i + 1] == 's')
			return (0);
		if (pattern[i] == '.' && ft_is_digit(pattern[i + 1]))
		{
			buff_idx = i++;
			while (ft_is_digit(pattern[i]))
			{
				len++;
				i++;
			}
			to_free = ft_substr(pattern, buff_idx, len);
			size = ft_atoi(to_free);
			free(to_free);
			if (size < 0)
				size = 0;
			return (size);
		}
		i++;
	}
	while (s[size] != '\0')
		size++;
	return (size);
}
