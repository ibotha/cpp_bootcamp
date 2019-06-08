NAME=Weapons

SOURCE=main.cpp AWeapon.cpp PlasmaRifle.cpp PowerFist.cpp SuperMutant.cpp Enemy.cpp RadScorpion.cpp Character.cpp

DEPS=AWeapon.hpp PlasmaRifle.hpp PowerFist.hpp SuperMutant.hpp Enemy.hpp RadScorpion.hpp Character.hpp

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