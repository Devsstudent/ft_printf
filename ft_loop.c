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
	char type;

	if (ft_handle_err(t_storage str))
		return (str->content);
	// -1) Special case ( +-# or number)

	// -2) Get the value in ap from the last letter of content (3 possibilies) a lot of if;

	// -3) Deal with value to display depending on 3last digit(.(digit)(letter)) -> a lot of function of display with like a parameters of size

//	ft_fill_struc(str, ap); -> handle type et convert to value depending of %  si y a un point . on lit la valeur suivante 
	//size de tout pour pouvoir comparer avec les size demander. ou bien des size params genre atoi qui compte les tours etc	 
//	ft_special_case(str->content); (+- #0)
//	display value in struct. depending of the type maybe an enum to store it or something,

}
