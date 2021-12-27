/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:13:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 11:16:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "enum/e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	*str;
};

static t_test const		g_test[] = {
{1,
	""},
{2,
	"A"},
{3,
	"42"},
{4,
	"Hello World !"},
{5,
	"]-[alpha BRAVO charlie DELTA[+]"},
{6,
	"Sakura_Minato_Kushina_Naruto_Sasuke_Lee_Gai_Tenten_Gaara_Kakashi_Itachi"},
{7,
	"\
I wanna be the very best, like no one ever was.\n\
To catch them is my real test, to train them is my cause !\n\
I will travel across the lands, searching far and wide.\n\
Each Pokemon to understand. The power that's inside !\n\
\n\
Pokemon ! Gotta catch 'em !\n\
It's you and me !\n\
I know it's my destiny !\n\
Pokemon ! Gotta catch 'em !\n\
Oh, you're my best friend !\n\
In the world we must defend !\n\
Pokemon ! Gotta catch 'em !\n\
A heart so true !\n\
Our courage will pull us through !\n\
You teach me and I teach you !\n\
Poookeeemooon !\n\
Gotta catch 'em all ! Gotta catch 'em all ! Pokemon !\n\
\n\
Every challenge along the way, with courage I will face.\n\
I will battle everyday to claim my rightfull place !\n\
Come with me, the time is right, there's no better team.\n\
Arm in arm, we'll win the fight, it's always been our dream !\n\
\n\
Pokemon ! Gotta catch 'em !\n\
It's you and me !\n\
I know it's my destiny !\n\
Pokemon ! Gotta catch 'em !\n\
Oh, you're my best friend !\n\
In the world we must defend !\n\
Pokemon ! Gotta catch 'em !\n\
A heart so true !\n\
Our courage will pull us through !\n\
You teach me and I teach you !\n\
Poookeeemooon !\n\
Gotta catch 'em all ! Gotta catch 'em all ! Pokemon !\n\
\n\
(instrumental)\n\
\n\
Pokemon ! Gotta catch 'em !\n\
It's you and me !\n\
I know it's my destiny !\n\
Pokemon ! Gotta catch 'em !\n\
Oh, you're my best friend !\n\
In the world we must defend !\n\
Pokemon ! Gotta catch 'em !\n\
A heart so true !\n\
Our courage will pull us through !\n\
You teach me and I teach you !\n\
Poookeeemooon !\n\
Gotta catch 'em all ! Gotta catch 'em all ! Pokemon !"},
{0}
};

int	test_ft_strdup(int *const ret)
{
	char	*str0;
	char	*str1;
	int		i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		str0 = strdup(g_test[i].str);
		if (!str0)
			return (*ret = STRDUP_ERR);
		str1 = ft_strdup(g_test[i].str);
		if (!str1)
		{
			free(str0);
			return (*ret = FT_STRDUP_ERR);
		}
		result(g_test[i].num,
			!strcmp(str0, str1));
		free(str0);
		free(str1);
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
