/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by odessein          #+#    #+#             */
/*   Updated: 2022/05/20 19:22:58 by odessein         ###   ########.fr       */
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
			ft_putchar(*string);
		string++;
	}
}

t_Bool	ft_check_end(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'p' || c == 's')
		return (true);
	else if (c == 'c' || c == 'x' || c == 'X' || c == '%')
		return (true);
	return (false);
}

if (c == 'i')
{
	int value = va_arg(ap, int);
}

char	*ft_brows(t_storage str, va_list ap)
{
	char type;
	int	i;

	i = 1;
/*	if (ft_handle_err(t_storage str))
		return (str->content);*/
	if (str->content[i] == '%')
	{
		write(STDOUT_FILENO, "%", 1);
		return (str->content + i);
	}
	while (!ft_check_end(str->content[i]))
	{
		if (str->content[i] == 'i' || str->content[i] == 'd')
			ft_manage_int(str, va_arg(ap, int));
		if (str->content[i] == 'x' || str->content[i] == 'X')
			ft_manage_hexa(str, va_arg(ap, unsigned int));
		if (str->content[i] == 'u')
			ft_manage_unsigned(str, va_arg(ap, unsigned int));
		if (str->content[i] == 's')
			ft_manage_string(str, va_arg(ap, (char *)));
		if (str->content[i] == 'c')
			ft_manage_char(str, va_arg(ap, char));
		if (str->content[i] == 'p')
			ft_manage_addr(str, va_arg(ap, (void *)));
		i++;
	}
	return (str->content + i);
}

	// -1) Special case ( +-# or number)

	// -2) Get the value in ap from the last letter of content (3 possibilies) a lot of if;

		// -3) Deal with value to display depending on 3last digit(.(digit)(letter)) -> a lot of function of display with like a parameters of size

//	ft_fill_struc(str, ap); -> handle type et convert to value depending of %  si y a un point . on lit la valeur suivante 
	//size de tout pour pouvoir comparer avec les size demander. ou bien des size params genre atoi qui compte les tours etc	 
//	ft_special_case(str->content); (+- #0)
//	display value in struct. depending of the type maybe an enum to store it or something,

