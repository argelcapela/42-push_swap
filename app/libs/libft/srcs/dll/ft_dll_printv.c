/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll_printv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:31 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 14:08:10 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dll_printv(t_dll *stack, char *title)
{
	t_dll *head;

	if (stack == NULL)
		ft_printf("empty\n");
	else
	{
	head = stack;
	ft_printf("%s:\n", title);
		while (head->next != NULL)
		{
			ft_printf("[%d] - VALUE: %d", head->index, head->value);
			if (head->previous)
				ft_printf("\t\t- PREV: %d",  head->previous->value);
			else
				ft_printf("\t\t- PREV: NULO");
			if (head->next)
				ft_printf("\t\t NEXT: %d\n", head->next->value);
			else
				ft_printf("\t\t NEXT: NULO!");
			head = head->next;
		}
			ft_printf("[%d] - VALUE: %d", head->index, head->value);
			if (head->previous)
				ft_printf("\t\t- PREV: %d",  head->previous->value);
			else
			{

				ft_printf("\t\t- PREV: NULO");
			}
			if (head->next)
				ft_printf("\t\t NEXT: %d\n", head->next->value);
			else
				ft_printf("\t\t NEXT: NULO!");
	}
}
