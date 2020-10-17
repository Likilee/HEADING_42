.SUFFIXEX : .c .o
NAME = my_header
LIB = lib.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
AFLAGS = rc
INCLUDES = -I ./Includes
SRCS_DIR = ./Srcs
SRCS_NAME = main.c \
			ft_strlen.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_split.c \
			ft_strlcpy.c \
			ft_strtrim.c \
			ft_arr_free.c \
			ft_strncmp.c \
			ft_strjoin.c \
			ft_toupper.c \
			ft_strdup.c \
			ft_strnstr.c \
			get_next_line.c \
			get_next_line_utils.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJECTS = $(SRCS:.c=.o)

all : $(NAME) clean

clean :
	rm -rf $(OBJECTS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
	make clean
$(NAME) : $(OBJECTS)
	 $(CC) $(CFLAGS) $(OBJECTS) -o $@ -I ./
%.o : %.c
	$(CC) $(CFLAGS) $? -c -o $@ $(INCLUDES)
.PHONY : all clean fclean re bonus
