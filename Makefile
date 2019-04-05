NAME = libfts.a

SRCSDIR = srcs/

OBJSDIR = objs/

SRCS = ft_strlen.s

OBJS = $(addprefix $(OBJSDIR),$(SRCS:.s=.o))

$(OBJSDIR)%.o: $(SRCSDIR)%.s Makefile
	@mkdir -p $(OBJSDIR)
	nasm -f macho64 -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

test:
	gcc main.c -L./ -lfts

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
