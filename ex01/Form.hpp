#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

// Forward declaration to avoid circular dependency
class Bureaucrat;

/**
 * @brief Form class representing an official document that can be signed by bureaucrats
 *
 * This class implements a form with a constant name, a sign status, and two constant
 * grade requirements: one for signing and one for executing. Grade validation ensures
 * all grades remain within the acceptable range (1-150).
 */
class Form {
private:
    const std::string _name;         // Form's name (constant)
    bool _is_signed;                 // Whether the form is signed
    const int _grade_to_sign;        // Required grade to sign (1-150)
    const int _grade_to_execute;     // Required grade to execute (1-150)

public:
    // Orthodox Canonical Form implementation
    Form();
    Form(const std::string &name, int grade_to_sign, int grade_to_execute);
    Form(const Form &src);
    Form &operator=(const Form &rhs);
    ~Form();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Form operations
    void beSigned(const Bureaucrat &bureaucrat);

    // Exception classes for grade validation
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

// Insertion operator overload for Form
std::ostream &operator<<(std::ostream &os, const Form &form);

// Include Bureaucrat header after Form is fully declared to resolve circular dependency
#include "Bureaucrat.hpp"

#endif