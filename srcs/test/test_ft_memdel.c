/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memdel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:07:45 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/26 06:08:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_string.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	size_t const	size;
};

static t_test const		g_test[] = {
{1, 1},
{2, 2},
{3, 42},
{4, 12345},
{5, 101010},
{6, 97643182},
{7, 197354682},
{0}
};

int	test_ft_memdel(int *const ret)
{
	void	*addr;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		addr = malloc(g_test[i].size);
		ft_memdel(&addr);
		result(g_test[i].num,
			!addr);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
