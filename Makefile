NAME = libfts.a

SRCSDIR = srcs/

OBJSDIR = objs/

SRCS = 	ft_isalnum.s \
		ft_isalpha.s \
		ft_isascii.s \
		ft_isdigit.s \
		ft_islower.s \
		ft_isprint.s \
		ft_isupper.s \
		ft_memcpy.s \
		ft_memset.s \
		ft_puts.s \
		ft_strdup.s \
		ft_strlen.s \
		ft_tolower.s \
		ft_toupper.s

OBJS = $(addprefix $(OBJSDIR),$(SRCS:.s=.o))

$(OBJSDIR)%.o: $(SRCSDIR)%.s Makefile
	@mkdir -p $(OBJSDIR)
	nasm -f macho64 -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

test: $(NAME)
	gcc main.c  -I includes/ -L./ -lfts

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
