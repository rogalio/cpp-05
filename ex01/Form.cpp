#include "Form.hpp"

// === Orthodox Canonical Form Implementation ===

/**
 * @brief Default constructor that creates a Form with default values
 */
Form::Form() : _name("Unknown Form"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150) {
    std::cout << "Form default constructor called" << std::endl;
}

/**
 * @brief Parameterized constructor that creates a Form with specified values
 *
 * @param name The form's name
 * @param grade_to_sign The grade required to sign (1-150)
 * @param grade_to_execute The grade required to execute (1-150)
 * @throw GradeTooHighException if any grade < 1
 * @throw GradeTooLowException if any grade > 150
 */
Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute)
    : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
    std::cout << "Form parameterized constructor called" << std::endl;

    // Grade validation
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw Form::GradeTooLowException();
}

/**
 * @brief Copy constructor
 *
 * @param src The Form to copy from
 */
Form::Form(const Form &src)
    : _name(src._name), _is_signed(src._is_signed),
      _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute) {
    std::cout << "Form copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator overload
 *
 * @param rhs The Form to assign from
 * @return Form& Reference to this object after assignment
 */
Form &Form::operator=(const Form &rhs) {
    std::cout << "Form assignment operator called" << std::endl;

    // Can't assign to const members, but we can assign is_signed
    if (this != &rhs) {
        this->_is_signed = rhs._is_signed;
    }
    return *this;
}

/**
 * @brief Destructor
 */
Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

// === Getters ===

/**
 * @brief Get the form's name
 *
 * @return std::string The form's name
 */
std::string Form::getName() const {
    return _name;
}

/**
 * @brief Get whether the form is signed
 *
 * @return bool True if the form is signed, false otherwise
 */
bool Form::getIsSigned() const {
    return _is_signed;
}

/**
 * @brief Get the grade required to sign the form
 *
 * @return int The required grade (1-150)
 */
int Form::getGradeToSign() const {
    return _grade_to_sign;
}

/**
 * @brief Get the grade required to execute the form
 *
 * @return int The required grade (1-150)
 */
int Form::getGradeToExecute() const {
    return _grade_to_execute;
}

// === Form Operations ===

/**
 * @brief Attempt to get the form signed by a bureaucrat
 *
 * @param bureaucrat The bureaucrat trying to sign the form
 * @throw GradeTooLowException if the bureaucrat's grade is too low
 */
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _grade_to_sign)
        throw Form::GradeTooLowException();

    _is_signed = true;
}

// === Exception Classes Implementation ===

/**
 * @brief Error message for GradeTooHighException
 *
 * @return const char* The error message
 */
const char *Form::GradeTooHighException::what() const throw() {
    return "Error: Grade is too high! Grade cannot be less than 1.";
}

/**
 * @brief Error message for GradeTooLowException
 *
 * @return const char* The error message
 */
const char *Form::GradeTooLowException::what() const throw() {
    return "Error: Grade is too low! Form requirements cannot be met.";
}

// === Operator Overloads ===

/**
 * @brief Insertion operator overload for Form
 *
 * Outputs the form in a formatted way
 *
 * @param os The output stream
 * @param form The Form to output
 * @return std::ostream& The output stream
 */
std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}