# Project Structure
NAME	=	mapb
SRCDIR	=	srcs
OBJDIR	=	objs
INCDIR	=	incs

# Compiler Options
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MD
CINCS	=	-I./$(INCDIR)

# Other
RM	=	rm -rf

# Files
SRCS	:=	main.cpp \
			utils.cpp \
			PhoneBook.cpp \
			Contact.cpp
OBJS	:=	$(SRCS:.cpp=.o)
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

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
