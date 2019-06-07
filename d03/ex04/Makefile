NAME=fragtrap

SOURCE=main.cpp FragTrap.cpp ScavTrap.cpp ClapTrap.cpp NinjaTrap.cpp SuperTrap.cpp

DEPS=FragTrap.hpp ScavTrap.hpp ClapTrap.hpp NinjaTrap.hpp SuperTrap.hpp

ODIR=obj
OBJECTS := $(patsubst %.cpp, $(ODIR)/%.o, $(SOURCE))

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