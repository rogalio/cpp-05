# Makefile for ex01: Form

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
NAME = form

# Source files
SRCS = main.cpp Bureaucrat.cpp Form.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Colors for terminal output
RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

# Default target
all: $(NAME)

# Rule to compile the executable
$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling executable...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' compiled successfully!$(RESET)"

# Rule to compile source files to object files
%.o: %.cpp
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(YELLOW)Removing object files...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)Object files removed!$(RESET)"

# Clean object files and executable
fclean: clean
	@echo "$(YELLOW)Removing executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Executable removed!$(RESET)"

# Clean and recompile
re: fclean all

# These targets do not represent files
.PHONY: all clean fclean re