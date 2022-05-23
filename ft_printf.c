/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:52:20 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 15:45:26 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		ret_val;

	ret_val = 0;
	va_start(ap,string);
	ft_loop((char *) string, ap, &ret_val);
	va_end(ap);
	return (ret_val);
}

int	main(void)
{
	void *test = NULL;
	ft_printf("%+11.10i", 900);
}
