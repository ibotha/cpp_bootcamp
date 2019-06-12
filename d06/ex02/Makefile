NAME=types

SOURCE=main.cpp A.cpp B.cpp C.cpp Base.cpp

DEPS=A.hpp B.hpp C.hpp Base.hpp

ODIR=obj
OBJECTS := $(patsubst %.cpp, $(ODIR)/%.o, $(SOURCE))

CC=clang++

CFLAGS=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(ODIR) $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(CFLAGS) -lncurses

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(ODIR):
	mkdir $(ODIR)

.PHONY: clean all fclean