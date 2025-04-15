# Couleurs pour une meilleure lisibilité
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
BOLD = \033[1m
RESET = \033[0m

# Compilateur et flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Nom du programme
NAME = intern

# Fichiers sources
SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp \
       Intern.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Fichiers d'en-tête
HEADERS = Bureaucrat.hpp \
          AForm.hpp \
          ShrubberyCreationForm.hpp \
          RobotomyRequestForm.hpp \
          PresidentialPardonForm.hpp \
          Intern.hpp

# Cible par défaut
all: header $(NAME)

# Affiche un en-tête
header:
	@echo "$(BOLD)$(MAGENTA)"
	@echo "╔══════════════════════════════════════════════════════════╗"
	@echo "║                                                          ║"
	@echo "║        CPP Module 05 - Exercise 03 - Bureaucracy        ║"
	@echo "║                                                          ║"
	@echo "╚══════════════════════════════════════════════════════════╝$(RESET)"

# Compilation du programme
$(NAME): $(OBJS)
	@echo "$(YELLOW)Compilation en cours...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✓ Compilation terminée! Exécutable: $(CYAN)$(NAME)$(RESET)"

# Compilation des fichiers source en fichiers objets
%.o: %.cpp $(HEADERS)
	@echo "$(BLUE)Compilation de $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers objets
clean:
	@echo "$(YELLOW)Suppression des fichiers objets...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)$(BOLD)✓ Fichiers objets supprimés.$(RESET)"

# Nettoyer les fichiers objets et l'exécutable
fclean: clean
	@echo "$(YELLOW)Suppression de l'exécutable...$(RESET)"
	@rm -f $(NAME)
	@rm -f *_shrubbery
	@echo "$(GREEN)$(BOLD)✓ Exécutable supprimé.$(RESET)"

# Tout reconstruire
re: fclean all

# Reconstruire et exécuter le programme
run: re
	@echo "$(BOLD)$(CYAN)Lancement du programme:$(RESET)"
	@./$(NAME)

# Cibles fictives
.PHONY: all clean fclean re run header