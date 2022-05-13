/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/05/12 23:29:44 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<push_swap.h>

static void	move_to_b_divide_two_groups (t_push_swap *ps)
{
	int	max;

	max = ps->a_size - 1;
	while (ps->a_size > 2)
	{
		if (ps->a->value == 0 || ps->a->value == max)
			ra(ps);
		else
			pb(ps);
		if (ps->b_size && ps->b->value > (max / 2))
			rb(ps);
		if (ft_dll_is_sorted(ps->a))
			break;
	}
}

#include <stdio.h>
static void	move_to_a (t_push_swap *ps)
{
	// 1 -> executa enquanto tiver nodes na stack b
	while (ps->b_size >= 5)
	{
		// 2-> atribui o tamanho de a b para o noa e nob
		ps->n_op_a = ps->a_size;
		ps->n_op_b = ps->b_size;

		// 3-> calcular o que será mais rápido pra passar pra A:
		t_dll	*b_node;

		b_node = ps->b;
		ps->tmp_lower_n_op_a_b = 0;
		while (b_node->next != NULL)
		{
			// CUSTO DE B
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
					ps->op_b = ft_strdup("rrb");
					ps->n_op_b = (ps->b_size - ps->distance_until_top_b);
				}
				else
				{
					ps->op_b = ft_strdup("rb");
					ps->n_op_b = ps->distance_until_top_b;
				}
			// CUSTO DE A
				t_dll	*head_a;
				t_dll	*prev;

				ps->distance_until_top_a = 0;
				prev = ft_dll_last(ps->a);
				head_a = ps->a;
				while (head_a->next != NULL && head_a->value < b_node->value &&
					   prev->value > b_node->value)
				{
					ps->distance_until_top_a++;
					head_a = head_a->next;
					prev = head_a->previous;
				}
					ps->distance_until_top_a++;
				//ft_printf("#%d#\n", head_a->value);



				if (ps->distance_until_top_a > (ps->a_size / 2))
				{
					ps->op_a = ft_strdup("rra");
					ps->n_op_a = (ps->a_size - ps->distance_until_top_a);
				}
				else
				{
					ps->op_a = ft_strdup("ra");
					ps->n_op_a = ps->distance_until_top_a;
				}
			// QUAL O NÚMERO O B_NODE MAIS RÁPIDO PRA SER PUXADO PRA A
			int sum_n_ops = ps->n_op_a + ps->n_op_b;
			if (sum_n_ops < ps->tmp_lower_n_op_a_b)
			{
				ps->tmp_lower_n_op_a_b = sum_n_ops;
				ps->tmp_n_op_a = ps->n_op_a;
				ps->tmp_n_op_b = ps->n_op_b;
				ps->tmp_op_a = ps->op_a;
				ps->tmp_op_b = ps->op_b;
			}

			b_node = b_node->next;
		}
		ft_printf("#%d#\n", ps->tmp_n_op_a);
			//exit(0);
		//ft_printf("BNODE: %d op:%s n_op: %d\n", b_node->value, ps->op_a, ps->n_op_a);
		//5-> Executa as operações de acordo com os calculos realizados:
		//ft_printf("#%d %d#\n", ps->n_op_a, ps->n_op_b);
		while (ps->tmp_n_op_a > 0 || ps->tmp_n_op_b > 0)
		{
			if (ps->tmp_n_op_a-- > 0)
			{
				if (ft_strncmp(ps->tmp_op_a, "ra", 2) == 0)
					ra(ps);
				else
					rra(ps);
			}
			if (ps->tmp_n_op_b-- > 0)
			{
				if (ft_strncmp(ps->tmp_op_b, "rb", 2) == 0)
					rb(ps);
				else
					rrb(ps);
			}

		}
		pa(ps);
				system("clear");
				ft_dll_printv(ps->a, "A");
				ft_printf("\n\n\n");
				ft_dll_printv(ps->b, "B");
				exit(0);
	}
}

void	five_hundred(t_push_swap *ps)
{
	move_to_b_divide_two_groups(ps);

	move_to_a(ps);


	//ft_dll_printv(ps->b, "B");

	//ft_dll_printv(ps->a, "A");

}


/* 3-> Calcular 2 coisas:

			Primeiro) Quantas rotações eu preciso fazer na Stack B para um node específico chegar até o topo. E qual operação chega mais rápido RB ou RRB.

			Segundo) Quantas rotações eu preciso fazer na Stack A para que o primeiro NODE:
				- TENHA UM VALOR MAIOR QUE O PRIMEIRO NODE DE B
				- O ÚLTIMO NODE DA STACK A SEJA MENOR QUE O PRIMEIRO NODE
				DA STACK B.
				- QUANDO NÓS DERMOS PUSH DE B PARA A, o PRIMEIRO NODE DE B, SE ENCAIXARÁ CERTINHO, ANTES DE UM NÚMERO MAIOR QUE ELE, E DEPOIS DE UM NÚMERO MENOR QUE ELE.
	    */
