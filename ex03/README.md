# CPP Module 05 - Exercise 03: Interns and Form Creation

## Overview

This exercise extends the bureaucracy system by adding an Intern class that can dynamically create different types of forms based on form name strings.

## Components

### 1. Intern Class

- Represents an unnamed, ungraded intern with no unique characteristics
- Implements the `makeForm(string formName, string target)` method that:
  - Takes a form name and target as parameters
  - Returns a pointer to the appropriate form type
  - Prints a message indicating the form creation
  - Handles unknown form types with an exception

### 2. Form Types (From Exercise 02)

- **ShrubberyCreationForm**: Creates a file with ASCII trees
- **RobotomyRequestForm**: Attempts to robotomize the target
- **PresidentialPardonForm**: Pardons the target

### 3. Form Creation Pattern

The Intern class implements a form of the Factory Pattern, where:

- Form creation is delegated to specialized methods
- Form names are mapped to creation methods using a static array
- The implementation avoids excessive if/else statements

## Exception Handling

- **UnknownFormException**: Thrown when an unknown form type is requested
- All previous exceptions from Exercise 02 are still applicable

## Test Cases

The main.cpp file includes comprehensive tests for the Intern class:

- Creating each type of form (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm)
- Testing that created forms work as expected
- Handling error cases with unknown form types

## Compilation and Usage

```
make        # Compile the program
./intern    # Run the tests
make clean  # Remove object files
make fclean # Remove object files and executable
```

## Concepts Covered

- Factory Pattern for object creation
- Function pointers and dynamic dispatch
- Memory management (allocating and deallocating dynamically created forms)
- Exception handling
- Case-insensitive string comparison
