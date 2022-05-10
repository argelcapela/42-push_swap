/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/04 02:04:27 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_dll_is_sorted(t_dll *stack)
{
	int	tmp;

	tmp = stack->value;
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (stack->value < tmp)
			return (0);
		tmp = stack->value;
	}
	return (1);
}