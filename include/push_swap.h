/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:46:44 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/05 12:02:57 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib_main.h"

typedef struct s_inp_chec
{
	int			*int_list;
	int			num;
}				t_inp_chec;

typedef struct s_stack_a_b
{
	t_list_dc	*a;
	t_list_dc	*b;
	int			length_a;
	int			length_b;
	int			rel_bits;
	int			cur_bit;
	int			cur_bit_value;
	int			cur_int_limit;
}				t_stack_a_b;

/* check input */

t_inp_chec		*check_input(int argc, char *argv[]);
char			**check_input_only_int(int argc, char *argv[]);
char			**check_one_string_list(char **argv);
char			**check_many_string_args(int argc, char **argv);
char			**trim_check_str_list(char **str_list);
char			**trim_str_list(char **str_list);
char			**check_each_item(char **str_list);
int				check_item(char *str);
t_inp_chec		*check_dupli_int_range(char **only_ints);
int				check_duplicates(int cur_int, int *res_arr, int num);
int				check_int_range(char *int_str, int *res_int);
int				ft_strlen_1_to_9(char *int_str);
t_inp_chec		*free_char(char **only_ints);
t_inp_chec		*free_struct_char(char **only_ints, t_inp_chec *res);
t_inp_chec		*free_struct_list_char(char **only_ints, t_inp_chec *res);
int				input_is_sorted(t_inp_chec *checked_input);
int				input_invalid_or_sorted(t_inp_chec *checked_input);

/* ints to ranks */

t_inp_chec		*convert_vals_to_ranks(t_inp_chec *checked_input);
int				get_rank(int to_rank_index, t_inp_chec *checked_input);

t_inp_chec		*raise_error_struct(t_inp_chec *checked_input);
t_inp_chec		*raise_error_array(t_inp_chec *checked_input,
					t_inp_chec *checked_input_ranks);

/* set up stacks */

t_stack_a_b		*set_up_stacks(t_inp_chec *checked_input);
t_list_dc		*add_int_node(t_list_dc **stack, int i);
t_list_dc		*stack_add_first(int i);
void			initilise_sorting_params(t_stack_a_b *stack_a_b);
t_stack_a_b		*raise_error_inp(t_inp_chec *checked_input);
t_stack_a_b		*raise_error_inp_stack(t_inp_chec *checked_input,
					t_stack_a_b **stack_a_b);
void			free_checked_input(t_inp_chec *checked_input);
void			free_stack_a_b(t_stack_a_b **stack_a_b);

/* sort stacks */

t_stack_a_b		*sort_stack_main(t_stack_a_b *stack_a_b);
t_stack_a_b		*sort_stack_2(t_stack_a_b *stack_a_b);
t_stack_a_b		*sort_stack_3(t_stack_a_b *stack_a_b, int offset);
int				get_index(t_stack_a_b *stack_a_b, int val);
void			rev_rotate_push(t_stack_a_b *stack_a_b, int index);
void			rotate_push(t_stack_a_b *stack_a_b, int index);
t_stack_a_b		*push_smallest_2_to_b(t_stack_a_b *stack_a_b);
void			push_value_b(t_stack_a_b *stack_a_b, int val);

t_stack_a_b		*sort_stack_5(t_stack_a_b *stack_a_b);
t_stack_a_b		*sort_big_5(t_stack_a_b *stack_a_b);
void			push_small_to_b(t_stack_a_b *stack_a_b);
void			push_back_cond_to_a(t_stack_a_b *stack_a_b);
void			push_back_all_to_a(t_stack_a_b *stack_a_b);

/* stack operations */

void			push_b(t_stack_a_b *stack_a_b);
void			push_a(t_stack_a_b *stack_a_b);
void			rotate_a(t_stack_a_b *stack_a_b);
void			rotate_b(t_stack_a_b *stack_a_b);
void			rev_rotate_a(t_stack_a_b *stack_a_b);
void			rev_rotate_b(t_stack_a_b *stack_a_b);
void			swap_a(t_stack_a_b *stack_a_b);
void			swap_b(t_stack_a_b *stack_a_b);

#endif