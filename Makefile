SRCS		=	main.c \
				ft_libft.c \
				ft_utils.c	\
				ft_monitor.c	\
				ft_atoi.c	\
				ft_init_phil.c	\
				ft_init_mut.c	\
				ft_phils_life.c



OBJS		=	$(SRCS:.c=.o)

LBFTDR		=	libft

CC			=	gcc

NAME    	=   philo

RM			= 	rm -f

%.o:%.c
				gcc -c -g $< -o $@
				gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME):		$(OBJS)
				#$(CC) $(OBJS) $(LBFTDR)/libft.a $(FL_TERM) $(FL_RDLN) -o $(NAME)
				$(CC) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: 		all clean mlx fclean re