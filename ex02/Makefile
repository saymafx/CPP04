CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		Animal.cpp \
		Brain.cpp \

OBJ = $(SRC:%.cpp=%.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all : a.out

a.out : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o a.out

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf a.out

re : fclean all
