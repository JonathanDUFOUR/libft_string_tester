/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:15:06 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 18:59:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const		num;
	char const		*src;
	char *const		dst0;
	char *const		dst1;
	size_t const	size;
};

static t_test const		g_test[] = {
{1,
	(char []){},
	(char []){},
	(char []){},
	0},
{2,
	(char []){0},
	(char []){0},
	(char []){0},
	1},
{3,
	(char []){'a', 0},
	(char []){'b', 0, 'o', 'o'},
	(char []){'b', 0, 'o', 'o'},
	},
{0}
};

int	test_ft_strlcat(int *const ret)
{
	printf("%20s:", __func__ + 5);
	printf("\n");
	return (*ret = SUCCESS);
}
