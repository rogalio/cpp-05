#include "ShrubberyCreationForm.hpp"
#include <fstream>

/**
 * Default constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

/**
 * Parameterized constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

/**
 * Copy constructor
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

/**
 * Assignment operator
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;

    if (this != &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

/**
 * Destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

/**
 * Get the target for the form
 */
std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

/**
 * Execute the form's action - create a file with ASCII trees
 */
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    // Check if the form is signed and the executor has sufficient grade
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    // Create and write to the target file
    std::string filename = this->_target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open()) {
        throw ShrubberyCreationForm::FileCreationException();
    }

    // ASCII tree art
    outfile << "               ,@@@@@@@,\n"
            << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
            << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
            << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
            << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
            << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
            << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
            << "       |o|        | |         | |\n"
            << "       |.|        | |         | |\n"
            << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

    outfile.close();
    std::cout << "Created shrubbery file: " << filename << std::endl;
}

/**
 * FileCreationException implementation
 */
const char *ShrubberyCreationForm::FileCreationException::what() const throw() {
    return "Failed to create or write to the shrubbery file";
}