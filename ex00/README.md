# C++ Module 05 - Exercise 00: Bureaucrat

## Overview

This exercise introduces exception handling in C++, implemented through a `Bureaucrat` class that manages employees with names and grades. The grade range is strictly enforced (1-150), with 1 being the highest grade and 150 being the lowest.

## Key Concepts

### 1. Exception Handling

- C++ uses `try`, `catch`, and `throw` keywords to handle exceptions
- Custom exception classes inherit from `std::exception`
- The `what()` method returns an error message

```cpp
try {
    // Code that might throw an exception
    Bureaucrat highRanked("Boss", 0); // Invalid grade!
} catch (std::exception &e) {
    // Handle the exception
    std::cout << "Error: " << e.what() << std::endl;
}
```

### 2. Orthodox Canonical Form

All classes in C++ should follow the Orthodox Canonical Form, which includes:

- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

### 3. Const Members

- The `Bureaucrat` class has a constant name member (`const std::string _name`)
- Constant members can only be initialized in the initializer list, not in the constructor body
- They cannot be modified after initialization

### 4. Operator Overloading

- The insertion operator (`<<`) is overloaded to provide custom output
- This allows printing objects with `std::cout << obj`

## Implementation Details

### Class Structure

```cpp
class Bureaucrat {
private:
    const std::string _name;    // Cannot be changed after creation
    int _grade;                 // 1 (highest) to 150 (lowest)

public:
    // Orthodox Canonical Form methods
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &rhs);
    ~Bureaucrat();

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Grade modification
    void incrementGrade();  // Increases the grade (decreases the grade value)
    void decrementGrade();  // Decreases the grade (increases the grade value)

    // Exception classes
    class GradeTooHighException : public std::exception { /*...*/ };
    class GradeTooLowException : public std::exception { /*...*/ };
};
```

### Grade Validation

- When creating or modifying a bureaucrat, grade limits are strictly enforced
- If grade < 1: throw `GradeTooHighException`
- If grade > 150: throw `GradeTooLowException`

### Testing

The test program demonstrates:

1. Creating valid and invalid bureaucrats
2. Getting and modifying grades
3. Handling exceptions at boundaries
4. Orthodox Canonical Form functionality

## Compilation and Execution

```bash
make        # Compile the program
./bureaucrat # Run the tests
```

## Key Takeaways

1. Exception handling provides a clean way to manage errors
2. Custom exception classes should inherit from `std::exception`
3. Constant class members must be initialized in the initializer list
4. The Orthodox Canonical Form ensures proper class behavior
