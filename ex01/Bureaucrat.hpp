#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

// Forward declaration for Form
class Form;

/**
 * @brief Bureaucrat class representing a governmental employee with a name and grade
 *
 * This class implements a basic bureaucrat with a constant name and a grade
 * ranging from 1 (highest) to 150 (lowest). It includes validation to ensure
 * grades remain within the acceptable range.
 */
class Bureaucrat {
private:
    const std::string _name;    // Bureaucrat's name (constant)
    int _grade;                 // Bureaucrat's grade (1 to 150)

public:
    // Orthodox Canonical Form implementation
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade modification methods
    void incrementGrade();  // Increases the grade (decreases the grade value)
    void decrementGrade();  // Decreases the grade (increases the grade value)

    // Form interaction methods
    void signForm(Form &form);

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

// Insertion operator overload for Bureaucrat
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

// Include Form header after Bureaucrat is fully declared
#include "Form.hpp"

#endif