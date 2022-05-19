/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by odessein          #+#    #+#             */
/*   Updated: 2022/05/19 18:26:29 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
#include <stdio.h>

void	ft_implement(char *string, va_list ap)
{
	size_t	i;
	size_t	len;
	size_t	index_buffer;
	t_str_l	**lst;

	i = 0;
	len = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			if (i != 0)
			//	printf("\nstart : %li, len : %li", index_buffer, (i - index_buffer));
			//	ft_lstaddback(lst, ft_lstnew(ft_substr(string, index_buffer, (i - index_buffer)));
			index_buffer = i++;
			while (!ft_check_end(string[i]) && string[i])
				i++;
			printf("\nstart : %li, len : %li", i, (i - index_buffer));
		}
		i++;
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

void	ft_lstaddback(t_str_l **head, t_str_l *new)
{
	while ((*head))
		*head = (*head)->next;
	(*head)->next = new;
}

void	ft_lstnew(char *str)
{
	t_str_l	*new;
	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->content = str;
}
