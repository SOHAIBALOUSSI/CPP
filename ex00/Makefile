NAME = megaphone
CC = c++
CPPFLAGS = -Wall -Wextra -Werror
CPPVERSION = -std=c++98

all : $(NAME)

$(NAME): megaphone.o
	$(CC) $(CPPFLAGS) megaphone.o -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c megaphone.cpp -o megaphone.o

clean :
	@rm -f megaphone.o

fclean : clean
	@rm -f $(NAME)

re : fclean all