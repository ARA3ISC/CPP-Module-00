NAME= phonebook
CC= c++
RM= rm -rf
FLAGS= -Werror -Wextra -Wall -std=c++98
SRC= main.cpp  phonebook.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
