//header
#ifndef PRINTF_H 
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define BASE_L "0123456780abcdef"
# define BASE_U "0123456780ABCDEF"

typedef enum {
	false = 0,
	true = 1
}	t_Bool;

typedef struct s_storage {
	void					*content;
	t_Bool					space_after;
}							t_storage;

void	ft_loop(char *string, va_list ap, int *ret_val);
char	*ft_brows(char *str, va_list ap, int *ret_val);
t_Bool	ft_check_end(char c);
int	ft_need_sign(char *str, int size, t_Bool *need_add, int *ret_val);
t_Bool	ft_check_minus(char *str);
int	ft_check_precision(char *str, int expected_space, int size);
t_Bool	ft_is_ok(char c);
t_Bool	ft_handle_err(char *str, int *ret_val);

int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

void	ft_apply_rules_before(char *str, int size, t_Bool *sign, int *ret_val);
void	ft_apply_minus_sign(char *str, int size, int *ret_val);
void	ft_precision(char *str, int size, t_Bool *add_sign, int *ret_val);
int	ft_disp_zero(char *str, int size, int index, int *ret_val);
int	ft_disp_space(char *str, int size, int index, int *ret_val);




int	ft_calc_number_size(char *str, int value);
int	ft_calc_hexa_size(char *str, unsigned value);
size_t	ft_strlen_special(char *s, char *pattern);



void	ft_manage_int(char *str, int value, int *ret_val);
void	ft_manage_hexa(char *str, unsigned value, char u_or_l, int *ret_val);
void	ft_manage_string(char *str, char *value, int *ret_val);
void	ft_manage_addr(char *str, void *addr, int *ret_val);
void	ft_manage_char(char *str, char c, int *ret_val);
void	ft_manage_unsigned(char *str, unsigned value, int *ret_val);


t_Bool	ft_check_addsign(char *str);
t_Bool	ft_check_dieze(char *str, int index);
t_Bool	ft_is_digit(char c);
t_Bool	ft_check_space(char *str, int index);

void	ft_putnstr(char *str, int size, int *ret_val);
void	ft_putnbr(long nb, t_Bool add_sign, int *ret_val);
void	ft_putnbr_hexa(unsigned nb, int *ret_val);
void	ft_putnbr_hexa_X(unsigned nb, int *ret_val);
void	ft_putnbr_unsigned(unsigned nb, int *ret_val);
void	ft_putchar(char c, int *ret_val);
void	ft_putnbr_addr(unsigned long nb, int *ret_val);

int	ft_power(long number, int power);
void	ft_implement(char *string, va_list ap);
#endif
