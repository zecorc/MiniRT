NAME		= miniRT

SRCS_LIST	= 	main.c \
				iwu.c \
				ray_utils.c

SRCS		= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS		= ${SRCS:.c=.o}

HEADER		= includes
FOLDER		= files
MLX			= minilibx
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(CFLAGS) $(LFLAGS) -I $(HEADER) $(OBJS) -o $(NAME)

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM)	$(NAME)
		
re:		fclean all