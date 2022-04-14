/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:34:46 by acapela-          #+#    #+#             */
/*   Updated: 2022/04/11 16:41:27 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// 1. write, read
# include <unistd.h>

// 2. malloc, free
# include <stdlib.h>

// 3. open
# include <fcntl.h>

// 4. pow
# include <math.h>

// 5. ft_printf and ft_printf_to_var
# include "ft_printf/ft_printf.h"

/*###############################################################
#																#
#																#
#	 						42-push_swap						#
#																#
#																#
###############################################################*/

size_t	ft_atos(const char *str);

/*###############################################################
#																#
#																#
#	 						42-pipex							#
#																#
#																#
###############################################################*/

char	*ft_str_replace_all(char *str, char *search, char *replace);

char	**ft_replace_all_matrix(char **matrix, char *search, char *replace);

int		ft_first_ocurrence(const char *str, int ch);

int		ft_last_ocurrence(const char *str, int ch);

/*###############################################################
#																#
#																#
#	 						42-fdf								#
#																#
#																#
###############################################################*/

char	**ft_split(char *s, char c);

void	ft_free_matrix(void **matrix);

void	ft_free_array(void **array);

int		ft_indexof(const char *str, int ch);

int		*ft_hexatoi(char *hexa);

void	ft_print_matrix(int **matrix, int width, int height);

void	ft_set_matrix(int **matrix, int width, int height, int ch);

/*###############################################################
#																#
#																#
#	 						42-printf							#
#																#
#																#
###############################################################*/

// FD that ft_putstr_fd will use to show the ft_printf response
# define FD 1

/* It's a way to apply tokenization technic, any time %% is passed in the
formatted string, or when 0(NULL) is passed as argument value, both assume
these tokens values, and at the final ft_putstr_fd will replace the tokens per
just % and ''. These avoid a lot of bugs. With the practice you will be aware
of it. */
# define TOKENIZATION_NULL    "___BANANA0_"

# define TOKENIZATION_PERCENT "___BANANA1_"

/* Useful to generate spaces and zeros of ' ' and 0 flag, and to transform c
to string before the final print.*/
char	*ft_chr_to_str(int c, size_t qtd);

// It's an strjoin a little more smart and simple
char	*ft_str_merge(char *s1, char *s2);

/* Super useful everywhere, we use it to replace the %something for values
passed as argument.*/
char	*ft_str_replace(char *str, char *search, char *replace);

// To avoid double free problems, etc. We free a pointer and set =NULL;
void	ft_free_ptr(void **ptr);

/* Transform a number to string but in a different base, for example, if you
 wana convert from base 10 to base 16, just put "0123456789abcdef" on the
 'base' argument, the logic is a variation of ft_itoa */
char	*ft_uitoa_base(size_t n, char *base);

/* Is the same ft_putstr_fd of libft, but with some increments, replacing the
defined and founded tokens and returns the number os bytes read */
int		ft_putstr_fd(char *s, int fd);

/*###################################################
#													#
#													#
#			  get-next-line							#
#													#
#													#
###################################################*/

char	*ft_strjoin_free(char *s1, char *s2);

char	*get_next_line(int fd);

/*###################################################
#													#
#													#
#			  Libft normal functions				#
#													#
#													#
###################################################*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);

void	ft_bzero(void *str, size_t n);

void	*ft_calloc(size_t num, size_t size);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

char	*ft_itoa(int n);

void	*ft_memchr(const void *str, int c, size_t n);

int		ft_memcmp(const void *str1, const void *str2, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memset(void *str, int c, size_t n);

void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

char	*ft_strchr(const char *str, int c);

char	*ft_strdup(const char *s);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlen(char const *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *s1, const char *s2, size_t n);

char	*ft_strrchr(const char *str, int c);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_tolower(int c);

char	ft_toupper(int c);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
