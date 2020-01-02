#include "libftprintf.h"

int		ft_natoi(char *str, int i)
{
	int nbr;

	nbr = 0;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

t_info	ft_init_info(void)
{
	t_info info;

	info.precision = -1;
	info.largeur = 0;
	info.moins = 0;
	info.zeros = 0;
	info.str = 0;
	return (info);
}

int	ft_take_arg(va_list *arg, char *type, int i)
{
	int nbr;

	nbr = 0;
	if (type[i] == '*')
		return (va_arg(*arg, int));
	while (ft_isdigit(type[i]))
	{
		nbr = (nbr * 10) + (type[i] - '0');
		i++;
	}
	return (nbr);
}

int		ft_take_flags(t_info *info, char *type)
{
	int i;

	i = 0;
	while (ft_check_flag(type[i]))
	{
		if (type[i] == '-')
			info->moins = 1;
		if (type[i] == '0')
			info->zeros = 1;
		i++;
	}
	return (i);
}

int		ft_take_largeur(t_info *info, char *type, int i,  va_list *arg)
{
	int add;

	add = 0;
	if (type[i + add] != '.' && (ft_isdigit(type[i + add]) || type[i + add] == '*'))
	{
		info->largeur = ft_take_arg(arg, type, i + add);
		if (type[i + add] == '*')
			add++;
		else while (ft_isdigit(type[i + add]))
			add++;
	}
	if (info->largeur < 0)
	{
			info->moins = 1;
			info->largeur = -info->largeur;
	}
	return (add);
}

int		ft_take_precision(t_info *info, char *type, int i,  va_list *arg)
{
	int add;

	add = 0;
	if (type[i + add] == '.')
	{
		add++;
		info->precision = ft_take_arg(arg, type, i + add);
		if (type[i + add] == '*')
			add++;
		else while (ft_isdigit(type[i + add]))
			add++;
		if (info->precision >= 0)
			info->zeros = 0;
	}
	return (add);
}

//printf("largeur : %d, precision : %d, ", info.largeur, info.precision);
//printf("zero : %d, moin : %d, ", info.zeros, info.moins);

t_info	ft_arg_i_d(va_list *arg, char *type)
{
	int		nbr;
	int		i;
	t_info	info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	nbr = va_arg(*arg, int);
	if (nbr != 0 || info.precision != 0)
		ft_aff_nbr(info, ft_itoa(nbr));
	else
			while (info.largeur > 0)
			{
				ft_putchar(' ');
				g_count++;
				info.largeur--;
			}
	return (info);
}

t_info	ft_arg_u(va_list *arg, char *type)
{
	int long long		nbr;
	int					i;
	t_info				info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	nbr = va_arg(*arg, int);
	if (nbr < 0)
		nbr = (4294967296) - -nbr;
	if (nbr != 0 || info.precision != 0)
		ft_aff_nbr(info, ft_itoa(nbr));
	else
		ft_aff_nbr(info, ft_strdup(""));
	return (info);
}

t_info	ft_arg_xX(va_list *arg, char *type, int a)
{
	int		nbr;
	int		i;
	t_info	info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	nbr = va_arg(*arg, int);
	if ((nbr != 0 || info.precision != 0) && a == 1)
		ft_aff_nbr(info, ft_convert_base(nbr, "0123456789abcdef"));
	else if ((nbr != 0 || info.precision != 0) && a == 2)
		ft_aff_nbr(info, ft_convert_base(nbr, "0123456789ABCDEF"));
	else
		ft_aff_nbr(info, ft_strdup(""));
	return (info);
}

t_info	ft_arg_c(va_list *arg, char *type)
{
	char	*str;
	int		i;
	t_info	info;

	i = 0;
	info = ft_init_info();
	if (!(str = malloc(sizeof(char) * 2)))
			return (info);
	str[1] = '\0';
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	str[0] = va_arg(*arg, unsigned int);
	info.str = 1;
	if (str[0] == '\0')
			g_count++;
	if (str != 0 || info.precision != 0)
		ft_aff_nbr(info, str);
	return (info);
}

t_info	ft_arg_s(va_list *arg, char *type)
{
	char	*str;
	int		i;
	t_info	info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	str = ft_strdup(va_arg(*arg, char*));
	info.str = 2;
	if (!str)
	{
		free(str);
		str = ft_strdup("(null)");
	}
	if (str != 0 || info.precision != 0)
		ft_aff_str(info, str);
	return (info);
}

t_info	ft_arg_p(va_list *arg, char *type)
{
	unsigned long long int	nbr;
	int						i;
	t_info					info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	nbr = va_arg(*arg, unsigned long long int);
	if (nbr != 0 || info.precision != 0)
		ft_aff_nbr(info, ft_convert_base_add(nbr, "0123456789abcdef"));
	return (info);
}

t_info	ft_arg_percent(va_list *arg, char *type)
{
	char	*str;
	int		i;
	t_info	info;

	i = 0;
	str = ft_strdup("%");
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	i += ft_take_flags(&info, type);
	ft_aff_percent(info, str);
	return (info);
}

int			ft_len_nbr(unsigned long long int nb, int lenBase)
{
	int i;

	i =  0;
	while (nb >= (unsigned long long int)lenBase)
	{
		nb = nb / lenBase;
		i++;
	}
	i++;
	return (i);
}

char		*ft_convert_base_add(unsigned long long int nbr, char *baseTo)
{
	int	len;
	char *nb;
	int i;
	int j;

	i = 1;
	j = 0;
	len = ft_len_nbr(nbr, ft_strlen(baseTo)) + 2;
	if (!(nb = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nb[len] = '\0';
	nb[0] = '0';
	nb[1] = 'x';
	while (nbr >= (unsigned long long int)ft_strlen(baseTo))
	{
		nb[len - i] = baseTo[nbr % ft_strlen(baseTo)];
		nbr = nbr / ft_strlen(baseTo);
		i++;
	}
	nb[len - i] = baseTo[nbr % ft_strlen(baseTo)];
	return (nb);
}

char		*ft_convert_base(unsigned int nbr, char *baseTo)
{
	int	len;
	char *nb;
	int i;
	int j;

	i = 1;
	j = 0;
	if (nbr < 0)
		nbr = (4294967296) - -nbr;
	len = ft_len_nbr(nbr, ft_strlen(baseTo));
	if (!(nb = malloc(sizeof(char)  * (len + 1))))
		return (NULL);
	nb[len] = '\0';
	while (nbr > (unsigned int)ft_strlen(baseTo))
	{
		nb[len - i] = baseTo[nbr % ft_strlen(baseTo)];
		nbr = nbr / ft_strlen(baseTo);
		i++;
	}
	nb[len - i] = baseTo[nbr % ft_strlen(baseTo)];
	return (nb);
}
