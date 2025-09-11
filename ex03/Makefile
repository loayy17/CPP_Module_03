CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98
SRCS = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = diamondTrap

${NAME}: ${OBJS}
		${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean: 
		rm -rf ${OBJS}
fclean: clean	
		rm -f ${NAME}
re: fclean all

.PHONY: re fclean clean all 