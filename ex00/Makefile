CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ClapTrap.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = claptrap

${NAME}: ${OBJS}
		${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean: 
		rm -rf ${OBJS}
fclean: clean	
		rm -f ${NAME}
re: fclean all

.PHONY: re fclean clean all 