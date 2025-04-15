# CPP Module 05 - Exercise 02: Forms and Bureaucracy

## Overview

This exercise extends the Bureaucrat and Form system by creating an abstract Form class (AForm) and implementing concrete form types with different behaviors when executed.

## Components

### 1. AForm (Abstract Base Class)

- Renamed from Form to AForm, making it abstract with a pure virtual execute method.
- Contains common form properties: name, sign status, and grade requirements.
- Provides base functionality for signing forms and validating grades.

### 2. Concrete Form Types

#### ShrubberyCreationForm

- Required grades: sign 145, exec 137
- Creates a file named `<target>_shrubbery` in the working directory.
- Writes ASCII trees inside the created file.

#### RobotomyRequestForm

- Required grades: sign 72, exec 45
- Makes drilling noises and has a 50% chance of robotomizing the target successfully.

#### PresidentialPardonForm

- Required grades: sign 25, exec 5
- Informs that the target has been pardoned by Zaphod Beeblebrox.

### 3. Bureaucrat Extensions

- Added the `executeForm(AForm const & form)` method to the Bureaucrat class.
- The method attempts to execute a form and displays appropriate messages.

## Exception Handling

- GradeTooHighException: For grades below 1
- GradeTooLowException: For grades above 150 or below form requirements
- FormNotSignedException: For attempts to execute unsigned forms

## Test Cases

The main.cpp file includes comprehensive tests for all form types:

- Testing form creation
- Testing signing with adequate and inadequate grades
- Testing execution with adequate and inadequate grades
- Testing execution of unsigned forms

## Compilation and Usage

```
make        # Compile the program
./forms     # Run the tests
make clean  # Remove object files
make fclean # Remove object files and executable
```

## Concepts Covered

- Abstract classes and pure virtual functions
- Inheritance and polymorphism
- Exception handling
- File I/O operations
- Random number generation
