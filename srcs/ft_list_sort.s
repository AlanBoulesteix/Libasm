;void ft_list_sort(t_list **begin_list, int (*cmp)())
section .text
	global ft_list_sort

ft_list_sort: ;rdi = begin_list, rsi = cmp
