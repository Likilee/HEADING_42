.SUFFIXEX : .c .o
NAME = run_heading
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
AFLAGS = rc
INCLUDES = -I ./Includes
SRCS_DIR = ./Srcs
SRCS_NAME = main.c \
			put_top.c \
			put_include.c \
			put_define.c \
			put_struct.c \
			put_prototype.c \
			put_finish.c \
			do_align.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_split.c \
			ft_strchr.c \
			ft_strndup.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strtrim.c \
			ft_arr_free.c \
			ft_strncmp.c \
			ft_strjoin.c \
			ft_toupper.c \
			ft_strdup.c \
			ft_strnstr.c \
			get_next_line.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	@rm -rf $(OBJECTS)
fclean : clean
	@rm -rf $(NAME)
re : fclean all

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@
%.o : %.c
	@$(CC) $(CFLAGS) $? -c -o $@ $(INCLUDES)
.PHONY : all clean fclean re