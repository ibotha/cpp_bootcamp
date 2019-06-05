NAME=Accountclass

SOURCE=Account.class.cpp tests.cpp

ODIR=obj
OBJECTS := $(patsubst %.cpp, $(ODIR)/%.o, $(SOURCE))

DEPS=Account.class.hpp

CC=clang++

CFLAGS=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(ODIR) $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS) $(CFLAGS)

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