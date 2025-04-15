#include "Bureaucrat.hpp"

/**
 * Default constructor
 */
Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

/**
 * Parameterized constructor with validation
 */
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;

    // Validate grade range
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }

    this->_grade = grade;
}

/**
 * Copy constructor
 */
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

/**
 * Assignment operator
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;

    if (this != &rhs) {
        // Can't assign to const members (_name), only copy grade
        this->_grade = rhs._grade;
    }
    return *this;
}

/**
 * Destructor
 */
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

/**
 * Get the bureaucrat name
 */
std::string Bureaucrat::getName() const {
    return this->_name;
}

/**
 * Get the bureaucrat grade
 */
int Bureaucrat::getGrade() const {
    return this->_grade;
}

/**
 * Increment the bureaucrat grade (lower the grade value)
 */
void Bureaucrat::incrementGrade() {
    std::cout << "Attempting to increment grade of " << this->_name << " from " << this->_grade << std::endl;

    if (this->_grade <= 1) {
        throw Bureaucrat::GradeTooHighException();
    }

    this->_grade--;
    std::cout << "Grade successfully incremented to " << this->_grade << std::endl;
}

/**
 * Decrement the bureaucrat grade (raise the grade value)
 */
void Bureaucrat::decrementGrade() {
    std::cout << "Attempting to decrement grade of " << this->_name << " from " << this->_grade << std::endl;

    if (this->_grade >= 150) {
        throw Bureaucrat::GradeTooLowException();
    }

    this->_grade++;
    std::cout << "Grade successfully decremented to " << this->_grade << std::endl;
}

/**
 * Sign a form if the bureaucrat has sufficient grade
 */
void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->_name << " couldn't sign " << form.getName()
                 << " because: " << e.what() << std::endl;
    }
}

/**
 * Execute a form if the bureaucrat has sufficient grade and the form is signed
 */
void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->_name << " couldn't execute " << form.getName()
                 << " because: " << e.what() << std::endl;
    }
}

/**
 * GradeTooHighException implementation
 */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high (must be at least 1)";
}

/**
 * GradeTooLowException implementation
 */
const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low (must be at most 150)";
}

/**
 * Insertion operator overload for Bureaucrat
 */
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}