# EXIT
NAME = get_next_line.a

# COMPILATION
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# SOURCES
SRC = get_next_line.c ft_substr.c ft_strlen.c ft_strjoin.c \
	  ft_find_pos.c ft_lstadd_back.c ft_lstlast.c ft_lstnew.c \

OBJS = $(SRC:.c=.o)

# LINKING
INCLUDE = get_next_line.h

$(NAME):$(OBJS) $(INCLUDE)
	ar -rcs $(NAME) $(OBJS)

# DEFAULT TARGET FOR COMPILATION
all: $(NAME)

# GENERATE .o FROM RESPECTIVE .c
%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

# CLEAN OBJETS
clean:
	rm -f $(OBJS)

# CLEAN OBJETS AND EXECUTABLE
fclean: clean
	rm -f $(NAME)

# CLEAN OBJETS AND EXECUTABLE AND THEN COMPILATION
re: fclean all

# KEY WORDS
.PHONY: all clean fclean re

