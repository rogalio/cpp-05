#include "AForm.hpp"

/**
 * Default constructor
 */
AForm::AForm() : _name("Default Form"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {
    std::cout << "AForm default constructor called" << std::endl;
}

/**
 * Parameterized constructor
 */
AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute)
    : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {

    std::cout << "AForm parameterized constructor called" << std::endl;

    // Validate grade ranges
    if (grade_to_sign < 1 || grade_to_execute < 1) {
        throw AForm::GradeTooHighException();
    } else if (grade_to_sign > 150 || grade_to_execute > 150) {
        throw AForm::GradeTooLowException();
    }
}

/**
 * Copy constructor
 */
AForm::AForm(const AForm &src)
    : _name(src._name), _is_signed(src._is_signed),
      _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute) {

    std::cout << "AForm copy constructor called" << std::endl;
}

/**
 * Assignment operator
 */
AForm &AForm::operator=(const AForm &rhs) {
    std::cout << "AForm assignment operator called" << std::endl;

    if (this != &rhs) {
        // Can't assign to const members, only copy the sign status
        this->_is_signed = rhs._is_signed;
    }
    return *this;
}

/**
 * Destructor
 */
AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

/**
 * Get the form name
 */
std::string AForm::getName() const {
    return this->_name;
}

/**
 * Get the form signature status
 */
bool AForm::getIsSigned() const {
    return this->_is_signed;
}

/**
 * Get the required grade to sign
 */
int AForm::getGradeToSign() const {
    return this->_grade_to_sign;
}

/**
 * Get the required grade to execute
 */
int AForm::getGradeToExecute() const {
    return this->_grade_to_execute;
}

/**
 * Signing method for bureaucrats
 */
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_grade_to_sign) {
        throw AForm::GradeTooLowException();
    }
    this->_is_signed = true;
}

/**
 * GradeTooHighException implementation
 */
const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high (must be at least 1)";
}

/**
 * GradeTooLowException implementation
 */
const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low (must be at most 150)";
}

/**
 * FormNotSignedException implementation
 */
const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed and cannot be executed";
}

/**
 * Insertion operator overload for AForm
 */
std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form: " << form.getName()
       << ", Sign Grade: " << form.getGradeToSign()
       << ", Execute Grade: " << form.getGradeToExecute()
       << ", Status: " << (form.getIsSigned() ? "Signed" : "Unsigned");
    return os;
}