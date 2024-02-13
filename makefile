NAME = libasm.a
EXEC = libasm
EXECBONUS = libasmExecBonus

SRCS = $(addsuffix .s, \
	ft_strlen \
	ft_strcpy \
	ft_strcmp \
	ft_write \
	ft_read \
	ft_strdup \
	ft_list_push_front \
	ft_list_size \
	ft_list_sort )

# BONUS = $(addsuffix .s, \
# 	ft_atoi_base)

OBJS = $(SRCS:%.s=srcs/.build/%.o)
DEPS = $(SRCS:%.s=srcs/.build/%.d)

# OBJSBONUS = $(BONUS:%.s=bonus/.build/%.o)
# DEPSBONUS = $(BONUS:%.s=srcs/.build/%.d)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

AS = nasm
ASFLAGS = -f elf64

AR = ar
ARFLAGS = rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

srcs/.build/%.o: srcs/%.s
	mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) $< -o $@ -MD -MP -MF $(@:.o=.d)

-include $(DEPS)

exec: $(NAME)
	$(CC) $(CFLAGS) -Iincludes main.c -L. -lasm -o $(EXEC)

bonus: $(NAME)
	$(CC) $(CFLAGS) -Iincludes mainbonus.c -L. -lasm -o $(EXECBONUS)

clean:
	$(RM) -rf srcs/.build

fclean: clean
	$(RM) $(NAME)
	$(RM) $(EXEC)
	$(RM) $(EXECBONUS)

re: fclean all

.PHONY: all clean fclean re exec
