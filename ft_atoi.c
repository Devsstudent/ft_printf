/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:12:19 by odessein          #+#    #+#             */
/*   Updated: 2022/05/21 14:37:24 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <stdlib.h>

void	ft_putnstr(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size && str[i] != '\0'))
	{
		ft_putchar(str[i]);
		i++;
	}
}
static void	ft_skip(const char *nptr, int *i, long long *res, int *neg_sign)
{
	*i = 0;
	*res = 0;
	*neg_sign = 1;
	while (nptr[*i] == '\v' || nptr[*i] == '\t' || nptr[*i] == '\r'
		|| nptr[*i] == '\n' || nptr[*i] == '\f' || nptr[*i] == ' ')
		*i = *i + 1;
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long long	res;
	int			neg_sign;

	ft_skip(nptr, &i, &res, &neg_sign);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg_sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] != ' ' && ft_is_digit(nptr[i]))
	{
		if ((long)(res * neg_sign) < -2147483648)
			return (0);
		else if ((long)(res * neg_sign) > 2147483647)
			return (-1);
		res *= 10;
		res += nptr[i] - 48;
		i++;
	}
	res *= neg_sign;
	return ((int) res);
}


inline static int	ft_malloc_size(char *s, int start, size_t len, char **ret)
{
	int		size;
	int		buff;
	int		i;

	size = 0;
	i = 0;
	buff = start;
	if (buff == 0 && ft_strlen(s) < len)
		size++;
	while (i < (int) len && s[buff] != '\0')
	{
		size++;
		i++;
		buff++;
	}
	if (i == size)
		size++;
	if (start == (int) len)
		size = len + 1;
	*ret = malloc(sizeof(char) * size);
	if (!(*ret))
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) <= start)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = 0;
		return (res);
	}
	i = start;
	j = 0;
	if (!ft_malloc_size((char *) s, (int) start, len, &res))
		return (NULL);
	while (j < len && s[i] != '\0')
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
