NAME=megaphone

SOURCE=megaphone.cpp

ODIR=obj
OBJECTS := $(patsubst %.cpp, $(ODIR)/%.o, $(SOURCE))

DEPS=

CC=g++

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

$(ODIR):
	mkdir $(ODIR)

.PHONY: clean all fclean

read:
	echo $(OBJECTS)