/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/13 17:54:28 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<checker.h>

int	ft_dll_biggest(t_dll *stack)
{
	int	biggest;

	biggest = 0;
	while (stack->next != NULL)
	{
		if (stack->value > biggest)
			biggest = stack->value;
		stack = stack->next;
	}
	return (biggest);
}

static void	move_to_b_divide_two_groups (t_push_swap *ps)
{
	int	max;

	max = ps->a_size - 1;
	while (ps->a_size > 2)
	{
		if (ps->a->index == 0 || ps->a->index == max)
			ra(ps);
		else
			pb(ps);
		if ((ps->b_size >= 2) && ps->b->value > (max / 2))
			rb(ps);
		if (ft_dll_is_sorted(ps->a))
			break;
	}
}

#include <stdio.h>
int get_prev_by_index(t_dll *a, t_dll *head_a)
{
	if (head_a->index == a->index)
		return(ft_dll_last(a)->index);
	else
	{
		return (head_a->previous->index);
	}
}

static void	move_to_a (t_push_swap *ps)
{
	//int z = 1;
	// 1 -> executa enquanto tiver nodes na stack b
		t_dll	*b_node;
	while (ps->b_size)
	{
		//ft_printf("\n\nMOVIMENTO %d ******************************************************\n", z++);
		// 2-> atribui o tamanho de a b para o noa e nob



		ps->n_op_a = ps->a_size;
		ps->n_op_b = ps->b_size;
///////////////////////// 3-> calcular o que será mais rápido pra passar pra

		b_node = ps->b;
		while (b_node != NULL)
		{
///////////////////////////// CUSTO DE B
				t_dll	*head_b;

				ps->distance_until_top_b = 0;
				head_b = ps->b;
				while (head_b->value != b_node->value)
				{
					ps->distance_until_top_b++;
					head_b = head_b->next;
				}
				if (ps->distance_until_top_b > (ps->b_size / 2))
				{
					ps->tmp_n_op_b = (ps->b_size - ps->distance_until_top_b);
					ps->tmp_op_b = ft_strdup("rrb");
				}
				else
				{
					ps->tmp_n_op_b = ps->distance_until_top_b;
					ps->tmp_op_b = ft_strdup("rb");
				}
////////////////////////////////////////////////////////////////////////////////

///////////////////////////////// CUSTO DE A
				int i;
				t_dll *head_a;

				ps->distance_until_top_a = 0;
				head_a = ps->a;
				i = 0;

				while (i < ps->a_size)
				{
					if (head_a->index > b_node->index && get_prev_by_index(ps->a, head_a) < b_node->index)
						break;
					else
						i++;
					head_a = head_a->next;
				}

				ps->distance_until_top_a = i;

				if (ps->distance_until_top_a > (ps->a_size / 2))
				{
					ps->tmp_n_op_a = (ps->a_size - ps->distance_until_top_a);
					ps->tmp_op_a = ft_strdup("rra");
				}
				else
				{
					ps->tmp_op_a = ft_strdup("ra");
					ps->tmp_n_op_a = ps->distance_until_top_a;
				}
////////////////////////////////////////////////////////////////////////////

////////////////// GUARDA O MENOR CUSTO
			// if (first_calc == 1)
			// {
			// 	ps->tmp_lower_n_op_a_b = ps->n_op_a + ps->n_op_b;
			// 	first_calc = 0;
			// }
			// else
			if ((ps->tmp_n_op_a + ps->tmp_n_op_b) < (ps->n_op_a + ps->n_op_b))
			{
				ps->n_op_a = ps->tmp_n_op_a;
				ps->n_op_b = ps->tmp_n_op_b;
				ps->op_a = ft_strdup(ps->tmp_op_a);
				ps->op_b = ft_strdup(ps->tmp_op_b);
			}
/////////////////////////////////////////////////////////////////////////////

			//ft_printf("\n(%d) O BNODE %d se encaixaria corretamente se: \n", i, b_node->value);

				//ft_printf("#%d - %s top distance A:%d#\n", (ps->a_size / 2), ps->op_a, ps->n_op_a);
				//ft_printf("#%d - %s top distance B:%d#\n", (ps->b_size / 2), //ps->op_b, ps->n_op_b);
				//ft_printf("  custo total da operação: %d\n", ps->n_op_a + ps->n_op_b);

			b_node = b_node->next;
			i++;
		}
//////////////////////////////////////////////////////////////////////////////
		//ft_printf("\nmenor custo: %d\n\n", ps->tmp_lower_n_op_a_b);

		//ft_printf("\n\nANTES ******************************************************\n");
		//ft_dll_printv(ps->a, "A");
		//ft_printf("\n\n\n");
		//ft_dll_printv(ps->b, "B");
//exit(0);

		//5-> Executa as operações de acordo com os calculos realizados:
		//ft_printf("\n\n##%d##\n\n", ps->tmp_n_op_a);
		//ft_printf("\n\n##%d##\n\n", ps->n_op_a);

		//if (z == 5)
		//	exit(0);

		int n_ops_a;
		int n_ops_b;

		n_ops_a = ps->n_op_a;
		n_ops_b = ps->n_op_b;

		while (n_ops_a > 0 || n_ops_b > 0)
		{
			if (n_ops_a-- > 0)
			{
				if (ft_strncmp(ps->op_a, "ra", 2) == 0)
					ra(ps);
				else
					rra(ps);
			}
			if (n_ops_b-- > 0)
			{
				if (ft_strncmp(ps->op_b, "rb", 2) == 0)
					rb(ps);
				else
					rrb(ps);
			}
		}
		pa(ps);
		// ft_printf("\n\nDEPOIS ******************************************************\n");
		// ft_dll_printv(ps->a, "A");
		// ft_printf("\n\n\n");
		// ft_dll_printv(ps->b, "B");
		//exit(0);
	}
}

void	bring_smaller_to_top(t_push_swap *ps)
{
	t_dll	*tmp;
	int		i;

	i = 0;
	tmp = ps->a;
	while (tmp && tmp->index != (ps->a_size - 1))
	{
		i++;
		tmp = tmp->next;
	}
	while ((i + 1) > 0)
	{
		ra(ps);
		i--;
	}
}

void	five_hundred(t_push_swap *ps)
{
	move_to_b_divide_two_groups(ps);


	//ft_dll_printv(ps->a, "A");
	//if (0)
	move_to_a(ps);
		bring_smaller_to_top(ps);


	//ft_dll_printv(ps->b, "B");


}


/* 3-> Calcular 2 coisas:

			Primeiro) Quantas rotações eu preciso fazer na Stack B para um node específico chegar até o topo. E qual operação chega mais rápido RB ou RRB.

			Segundo) Quantas rotações eu preciso fazer na Stack A para que o primeiro NODE:
				- TENHA UM VALOR MAIOR QUE O PRIMEIRO NODE DE B
				- O ÚLTIMO NODE DA STACK A SEJA MENOR QUE O PRIMEIRO NODE
				DA STACK B.
				- QUANDO NÓS DERMOS PUSH DE B PARA A, o PRIMEIRO NODE DE B, SE ENCAIXARÁ CERTINHO, ANTES DE UM NÚMERO MAIOR QUE ELE, E DEPOIS DE UM NÚMERO MENOR QUE ELE.
	    */
