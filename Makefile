CC = gcc

CINCLUDE = -IHEADERS

CFLAGS = -Wall -Wextra -Werror -IHEADERS

SOURCE = pipex.c function_1.c function_2.c function_3.c Utils/ft_split.c Utils/ft_strlen.c Utils/ft_strncmp.c \
Utils/ft_substr.c Utils/ft_strrchr.c Utils/ft_strdup.c Utils/ft_strjoin.c Utils/ft_isalpha.c \
Utils/ft_putstr_fd.c

BONUS = pipex_bonus.c function_1_bonus.c function_2_bonus.c function_3_bonus.c Utils/ft_split.c Utils/ft_strlen.c Utils/ft_strncmp.c \
Utils/ft_substr.c Utils/ft_strrchr.c Utils/ft_strdup.c Utils/ft_strjoin.c Utils/ft_isalpha.c Utils/get_next_line_bonus.c Utils/get_next_line_utils_bonus.c \
Utils/ft_putstr_fd.c

NAME = pipex

O_SOURCE = $(SOURCE:.c=.o)
O_BONUS = $(BONUS:.c=.o)
all: $(NAME)

$(NAME): $(O_SOURCE)
	$(CC) $(O_SOURCE) $(CFLAGS) $(CINCLUDE) -o $(NAME)

bonus: $(O_BONUS)
	$(CC) $(CFLAGS) $(O_BONUS) $(CINCLUDE) -o pipex_bonus

clean:
	rm -f $(NAME) $(O_SOURCE) $(O_BONUS) pipex_bonus
fclean: clean
	rm -f $(NAME) $(O_SOURCE) $(O_BONUS) pipex_bonus

re:	clean all