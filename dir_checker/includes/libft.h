/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:09:03 by elee              #+#    #+#             */
/*   Updated: 2016/11/18 13:55:08 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include <limits.h>

# define BUFF_SIZE 32
# define MAXPOWTWO 4.503599627370496000E+15
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define MIN(a, b) (((a) < (b)) ? (a) : (b))
# define ABS(a) (((a) < 0) ? -(a) : (a))
# define SWAP(a, b) {typeof(a) temp = a; a = b; b = temp;}

/*
** printf
*/

int					ft_printf(const char *format, ...);

intmax_t			dec_downcast(intmax_t n, char *str);
size_t				uns_downcast(size_t n, char *str);

int					is_neg(double n);
int					is_zero(double n);
int					is_in(double n);
int					get_exponent(double n);
int					ft_sci(double *i, double *f, int power, int fl[8]);

void				ft_putdi(intmax_t n, int fl[8]);
void				ft_putu(size_t n, int fl[8]);
void				ft_putb(size_t n);
void				ft_puto(size_t n);
void				ft_putx(size_t n, char spec);

int					ft_isflag(char c);
int					flag_parser(char *str, int fl[8]);
int					pos_parser(char *str, va_list *args, va_list copy);
int					mfw_parser(char *str, int fl[8], va_list *args);
int					prec_parser(char *str, int fl[8], va_list *args);
int					is_mod(char c);
int					is_spec(char c);
int					mp(char *str);
char				sp(char *str);

char				*wtos(wchar_t c, char b[6]);
int					ft_wlen(wchar_t *s, int fl[8]);

int					ft_preformat(int fl[8], int len);
int					ft_preformat2(int fl[8], int len, intmax_t n);
int					ft_preformat3(int fl[8], int len, void *s);
int					ft_preformat4(int fl[8], int len);
int					ft_preformat5(int fl[8], int len);
int					ft_postformat(int fl[8], int len, intmax_t n);
int					ft_postformat2(int fl[8], int len);
int					ft_postformat3(int fl[8], int len);
int					prec_calc(int len, int fl[8], int str);

int					ft_putextra(char c, int fl[8]);
int					ft_putn(int *n, int len);
int					ft_putc(int c, int fl[8]);
int					ft_putcapc(wchar_t c, int fl[8]);
int					ft_puts(char *s, int fl[8]);
int					ft_putr(char *s, int fl[8]);
int					ft_putcaps(wchar_t *s, int fl[8]);
int					ft_putdec(intmax_t ptr, int fl[8], char *str);
int					ft_putuns(size_t i, int fl[8], char *str);
int					ft_putbin(size_t i, int fl[8], char *str);
int					ft_putoct(size_t i, int fl[8], char *str);
int					ft_puthex(size_t i, int fl[8], char *str);
int					ft_putp(void *input, int fl[8]);

int					ft_putf(double n, int fl[8], char *s);
int					ft_pute(double n, int fl[8], char *s);
int					ft_putg(double n, int fl[8], char *s);
int					ft_puta(double n, int fl[8], char *s);
int					ft_putv(double n, int fl[8], char *s);

int					g_loop(double f, int fl[8], char *s);

/*
** ctype
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isascii(int c);

/*
** stdio
*/

int					ft_putchar(char c);
int					ft_putchar_fd(char c, int fd);
int					ft_putendl(char const *s);
int					ft_putendl_fd(char const *s, int fd);
int					ft_putnbr(int n);
int					ft_putnbr_fd(int n, int fd);
int					ft_putstr(const char *s);
int					ft_putstr_fd(const char *s, int fd);
int					get_next_line(const int fd, char **line);

/*
** stdlib
*/

int					ft_atoi(const char *str);
long int			ft_atol(const char *str);
double				ft_atof(const char *str);
char				*ft_itoa(int n);
char				*ft_ltoa(intmax_t n);
/*
** make double ft_ftoa(double n);
*/
int					ft_atoi_base(const char *str, int str_base);
char				*ft_itoa_base(int value, int base);
double				ft_modf(double n, double *iptr);
double				ft_rint(double x);

/*
** string
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, \
														size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, const char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strtrimc(char const *s, char trim);
char				*ft_strupcase(char *str);
char				*ft_strlowcase(char *str);
char				*ft_join(char **tab, char *sep);
char				**ft_split_whitespaces(char const *s);
char				**ft_strstrsplit(char const *s, char *c);
char				*ft_strresub(char *lines, size_t start);
char				*ft_strrecat(char *lines, char *input);

/*
** struct
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct		s_node
{
	void			*data;
	size_t			size;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

t_node				*create_node(void *data, size_t size);
void				delete_node(t_node **node_ptr, void (*del)(void *, size_t));

typedef struct		s_dlist
{
	t_node			*head;
	t_node			*tail;
}					t_dlist;

t_dlist				*create_dlist(void);
void				delete_dlist(t_dlist **dlist_ptr, \
						void (*del)(void *, size_t));
size_t				dl_size(t_dlist *dlist);
void				dl_push_front(t_dlist *dlist, void *data, size_t size);
void				*dl_top_front(t_dlist *list);
void				*dl_pop_front(t_dlist *list, void (*del)(void *, size_t));
void				dl_push_back(t_dlist *dlist, void *data, size_t size);
void				*dl_top_back(t_dlist *list);
void				*dl_pop_back(t_dlist *list, void (*del)(void *, size_t));
void				dl_display_forward(t_dlist *dlist);
void				dl_display_backward(t_dlist *dlist);

/*
** sort
*/
void				bubble_sort(int *array, int size);
void				insertion_sort(int *array, int size);
void				selection_sort(int *array, int size);
void				quick_sort(int *array, int l, int r);
void				merge_sort(int *array, int size);
void				heap_sort(int *array, int size);

/*
** misc
*/

long double			ft_pb(int power, int base);
int					ft_unsignedlen(unsigned long long n, int base);
int					ft_numlen(long long n);
int					ft_numlen2(long long n);
int					*ft_intnew(int num);
void				ft_free_two(char **p);
void				ft_free_three(char ***p);
void				delete_func(void *data, size_t size);
size_t				ft_ptrlen(char **ptr);
char				**ft_ptrnew(size_t size);
size_t				ft_count_chr(char *str, char c);
void				ft_bnull(char **s, size_t n);
int					ft_nextchr(char *str, char c);
#endif
