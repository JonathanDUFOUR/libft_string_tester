/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:00:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/26 00:44:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ft_string.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	size_t const	n;
	size_t const	size;
};

static t_test const		g_test[] = {
{1, 42, sizeof(uint8_t)},
{2, 21, sizeof(uint16_t)},
{3, 101010, sizeof(uint32_t)},
{4, 9, sizeof(uint64_t)},
{5, 0, sizeof(uint8_t)},
{6, UINT_MAX, sizeof(uint64_t)},
{7, 256, 0},
{0}
};

int	test_ft_calloc(int *const ret)
{
	void	*addr0;
	void	*addr1;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		addr0 = calloc(g_test[i].n, g_test[i].size);
		addr1 = ft_calloc(g_test[i].n, g_test[i].size);
		result(g_test[i].num,
			(!addr0 && !addr1) || (addr0 && addr1
				&& !memcmp(addr0, addr1, g_test[i].n * g_test[i].size)));
		free(addr0);
		free(addr1);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
