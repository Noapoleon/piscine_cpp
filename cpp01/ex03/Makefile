# Project Structure
NAME	=	violence
SRCDIR	=	srcs
INCDIR	=	incs
OBJDIR	=	objs

# Compiler Options
CC		=	c++
#CC		=	c++ -g
CFLAGS	=	-Wall -Wextra -Werror -MD -std=c++98
CINCS	=	-I./$(INCDIR)

# Other
RM	=	rm -rf

# Files
SRCS	:=	main.cpp \
			Weapon.cpp \
			HumanA.cpp \
			HumanB.cpp
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
