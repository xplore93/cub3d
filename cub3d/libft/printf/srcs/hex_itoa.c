/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:12:25 by estina            #+#    #+#             */
/*   Updated: 2019/12/05 12:49:24 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	transform(unsigned long n, unsigned long b_l, char *bs, char **s)
{
	unsigned long	aux;
	int				len;

	aux = n;
	len = 0;
	while (aux >= b_l)
	{
		len++;
		aux /= b_l;
	}
	(*s)[len + 1] = 0;
	while (n >= b_l)
	{
		(*s)[len] = bs[n % b_l];
		len--;
		n /= b_l;
	}
	(*s)[len] = bs[n % b_l];
}

char		*hex_itoa(unsigned long nbr, int upper)
{
	unsigned long	base_len;
	char			*base;
	int				hex_len;
	char			*str;
	unsigned long	aux;

	hex_len = 1;
	base_len = 16;
	if (upper)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	aux = nbr;
	while (aux >= base_len)
	{
		hex_len++;
		aux /= base_len;
	}
	if (!(str = malloc(hex_len + 1)))
		return (NULL);
	transform(nbr, base_len, base, &str);
	free(base);
	return (str);
}

char		*pointer_handler(t_flags *flags, va_list ap, char **str)
{
	char			*aux;

	if (!flags->flag_ll && !flags->flag_hh)
		aux = hex_itoa(va_arg(ap, unsigned int), (**str == 'x' ? 0 : 1));
	else if (flags->flag_ll == 2)
		aux = hex_itoa(va_arg(ap, unsigned long long), (**str == 'x' ? 0 : 1));
	else if (flags->flag_ll == 1)
		aux = hex_itoa(va_arg(ap, unsigned long), (**str == 'x' ? 0 : 1));
	else if (flags->flag_hh == 1)
		aux = hex_itoa((unsigned short)va_arg(ap, unsigned long),
			(**str == 'x' ? 0 : 1));
	else
		aux = hex_itoa((unsigned char)va_arg(ap, unsigned long),
			(**str == 'x' ? 0 : 1));
	return (aux);
}
