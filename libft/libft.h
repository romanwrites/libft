/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 06:25:28 by mkristie          #+#    #+#             */
/*   Updated: 2020/07/07 04:17:48 by mkristie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
** Part 1
*/
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				**ft_split(char const *s, char c);

/*
** Part 2
*/
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Bonus part
*/
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));

/*
** My funcs
*/
char				*ft_strjoin_free_s1(char *s1, char *s2);
char				*ft_strjoin_free(char *s1, char *s2, int which_to_free);
char				*ft_itoa_base(long long int number, int base);
char				*ft_itoa_base_u(unsigned long long int number, int base);
void				*ft_free_and_clear(char *str);
void				*ft_strdup_free(char *str);
char				*ft_itoa_u(int n);
int					ft_intlen_u(int num);
int					ft_isspace(int c);
void				ft_putchar(char c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isblank(int c);
int					ft_isgraph(int c);
int					ft_iscntrl(int c);
int					ft_isxdigit(int c);
int					ft_strequ(char const *s1, char const *s2);
char				**ft_free2d(char **strarr);
void				ft_strcpy(char *dst, const char *src);

#endif
