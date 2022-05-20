/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by odessein          #+#    #+#             */
/*   Updated: 2022/05/20 11:44:25 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <stdio.h>

void	ft_loop(char *string, va_list ap)
{
	t_storage handle;

	while (*string)
	{
		t_storage->content = string;
		if (*string == '%')
			string = ft_brows(handle, ap);
		else
			write(STDOUT_FILENO, string, 1);
		string++;
	}
}

t_Bool	ft_check_end(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'i' || c == 'p' || c == 's')
		return (true);
	else if (c == 'c' || c == 'x' || c == 'X' || c == '%')
		return (true);
	return (false);
}

char	*ft_brows(t_storage str, va_list ap)
{
	//array_map_all_type
	ft_get_type
	if (ft_handle_err(t_storage str))
		return (str->content);
	ft_special_case(str->content);

}
