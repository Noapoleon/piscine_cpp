# Project Structure
NAME	=	megaphone

# Compiler Options
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

# Other
RM	=	rm -rf

# Files
SRCS	:=	megaphone.cpp
OBJS	:=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
