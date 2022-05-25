/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:42:48 by odessein          #+#    #+#             */
/*   Updated: 2022/05/25 15:57:28 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define BASE_L "0123456789abcdef"
# define BASE_U "0123456789ABCDEF"

typedef enum e_Bool{
	FALSE = 0,
	TRUE = 1
}	t_Bool;

typedef struct s_useful{
	t_Bool	need_add;
	t_Bool	need_neg;
}		t_useful;

typedef struct s_storage {
	void					*content;
	t_Bool					space_after;
}							t_storage;

int	ft_printf(const char *string, ...);
void	ft_loop(char *string, va_list ap, int *ret_val);
char	*ft_brows(char *str, va_list ap, int *ret_val);
t_Bool	ft_check_end(char c);
int		ft_need_sign(char *str, int size, t_useful *need_add, int *ret_val);
t_Bool	ft_check_minus(char *str);
int		ft_check_precision(char *str, int expected_space, int size);
t_Bool	ft_is_ok(char c);
t_Bool	ft_handle_err(char *str, int *ret_val);
t_Bool	ft_check_neg_sign(char *str);
t_Bool	ft_check_novalue(char *str, unsigned int value);
t_Bool	ft_check_prec_zero(char *str);

int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

char	*ft_brows_1(char *str, int *ret_val);
void	ft_apply_rules_before(char *str, int size, t_useful *sign, int *ret_val);
void	ft_apply_minus_sign(char *str, int size, int *ret_val);
void	ft_precision(char *str, int size, t_useful *add_sign, int *ret_val);
int		ft_disp_zero(char *str, int size, int index, int *ret_val);
int		ft_disp_space(char *str, int size, int index, int *ret_val);

int		ft_calc_number_size(unsigned long value, char *str);
int		ft_calc_hexa_size(char *str, unsigned int value);
size_t	ft_strlen_special(char *s, char *pattern);

void	ft_manage_int(char *str, int value, int *ret_val, t_Bool *not_end);
void	ft_manage_hexa(char *str, unsigned int val, int *ret_val, t_Bool *not_end);
void	ft_manage_string(char *str, char *value, int *ret_val, t_Bool *not_end);
void	ft_manage_addr(char *str, void *addr, int *ret_val, t_Bool *not_end);
void	ft_manage_char(char *str, char c, int *ret_val, t_Bool *not_end);
void	ft_manage_unsigned(char *str, unsigned int value, int *ret_val, t_Bool *not_end);

t_Bool	ft_check_addsign(char *str);
t_Bool	ft_check_dieze(char *str, int index);
t_Bool	ft_is_digit(char c);
t_Bool	ft_check_space(char *str, int index);

void	ft_putnstr(char *str, int size, int *ret_val);
void	ft_putnbr(long nb, int *ret_val);
void	ft_putnbr_hexa(unsigned int nb, int *ret_val);
void	ft_putnbr_hexa_x(unsigned int nb, int *ret_val);
void	ft_putnbr_unsigned(unsigned int nb, int *ret_val);
void	ft_putchar(char c, int *ret_val);
void	ft_putnbr_addr(unsigned long nb, int *ret_val);

long		ft_power(long number, int power);
void	ft_implement(char *string, va_list ap);

#endif
