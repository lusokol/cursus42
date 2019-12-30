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
	info.largeur = -1;
	info.moins = 0;
	info.zeros = 0;
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
		info->zeros = 0;
	}
	return (add);
}

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
	return (info);
}

t_info	ft_arg_u(va_list *arg, char *type)
{
	int long long		nbr;
	//unsigned int		unbr;
	int					i;
	t_info				info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	nbr = va_arg(*arg, int);
	//printf("nbr : %lld\n", nbr);
	//unbr = (unsigned int)nbr;
	//else
	//		test = nbr;
	//printf("unbr :\t");
	if (nbr < 0)
		nbr = (4294967296) - -nbr;
	//nbr = unbr;
	//printf("\n%lld\n", nbr);
	//ft_putnbr(unbr);
	if (nbr != 0 || info.precision != 0)
		ft_aff_nbr(info, ft_itoa(nbr));
	return (info);
}
