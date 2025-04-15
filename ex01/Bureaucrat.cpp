#include "Bureaucrat.hpp"

// === Orthodox Canonical Form Implementation ===

/**
 * @brief Default constructor that creates a Bureaucrat with name "Unknown" and grade 150
 */
Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150) {
    std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Parameterized constructor that creates a Bureaucrat with a specified name and grade
 *
 * @param name The bureaucrat's name
 * @param grade The bureaucrat's grade (must be between 1 and 150)
 * @throw GradeTooHighException if grade < 1
 * @throw GradeTooLowException if grade > 150
 */
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    std::cout << "Parameterized constructor called" << std::endl;

    // Grade validation
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();

    _grade = grade;
}

/**
 * @brief Copy constructor
 *
 * @param src The Bureaucrat to copy from
 */
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
    std::cout << "Copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator overload
 *
 * @param rhs The Bureaucrat to assign from
 * @return Bureaucrat& Reference to this object after assignment
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    std::cout << "Assignment operator called" << std::endl;

    // Can't assign to _name as it's const, but we can assign the grade
    if (this != &rhs) {
        // const_cast is generally not recommended, but we need to handle const name in assignment
        // We need to do this carefully since we can't actually change _name
        this->_grade = rhs._grade;
    }
    return *this;
}

/**
 * @brief Destructor
 */
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

// === Getters ===

/**
 * @brief Get the bureaucrat's name
 *
 * @return std::string The bureaucrat's name
 */
std::string Bureaucrat::getName() const {
    return _name;
}

/**
 * @brief Get the bureaucrat's grade
 *
 * @return int The bureaucrat's grade (1-150)
 */
int Bureaucrat::getGrade() const {
    return _grade;
}

// === Grade Modification Methods ===

/**
 * @brief Increment the bureaucrat's grade (decrease the grade value)
 *
 * @throw GradeTooHighException if grade would become < 1
 */
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
    std::cout << _name << " has been promoted to grade " << _grade << std::endl;
}

/**
 * @brief Decrement the bureaucrat's grade (increase the grade value)
 *
 * @throw GradeTooLowException if grade would become > 150
 */
void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
    std::cout << _name << " has been demoted to grade " << _grade << std::endl;
}

/**
 * @brief Attempt to sign a form
 *
 * @param form The form to sign
 */
void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

// === Exception Classes Implementation ===

/**
 * @brief Error message for GradeTooHighException
 *
 * @return const char* The error message
 */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Error: Grade is too high! Grade cannot be less than 1.";
}

/**
 * @brief Error message for GradeTooLowException
 *
 * @return const char* The error message
 */
const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Error: Grade is too low! Grade cannot be greater than 150.";
}

// === Operator Overloads ===

/**
 * @brief Insertion operator overload for Bureaucrat
 *
 * Outputs the bureaucrat in the format: "<name>, bureaucrat grade <grade>"
 *
 * @param os The output stream
 * @param bureaucrat The Bureaucrat to output
 * @return std::ostream& The output stream
 */
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}