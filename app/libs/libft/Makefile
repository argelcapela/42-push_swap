# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 01:45:50 by acapela-          #+#    #+#              #
#    Updated: 2022/04/06 22:51:32 by acapela-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# libft makefile
#

SRCS =		ft_isalnum.c \
			ft_atoi.c \
			ft_isascii.c \
			ft_putstr_fd.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_bzero.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c\
			ft_calloc.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_chr_to_str.c \
			ft_str_merge.c \
			ft_str_replace.c \
			ft_free_ptr.c\
			ft_uitoa_base.c\

SRCS +=		get_next_line.c \
			ft_strjoin_free.c

SRCS +=		ft_printf/ft_printf.c \
			ft_printf/ft_printf_to_var.c \
			ft_printf/vendor/base/initialize_struct.c         \
			ft_printf/vendor/base/destroy_struct.c         \
			ft_printf/vendor/base/has_visible_signal.c         \
			ft_printf/vendor/base/remove_minus.c         \
			ft_printf/vendor/base/prepare_to_translation.c         \
			ft_printf/vendor/base/understanding_format.c         \
			ft_printf/vendor/base/what_flags.c         \
			ft_printf/vendor/base/what_format_type.c         \
			ft_printf/vendor/base/what_precision.c         \
			ft_printf/vendor/base/what_width.c         \
			ft_printf/vendor/translators/translate_percent.c \
			ft_printf/vendor/translators/translate_to_char.c  \
			ft_printf/vendor/translators/translate_to_decimal.c  \
			ft_printf/vendor/translators/translate_to_integer.c  \
			ft_printf/vendor/translators/translate_to_string.c  \
			ft_printf/vendor/translators/translate_to_unsigned_int.c  \
			ft_printf/vendor/translators/translate_to_pointer.c  \
			ft_printf/vendor/translators/translate_to_hexadecimal.c

SRCS +=		ft_free_matrix.c \
			ft_free_array.c \
			ft_hexatoi.c \
			ft_set_matrix.c \
			ft_print_matrix.c

SRCS +=		ft_str_replace_all.c     \
			ft_replace_all_matrix.c \
			ft_first_ocurrence.c \
			ft_last_ocurrence.c 
			
HEADER =	libft.h

OBJS =		$(SRCS:.c=.o)

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

AR =		ar -rcs

#
# 🔨Compilation and Linking 🔌
#

all:		libft.a

libft.a: 	$(OBJS) $(HEADER)
			$(AR) libft.a $(OBJS) $(HEADER)

%.o: 		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $<	-o $@

bonus:		all

clean:
			rm $(OBJS)

fclean:		clean
			rm libft.a

re:			fclean all

.PHONY:		clean fclean re
