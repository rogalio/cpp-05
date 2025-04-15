#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

/**
 * @brief ShrubberyCreationForm class for creating ASCII trees
 *
 * This concrete form creates a file named <target>_shrubbery in the working
 * directory and writes ASCII trees inside it when executed.
 * Required grades: sign 145, exec 137
 */
class ShrubberyCreationForm : public AForm {
private:
    std::string _target;  // Target for the form's action

public:
    // Orthodox Canonical Form implementation
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
    virtual ~ShrubberyCreationForm();

    // Getter for target
    std::string getTarget() const;

    // Implementation of abstract execute method
    virtual void execute(Bureaucrat const & executor) const;

    // Exception for file creation errors
    class FileCreationException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif