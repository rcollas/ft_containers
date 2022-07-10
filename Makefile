NAME		=	ft_containers

NAME_TEST	=	ft_containers_test

SRC_FILES 	=	main.cpp \
				RBTree.cpp \

OBJS_DIR	=	objs

TEST_DIR	=	objs_test

SRC_DIR		=	./srcs/

INC_DIR		=	./include/

INC_FILES	=	Stack.hpp \
				Vector.hpp \
				Map.hpp \
				utils/IteratorsTraits.hpp \
				utils/ReverseIterator.hpp \
				utils/Iterator.hpp \
				utils/RandomAccessIterator.hpp \
				utils/RBTree.hpp \
				utils/RBTreeOP.hpp \

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRC_FILES:.cpp=.o))

STD_OBJS	=	$(addprefix $(TEST_DIR)/, $(SRC_FILES:.cpp=.o))

INCLUDE		=	$(addprefix $(INC_DIR)/, $(INC_FILES))

CC			=	clang++

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

$(TEST_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I$(INC_DIR) -DSTD -c $< -o $@
				@echo "$(CUT)$(BLUE)clang $(RESET)$(notdir $@)"
				@printf "$(UP)"

all:	$(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $^ -o $@
				@echo "$(CUT)$(GREEN)✔ $(NAME) created$(RESET)"

fclean:	clean
				@$(RM) $(NAME) diff.log ft_test.log std_test.log
				@echo "$(RED)✘ fclean$(RESET)"

test:	$(NAME_TEST)

DIFF			=	-@diff -sy --suppress-common-lines ft_test.log std_test.log

$(NAME_TEST):	$(OBJS) $(STD_OBJS)
				@$(CC) $(CFLAGS) $(STD_OBJS) -o $(NAME_TEST)
				@./$(NAME_TEST) > std_test.log
				@$(RM) $(STD_OBJS) $(TEST_DIR)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@./$(NAME) > ft_test.log
				@$(RM) $(OBJS) $(OBJS_DIR)
				@$(DIFF) > diff.log
				@$(DIFF)
				@rm ft_test.log std_test.log $(NAME) $(NAME_TEST)

clean:
				@$(RM) $(OBJS) $(OBJS_DIR)
				@echo "$(RED)✘ clean$(RESET)"



re:		fclean all

.PHONY:	all clean fclean re test diff
