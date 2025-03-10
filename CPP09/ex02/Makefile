NAME = PmergeMe
CC = c++ 
CPPFLAGS = #-Wall -Wextra -Werror
CPPVERSION = -std=c++98
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CPPFLAGS) $(CPPVERSION) $(OBJS) -o $(NAME)

%.o: %.cpp *.hpp
	$(CC) $(CPPFLAGS) $(CPPVERSION) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re : fclean all