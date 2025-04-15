#include "PresidentialPardonForm.hpp"

/**
 * Default constructor
 */
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

/**
 * Parameterized constructor
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

/**
 * Copy constructor
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src), _target(src._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

/**
 * Assignment operator
 */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;

    if (this != &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

/**
 * Destructor
 */
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

/**
 * Get the target for the form
 */
std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}

/**
 * Execute the form's action - inform that the target has been pardoned
 */
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    // Check if the form is signed and the executor has sufficient grade
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    // Inform about the pardon
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}