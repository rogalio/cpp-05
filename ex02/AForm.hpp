#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

// Forward declaration to avoid circular dependency
class Bureaucrat;

/**
 * @brief Abstract Form class representing an official document that can be signed and executed
 *
 * This class implements a form with a constant name, a sign status, and two constant
 * grade requirements: one for signing and one for executing. Grade validation ensures
 * all grades remain within the acceptable range (1-150).
 * This is an abstract class that must be inherited by concrete form types.
 */
class AForm {
private:
    const std::string _name;         // Form's name (constant)
    bool _is_signed;                 // Whether the form is signed
    const int _grade_to_sign;        // Required grade to sign (1-150)
    const int _grade_to_execute;     // Required grade to execute (1-150)

public:
    // Orthodox Canonical Form implementation
    AForm();
    AForm(const std::string &name, int grade_to_sign, int grade_to_execute);
    AForm(const AForm &src);
    AForm &operator=(const AForm &rhs);
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Form operations
    void beSigned(const Bureaucrat &bureaucrat);

    // Pure virtual execute method that makes this class abstract
    virtual void execute(Bureaucrat const & executor) const = 0;

    // Exception classes for validation
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

// Insertion operator overload for AForm
std::ostream &operator<<(std::ostream &os, const AForm &form);

// Include Bureaucrat header after AForm is fully declared to resolve circular dependency
#include "Bureaucrat.hpp"

#endif