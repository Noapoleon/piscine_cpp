# Project Structure
NAME	=	brainz
SRCDIR	=	srcs
INCDIR	=	incs
OBJDIR	=	objs

# Compiler Options
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -MD -std=c++98
CINCS	=	-I./$(INCDIR)

# Other
RM	=	rm -rf

# Files
SRCS	:=	main.cpp \
			Zombie.cpp \
			zombieHorde.cpp
OBJS	:=	$(SRCS:.cpp=.o)
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if [ ! -d $(dir $@) ]; then \
		mkdir -p $(dir $@); \
	fi
	$(CC) $(CFLAGS) $(CINCS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
