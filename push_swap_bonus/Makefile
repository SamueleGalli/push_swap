#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := checker
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      CHECKING/stringer.c \
                          CHECKING/check_val.c \
                          BONUS/sa_sb_ss_pa_pb_check.c \
                          BONUS/ra_rb_rr_check.c \
                          BONUS/rra_rrb_rrr_check.c \
                          checker.c \
                          libft/ft_toupper.c \
                          libft/ft_tolower.c \
                          libft/ft_split.c \
                          libft/ft_memcpy.c \
                          libft/ft_lstsize.c \
                          libft/ft_strnstr.c \
                          libft/ft_isalnum.c \
                          libft/ft_strlcat.c \
                          libft/ft_strchr.c \
                          libft/ft_lstiter.c \
                          libft/ft_isdigit.c \
                          libft/ft_itoa.c \
                          libft/ft_lstclear.c \
                          libft/ft_strlcpy.c \
                          libft/ft_strrchr.c \
                          libft/ft_isprint.c \
                          libft/ft_isascii.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_strcmp.c \
                          libft/ft_strjoin.c \
                          libft/ft_lstmap.c \
                          libft/ft_display_exit.c \
                          libft/ft_striteri.c \
                          libft/ft_strncmp.c \
                          libft/ft_get_next_line.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_memset.c \
                          libft/ft_strlen.c \
                          libft/ft_atoi.c \
                          libft/ft_strmapi.c \
                          libft/ft_lstlast.c \
                          libft/ft_bzero.c \
                          libft/ft_substr.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_strdup.c \
                          libft/ft_isalpha.c \
                          libft/ft_lstdelone.c \
                          libft/ft_lstnew.c \
                          libft/ft_memchr.c \
                          libft/ft_memmove.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_strtrim.c \
                          libft/ft_memcmp.c \
                          libft/ft_calloc.c \
                          OTHERS/continue.c \
                          SORT/ra_rb_rr.c \
                          SORT/sorting.c \
                          SORT/sa_sb_ss_pa_pb.c \
                          SORT/rra_rrb_rrr.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


