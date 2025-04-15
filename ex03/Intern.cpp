#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

/**
 * Default constructor
 */
Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

/**
 * Copy constructor
 */
Intern::Intern(const Intern &src) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

/**
 * Assignment operator
 */
Intern &Intern::operator=(const Intern &rhs) {
    std::cout << "Intern assignment operator called" << std::endl;
    (void)rhs;  // Interns have no attributes to copy
    return *this;
}

/**
 * Destructor
 */
Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

/**
 * Create a ShrubberyCreationForm
 */
AForm *Intern::createShrubberyCreationForm(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}

/**
 * Create a RobotomyRequestForm
 */
AForm *Intern::createRobotomyRequestForm(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

/**
 * Create a PresidentialPardonForm
 */
AForm *Intern::createPresidentialPardonForm(const std::string &target) const {
    return new PresidentialPardonForm(target);
}

/**
 * Create a form based on the form name
 */
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    // Define the mapping of form names to creation methods
    static const FormType forms[FORM_COUNT] = {
        {"shrubbery creation", &Intern::createShrubberyCreationForm},
        {"robotomy request", &Intern::createRobotomyRequestForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };

    // Convert form name to lowercase for case-insensitive comparison
    std::string formNameLower = formName;
    std::transform(formNameLower.begin(), formNameLower.end(), formNameLower.begin(), ::tolower);

    // Find the matching form type and create it
    for (int i = 0; i < FORM_COUNT; i++) {
        if (formNameLower == forms[i].name) {
            AForm *form = (this->*forms[i].creator)(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    // No matching form found
    std::cerr << "Intern cannot create form: unknown form type '" << formName << "'" << std::endl;
    throw UnknownFormException();
}

/**
 * UnknownFormException implementation
 */
const char *Intern::UnknownFormException::what() const throw() {
    return "Unknown form type requested";
}