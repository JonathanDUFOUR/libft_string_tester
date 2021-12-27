# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 00:16:26 by jodufour          #+#    #+#              #
#    Updated: 2021/12/27 05:43:33 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CC					=	clang -c -o
LINK				=	clang -o
MKDIR				=	mkdir -p
RM					=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME				=	unit_test

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR				=	srcs/
OBJ_DIR				=	objs/
INC_DIR				=	
PRV_DIR				=	private/

FT_STRING_DIR		=	../
FT_STRING_INC_DIR	=	include/
FT_STRING_INC_DIR	:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_INC_DIR}}

#######################################
#              LIBRARIES              #
#######################################
FT_STRING_A			=	libft_string.a
FT_STRING_A			:=	${addprefix ${FT_STRING_DIR}, ${FT_STRING_A}}

######################################
#            SOURCE FILES            #
######################################
SRC					=	\
						${addprefix test/,			\
							test_ft_bzero.c			\
							test_ft_calloc.c		\
							test_ft_memccpy.c		\
							test_ft_memchr.c		\
							test_ft_memcmp.c		\
							test_ft_memcpy.c		\
							test_ft_memdel.c		\
							test_ft_memmove.c		\
							test_ft_memset.c		\
							test_ft_memswap.c		\
							test_ft_split.c			\
							test_ft_strcasecmp.c	\
							test_ft_strcat.c		\
							test_ft_strcdup.c		\
							test_ft_strchr.c		\
							test_ft_strcjoin.c		\
							test_ft_strcmp.c		\
							test_ft_strcpy.c		\
							test_ft_strdup.c		\
							test_ft_striter.c		\
							test_ft_striteri.c		\
							test_ft_strjoin.c		\
							test_ft_strlcat.c		\
							test_ft_strlcpy.c		\
							test_ft_strlen.c		\
							test_ft_strlink.c		\
							test_ft_strmap.c		\
							test_ft_strmapi.c		\
							test_ft_strncasecmp.c	\
							test_ft_strncat.c		\
							test_ft_strncmp.c		\
							test_ft_strncpy.c		\
							test_ft_strndup.c		\
							test_ft_strnstr.c		\
							test_ft_strrchr.c		\
							test_ft_strrev.c		\
							test_ft_strstr.c		\
							test_ft_strsubchr.c		\
							test_ft_strsubidx.c		\
							test_ft_strtrim.c		\
							test_ft_substr.c		\
						}							\
						err_msg.c					\
						main.c						\
						result.c

######################################
#            OBJECT FILES            #
######################################
OBJ				=	${SRC:.c=.o}
OBJ				:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP				=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CFLAGS			=	-Wall -Wextra# -Werror
CFLAGS			+=	-MMD -MP
CFLAGS			+=	-I${PRV_DIR}
CFLAGS			+=	-I${FT_STRING_INC_DIR}

LDFLAGS			=	-L${FT_STRING_DIR} -lft_string

ifeq (${DEBUG}, 1)
	CFLAGS		+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}:	${OBJ} ${FT_STRING_A}
	${LINK} $@ $^ ${LDFLAGS}

all:	${NAME}

-include ${DEP}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${MKDIR} ${@D}
	${CC} $@ ${CFLAGS} $<

${FT_STRING_A}:
	${MAKE} ${@F} -C ${@D}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore*

fclean:
	${RM} ${OBJ_DIR} ${NAME}
	${MAKE} $@ -C ${FT_STRING_DIR}

-include /home/jodufour/Templates/mk_files/coffee.mk
-include /home/jodufour/Templates/mk_files/norm.mk

re:	clean all

fre: fclean all

.PHONY:	all clean fclean re fre
