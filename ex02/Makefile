# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Program name
NAME = forms

# Source files
SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Bureaucrat.hpp \
          AForm.hpp \
          ShrubberyCreationForm.hpp \
          RobotomyRequestForm.hpp \
          PresidentialPardonForm.hpp

# Default target
all: $(NAME)

# Compile program
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation completed. Executable: $(NAME)"

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)
	@echo "Object files removed."

# Clean object files and executable
fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery
	@echo "Executable removed."

# Rebuild everything
re: fclean all

# Rebuild and run the program
run: re
	./$(NAME)

# Phony targets
.PHONY: all clean fclean re run