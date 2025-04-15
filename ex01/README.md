# C++ Module 05 - Exercise 01: Forms

## Overview

This exercise builds on the previous one by introducing a `Form` class that interacts with `Bureaucrat`. The form has specific grade requirements for signing and execution, and can only be signed by bureaucrats of sufficient rank.

## Key Concepts

### 1. Class Interaction

- Classes can interact with each other through method calls
- Using forward declarations to handle circular dependencies
- Proper exception handling between interacting classes

### 2. Circular Dependencies

The solution uses forward declarations to resolve circular dependencies:

```cpp
// In Bureaucrat.hpp
class Form;  // Forward declaration

// In Form.hpp
class Bureaucrat;  // Forward declaration

// Include order matters
#include "Bureaucrat.hpp"  // At the end of Form.hpp
#include "Form.hpp"        // At the end of Bureaucrat.hpp
```

### 3. Exception Propagation

- Exceptions can be thrown by one class and caught by another
- The `signForm` method catches exceptions from `beSigned` to prevent program termination
- This shows how to properly handle errors across multiple objects

### 4. Const Member Variables

- Form has multiple const attributes that cannot be changed after initialization
- Assignment operator must handle const members properly
- Only non-const attributes can be modified in the assignment operator

## Implementation Details

### Form Class

```cpp
class Form {
private:
    const std::string _name;         // Form's name
    bool _is_signed;                 // Whether the form is signed
    const int _grade_to_sign;        // Required grade to sign
    const int _grade_to_execute;     // Required grade to execute

public:
    // Orthodox Canonical Form methods
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

    // Exception classes
    class GradeTooHighException : public std::exception { /*...*/ };
    class GradeTooLowException : public std::exception { /*...*/ };
};
```

### Bureaucrat's signForm Method

```cpp
void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
```

### Form's beSigned Method

```cpp
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _grade_to_sign)
        throw Form::GradeTooLowException();

    _is_signed = true;
}
```

## Testing

The test program demonstrates:

1. Creating forms with valid and invalid grades
2. Signing forms successfully when bureaucrat grade is sufficient
3. Handling failures when bureaucrat grade is too low
4. Direct use of `beSigned` with exception handling
5. Testing the Orthodox Canonical Form functionality

## Compilation and Execution

```bash
make        # Compile the program
./form      # Run the tests
```

## Key Takeaways

1. Classes can interact through methods that take other objects as parameters
2. Forward declarations help resolve circular dependencies
3. Exception handling can span multiple classes and methods
4. The `operator=` must handle const members appropriately (can't modify them)
