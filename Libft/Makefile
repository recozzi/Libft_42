NAME		:=	libft.a

CC			:=	gcc

CFLAGS		:=	-g -Wall -Wextra -Werror

AR			:=	ar -crs

RM			:=	rm -rf

SRCS 		:=	is/ft_isalpha.c						\
				is/ft_isdigit.c						\
				is/ft_isalnum.c						\
				is/ft_isascii.c						\
				is/ft_isprint.c						\
				is/ft_toupper.c						\
				is/ft_tolower.c						\
				is/ft_isspace.c						\
													\
				str/ft_strlen.c						\
				str/ft_strlcpy.c					\
				str/ft_strchr.c						\
				str/ft_strrchr.c					\
				str/ft_strncmp.c					\
    			str/ft_strnstr.c					\
				str/ft_atoi.c						\
				str/ft_strdup.c						\
				str/ft_strlcat.c					\
				str/ft_substr.c						\
				str/ft_strjoin.c					\
				str/ft_strmapi.c					\
				str/ft_striteri.c					\
				str/ft_strtrim.c					\
				str/ft_itoa.c						\
				str/ft_split.c						\
				str/ft_matrixlen.c					\
				str/ft_atol.c						\
				str/ft_strcmp.c						\
				str/ft_atof.c						\
				str/ft_strlen_offset.c				\
				str/ft_strlen_until.c				\
													\
				fd/ft_putstr_fd.c					\
				fd/ft_putendl_fd.c					\
				fd/ft_putchar_fd.c					\
				fd/ft_putnbr_fd.c					\
													\
				mem/ft_free.c						\
				mem/ft_memset.c						\
				mem/ft_bzero.c						\
				mem/ft_memcpy.c						\
				mem/ft_memmove.c					\
				mem/ft_memchr.c						\
				mem/ft_memcmp.c						\
				mem/ft_calloc.c						\
				mem/ft_realloc.c					\
													\
				lst/ft_lstadd_back.c				\
				lst/ft_lstadd_front.c				\
				lst/ft_lstclear.c					\
				lst/ft_lstdelone.c					\
				lst/ft_lstiter.c					\
				lst/ft_lstlast.c					\
				lst/ft_lstmap.c						\
				lst/ft_lstnew.c						\
				lst/ft_lstsize.c					\
													\
				get_next_line/get_next_line.c		\
													\
				ft_printf/ft_print_hex.c			\
				ft_printf/ft_print_pointer.c		\
				ft_printf/ft_printf.c				\
				ft_printf/ft_print_char.c			\
				ft_printf/ft_print_nbr.c			\
				ft_printf/ft_print_str.c			\
				ft_printf/ft_print_unbr.c			\
													\
				ft_printf_fd/ft_printf_fd.c			\
				ft_printf_fd/ft_print_char_fd.c		\
				ft_printf_fd/ft_print_hex_fd.c		\
				ft_printf_fd/ft_print_nbr_fd.c		\
				ft_printf_fd/ft_print_ptr_fd.c		\
				ft_printf_fd/ft_print_str_fd.c		\
				ft_printf_fd/ft_print_unbr_fd.c

OBJS_DIR	:=	obj/

SRCS_DIR	:=	src/

OBJS 		:=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# COLORS ================================================================= #

RED		=	\033[0;91m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
WHITE	=	\033[0;97m

# ======================================================================== #

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "$(GREEN)Compiling:$(WHITE) $<"

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(YELLOW)- Archive Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)All object files removed.$(WHITE)"

fclean: clean
	@$(RM) $(NAME) $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
