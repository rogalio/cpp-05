# C++ Module 05: Repetition and Exceptions

![C++](https://img.shields.io/badge/language-C++-blue.svg)
![C++98](https://img.shields.io/badge/standard-C++98-orange.svg)
![42](https://img.shields.io/badge/school-42-green.svg)

## Overview

This module focuses on exception handling in C++98, implementing a bureaucratic nightmare simulation. The project develops various classes representing bureaucrats, forms, and interns, with careful exception handling to manage error scenarios effectively.

## Key Concepts Explored

- **Exception Handling**: Using `try/catch` blocks to handle exceptional conditions
- **Inheritance**: Creating base classes and derived concrete implementations
- **Polymorphism**: Using virtual functions to execute different behaviors
- **Abstract Classes**: Creating abstract base classes with pure virtual functions
- **Function Pointers**: Implementing factory pattern with function pointers
- **File Operations**: Reading from and writing to files
- **Memory Management**: Proper allocation and deallocation of resources

## Project Structure

The project is divided into four exercises, each building upon the previous:

### Exercise 00: Bureaucrat

Implementation of a basic `Bureaucrat` class with proper exception handling:

- Constant name attribute
- Grade attribute (1-150 range)
- Custom exceptions for invalid grades
- Increment/decrement functionality with exception safety

### Exercise 01: Form

Introduction of a `Form` class that can be signed by bureaucrats:

- Constant name attribute
- Signing status
- Grade requirements for signing and execution
- Exception handling for grade violations
- Interaction with the `Bureaucrat` class for signing actions

### Exercise 02: Concrete Forms

Expansion with an abstract form base class and three concrete implementations:

- `AForm`: Abstract base class derived from `Form`
- `ShrubberyCreationForm`: Creates a file with ASCII trees
- `RobotomyRequestForm`: Attempts to robotomize targets
- `PresidentialPardonForm`: Grants presidential pardons
- Polymorphic execution based on form type

### Exercise 03: Intern

Addition of an `Intern` class to automate form creation:

- Implementation of a factory pattern using function pointers
- Dynamic form creation based on form name strings
- Memory management for dynamically allocated forms
- Exception handling for unknown form types

## Design Patterns Used

- **Orthodox Canonical Form**: All classes follow the OCF with proper constructors, destructors, and operators
- **Factory Pattern**: The `Intern` class implements a factory to create concrete form instances
- **Command Pattern**: Forms represent commands to be executed when conditions are met
- **Exception Pattern**: Custom exception classes for error conditions

## Key Learnings

- **Exception Safety**: Maintaining program stability during exceptional conditions
- **Class Design**: Following OOP principles for extensible and maintainable code
- **Resource Management**: Proper allocation/deallocation of resources
- **Type Safety**: Using C++'s type system to prevent errors
- **Polymorphism**: Utilizing inheritance and virtual functions for dynamic behavior
- **Code Organization**: Structuring code for clarity and separation of concerns

## Usage

Each exercise contains its own Makefile and test program. To build and run:

```bash
# For any exercise (ex00-ex03)
cd ex03
make
./intern
```

## Exception Handling

This module thoroughly explores C++ exception handling:

1. **Custom Exceptions**: Each class defines its own exception types
2. **Exception Hierarchies**: Exceptions inherit from `std::exception`
3. **Error Messages**: Custom `what()` methods for informative error messages
4. **Exception Propagation**: Proper handling of exceptions across class boundaries
5. **Resource Cleanup**: Ensuring proper cleanup during exceptional conditions

## Form Execution Process

The execution of a form follows a sequence of validations:

1. Check if the bureaucrat has high enough grade
2. Verify the form is signed
3. Perform the specific action based on form type
4. Handle any exceptions that may occur during execution

## Conclusion

This module provides a comprehensive introduction to exception handling in C++, demonstrating how to design robust error handling mechanisms and implement class hierarchies using polymorphism. The bureaucratic simulation serves as an excellent practical example of these concepts.

---

**Made with ❤️ for 42**
