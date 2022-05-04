/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_identify_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/04 22:12:33 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_if_there_is_value_duplication(int argc, char **argv)
{
	char	**comparation_stack;
	int		i;
	int		y;
	int		z;

	i = 0;
	y = -1;
	z = 0;
	comparation_stack = NULL;
	comparation_stack = (char **) ft_calloc(argc, sizeof(char *));
	if (!comparation_stack)
		return (0);
	while (argv[++i])
	{
		while (comparation_stack[++y])
		{
			if (ft_strncmp(argv[i], comparation_stack[y], sizeof(argv[i])) == 0)
				return (1);
		}
		y = -1;
		comparation_stack[z] = ft_strdup(argv[i]);
		z++;
	}
	ft_free_matrix((void **) comparation_stack);
	return (0);
}

static int	check_if_value_is_not_integer(char **argv)
{
	int		i;
	int		y;
	int		is_not_digit;
	char	*tmp;

	i = 0;
	y = -1;
	is_not_digit = 0;
	while (argv[++i])
	{
		tmp = ft_strdup(argv[i]);
		while (tmp[++y])
		{
			if (ft_isdigit(tmp[y]) == 0)
				is_not_digit++;
		}
		y = -1;
		if (is_not_digit > 0)
			return (1);
		ft_free_ptr((void *) &tmp);
	}
	return (0);
}

static int	check_if_value_overcome_limit(char **argv)
{
	int				i;
	int				is_negative;
	unsigned int	n;

	i = 0;
	while (argv[++i])
	{
		is_negative = 0;
		if (ft_strrchr(argv[i], '-'))
			is_negative = 1;
		if (is_negative == 0)
			n = (unsigned int) ft_atoi(argv[i]);
		else
			n = (unsigned int) ft_atoi(argv[i] + 1);
		if ((is_negative == 0 && n > INT_MAX) \
		|| (is_negative == 1 && n > INT_MIN))
			return (1);
	}
	return (0);
}

int	identify_errors(int argc, char **argv)
{
	if (argc <= 1)
		return (2);
	else if (check_if_value_is_not_integer(argv) == 1)
		return (1);
	else if (check_if_there_is_value_duplication(argc, argv) == 1)
		return (1);
	else if (check_if_value_overcome_limit(argv) == 1)
		return (1);
	return (0);
}
