#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

/**
 * @brief Intern class that can create different types of forms
 *
 * This class represents an unnamed, ungraded intern whose sole purpose
 * is to create forms of different types based on form name strings.
 */
class Intern {
public:
    // Orthodox Canonical Form implementation
    Intern();
    Intern(const Intern &src);
    Intern &operator=(const Intern &rhs);
    ~Intern();

    // Form creation method
    AForm *makeForm(const std::string &formName, const std::string &target) const;

    // Exception for unknown form type
    class UnknownFormException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

private:
    // Function pointer for form creation methods
    typedef AForm *(Intern::*FormCreator)(const std::string &target) const;

    // Form creation methods
    AForm *createShrubberyCreationForm(const std::string &target) const;
    AForm *createRobotomyRequestForm(const std::string &target) const;
    AForm *createPresidentialPardonForm(const std::string &target) const;

    // Static array to map form names to creation methods
    static const int FORM_COUNT = 3;
    struct FormType {
        std::string name;
        FormCreator creator;
    };
};

#endif