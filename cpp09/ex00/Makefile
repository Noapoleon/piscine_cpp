# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlegrand <nlegrand@stud.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 18:42:40 by nlegrand          #+#    #+#              #
#    Updated: 2024/02/21 18:31:43 by nlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Structure
NAME	=	btc
SRCDIR	=	srcs
OBJDIR	=	objs
INCDIR	=	incs

# Compiler Options
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MD -g
CINCS	=	-I./$(INCDIR)

# Other
RM	=	rm -rf

# Files
SRCS	:=	main.cpp \
			BitcoinExchange.cpp
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

test:
	@echo $(OBJS)

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
