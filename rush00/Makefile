NAME= ft_retro

SOURCE=	main.cpp\
		Game.cpp\
		AEntity.cpp\
		EntityList.cpp\
		Enemy.cpp\
		Player.cpp\
		Projectile.cpp\
		sprite.cpp

DEPS=	Game.hpp\
		AEntity.hpp\
		EntityList.hpp\
		Enemy.hpp\
		Player.hpp\
		Projectile.hpp\
		Sprite.hpp

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
