################################################################################
################################################################################
############################/? MAIN FILES ?/####################################
################################################################################
################################################################################

NAME		=	ft_containers

SRC_FILES 	=	main.cpp

OBJS_DIR	=	objs

SRC_DIR		=	./srcs/

INC_DIR		=	./include/

INC_FILES	=	Stack.hpp \
				Vector.hpp \
				Map.hpp \
				utils/IteratorsTraits.hpp \
				utils/ReverseIterator.hpp \
				utils/Iterator.hpp \
				utils/RandomAccessIterator.hpp \
				utils/AVL_BST.hpp \

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRC_FILES:.cpp=.o))

INCLUDE		=	$(addprefix $(INC_DIR)/, $(INC_FILES))

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -g -std=c++98

RM			=	rm -rf

RESET		=	\033[0m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
WHITE		=	\033[1;37m
ORANGE		=	\033[1;38;5;208m
UP			=	\033[A
CUT			=	\033[K

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
				@echo "$(CUT)$(BLUE)clang $(RESET)$(notdir $@)"
				@printf "$(UP)"

all:	$(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $^ -o $@
				@echo "$(CUT)$(GREEN)✔ $(NAME) created$(RESET)"

clean:
				@$(RM) $(OBJS) $(OBJS_DIR)
				@echo "$(RED)✘ clean$(RESET)"

fclean:	clean
				@$(RM) $(NAME)
				@echo "$(RED)✘ fclean$(RESET)"

re:		fclean all

################################################################################
################################################################################
############################/? TEST FILES ?/####################################
################################################################################
################################################################################

TEST_NAME		=	ft_containers_test

TEST_SRC_FILES	=	main_test.cpp

TEST_OBJS_DIR	=	test/objs

TEST_SRC_DIR	=	test/srcs

TEST_INC_DIR	=	test/include

TEST_INC_FILES	=	vector_assign.h

TEST_OBJS		=	$(addprefix $(TEST_OBJS_DIR)/, $(TEST_SRC_FILES:.cpp=.o))

TEST_INC		=	$(addprefix $(TEST_INC_DIR)/, $(TEST_INC_FILES))

GTEST_INCLUDE	=	./test/googletest/googletest/include/

CC				=	c++

GTEST_FLAGS		=	./test/googletest/lib/libgtest.a -lpthread

$(TEST_OBJS_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp $(TEST_INC)
				@mkdir -p $(@D)
				@$(CC) -I$(GTEST_INCLUDE) -Igtest -c $< -o $@
				@echo "$(CUT)$(BLUE)clang $(RESET)$(notdir $@)"
				@printf "$(UP)"

test:	$(TEST_NAME)

$(TEST_NAME):		$(TEST_OBJS)
					@$(CC) -pthread -I$(GTEST_INCLUDE) $^ -o $@ $(GTEST_FLAGS) -g
					@echo "$(CUT)$(GREEN)✔ $(TEST_NAME) created$(RESET)"
					#@valgrind --leak-check=full ./$@
					@./$@
					@$(RM) $(TEST_OBJS) $(TEST_OBJS_DIR) $(TEST_NAME)

.DELETE_ON_ERROR:
					$(TEST_NAME)
					$(TEST_OBJS)

.PHONY:	all clean fclean re test

