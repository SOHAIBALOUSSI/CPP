NAME = AForm
CC = c++ 
CPPFLAGS = -Wall -Wextra -Werror
CPPVERSION = -std=c++98
SRCS = main.cpp AForm.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(CPPVERSION) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CPPVERSION) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f *_shrubbery

re : fclean all