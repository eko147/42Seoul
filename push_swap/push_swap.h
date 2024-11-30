/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:42:51 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/04 21:35:01 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef enum e_oper
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}		t_oper;

typedef struct s_list{
	int				value;
	struct s_list	*next;
}		t_list;

typedef struct s_info
{
	int		*num;
	int		arg_cnt;
	int		pv1;
	int		pv2;
	int		ra;
	int		rb;
	int		pb;
	int		pa;
	t_list	*a_stack;
	t_list	*b_stack;
	t_list	*oper_list;
}			t_info;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c, int	*i);
int		ft_atoi(const char *str, int idx, long long sign, long long res);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	print_operater(char	*str);
void	exit_from_err(char *message);
char	**free_all(char **arr);
void	creat_a_stack(t_info *info);
void	sa(t_info	*info, int flag);
void	sb(t_info	*info, int flag);
void	ss(t_info	*info);
void	pb(t_info	*info);
void	pa(t_info	*info);
void	ra(t_info	*info, int flag);
void	rb(t_info	*info, int flag);
void	rr(t_info	*info);
void	rra(t_info	*info, int flag);
void	rrb(t_info	*info, int flag);
void	rrr(t_info	*info);
void	devide_a_to_b(t_info	*info, int size);
void	raise_a_b_part(t_info	*info);
void	raise_b_c_part(t_info	*info, int ra, int rb);
void	a_to_b(t_info	*info, int size);
void	b_to_a(t_info	*info, int size);
void	hard_sort_for_b(t_info *info, int size);
void	first_a_to_b(t_info	*info, int size);
int		*set_int_arr_for_sort(t_list *list, int size);
void	b_to_a(t_info	*info, int size);
void	hard_sort(t_info *info);
void	hard_sort_for_a(t_info *info, int size);
void	hard_sort_for_b(t_info *info, int size);
void	a_to_b_hard_sort(t_info *info, int size);
void	b_to_a_hard_sort(t_info *info, int size);
t_list	*ft_lstlast(t_list *lst);
void	creat_oper_list(t_info *info, t_oper type);
void	print_oper_list(t_list	*oper);
void	print_oper(t_oper type);
void	test_print(t_info	*info);
void	check_double(t_info	*info);
void	check_sort(t_info *info);
void	bubblesort(int arr[], int n);
t_list	*ft_lstlast(t_list *lst);
int		second_to_last(t_list *lst);

#endif
