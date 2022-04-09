/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_identify_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:04:25 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/09 06:41:02 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int check_number_duplication (int argc, char **argv)
// {
//     char    **comparation_stack;
//     int     i;
//     int     y;
//     //char    *tmp;

//     i = -1;
//     y = 0;
//     comparation_stack = (char **) malloc (argc * sizeof(char*));
//     while (comparation_stack[++i])
//         comparation_stack = NULL;
//     comparation_stack[0] = ft_strdup(argv[1]);
//     i = 2;
//     while (i < argc - 1)
//     {
//         while (y < argc)
//         {
//             if (ft_strncmp(argv[i], comparation_stack[y], ft_strlen(argv[i])) == 0)
//               return (1);
//             y++;
//         }
//         y = 0;
//         comparation_stack[i] = ft_strdup(argv[i]);
//         i++;
//     }
//     return (0);
// }

int identify_erros(int argc, char **argv)
{   
    if (argc <= 1)
    {
        ft_putstr_fd("\033[31;1m\nInvalid \
number of arguments: ./push_swap 0 8 5 7 6 ...\033[0m\n\n", 2);
        return (1);
    }
    if (argv)
    {
    }
//     if (check_number_duplication(argc, argv) == 1)
//     {
// //          ft_putstr_fd("\033[31;1m\nThe arguments should not \
// // contain duplicated numbers!\033[0m\n\n", 2);      
// //         return (1);
//     }
    return (0);
}