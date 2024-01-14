# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 18:42:40 by nlegrand          #+#    #+#              #
#    Updated: 2024/01/14 18:46:37 by nlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Structure
NAME	=	ex02
SRCDIR	=	srcs
OBJDIR	=	objs
INCDIR	=	incs

# Compiler Options
CC		=	c++
CFLAGS	=	-MD -std=c++98 -g
#CFLAGS	=	-Wall -Wextra -Werror -MD -std=c++98 -g
CINCS	=	-I./$(INCDIR)

# Other
RM	=	rm -rf

# Files
SRCS	:=	main.cpp \
			Array.tpp
OBJS	:=	$(SRCS:.[ct]pp=.o)
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.[ct]pp
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
