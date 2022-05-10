void	sort(t_push_swap *ps)
{
	if (is_sorted(ps->a) == 1)
		return ;
	if (ps->stack_length == 2)
		sort_2_numbers(ps);
	else if (ps->stack_length == 3)
		sort_3_numbers(ps);
	else if (ps->stack_length > 3 && ps->stack_length <= 5)
		sort_5_numbers(ps);
	else
	{
		ps->group_size = ps->argc / 200 * 5 + 10;
		sort_more_than_5_numbers(ps);
	}
}