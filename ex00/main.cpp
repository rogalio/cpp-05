#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

// ANSI color codes for more readable terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

/**
 * @brief Displays a section header with a title
 *
 * @param title The title of the test section
 */
void displayHeader(const std::string &title) {
    std::cout << std::endl << MAGENTA << "=== " << title << " ===" << RESET << std::endl;
}

/**
 * @brief Displays a test description
 *
 * @param description The description of the test
 */
void displayTest(const std::string &description) {
    std::cout << CYAN << ">> " << description << RESET << std::endl;
}

int main() {
    std::cout << YELLOW << "BUREAUCRAT TEST PROGRAM" << RESET << std::endl;
    std::cout << "This program demonstrates the functionality of the Bureaucrat class." << std::endl;

    // Test 1: Basic constructor and operator<< overload
    displayHeader("CONSTRUCTOR TESTS");

    displayTest("Creating a valid bureaucrat (Bob, grade 42)");
    try {
        Bureaucrat bob("Bob", 42);
        std::cout << GREEN << "✓ Successfully created: " << bob << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "❌ Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // Test 2: Grade too high exception (grade < 1)
    displayTest("Creating a bureaucrat with grade 0 (too high)");
    try {
        Bureaucrat tooHigh("SuperBoss", 0);
        std::cout << RED << "❌ Test failed: No exception thrown!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << RESET << std::endl;
    }

    // Test 3: Grade too low exception (grade > 150)
    displayTest("Creating a bureaucrat with grade 151 (too low)");
    try {
        Bureaucrat tooLow("Intern", 151);
        std::cout << RED << "❌ Test failed: No exception thrown!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << RESET << std::endl;
    }

    // Test 4: Testing getters
    displayHeader("GETTER TESTS");

    Bureaucrat alice("Alice", 50);
    displayTest("Testing getName() and getGrade()");
    std::cout << "Name: " << alice.getName() << std::endl;
    std::cout << "Grade: " << alice.getGrade() << std::endl;

    // Test 5: Testing increment/decrement
    displayHeader("GRADE MODIFICATION TESTS");

    displayTest("Testing incrementGrade()");
    std::cout << "Before: " << alice << std::endl;
    alice.incrementGrade();
    std::cout << "After increment: " << alice << std::endl;

    displayTest("Testing decrementGrade()");
    std::cout << "Before: " << alice << std::endl;
    alice.decrementGrade();
    std::cout << "After decrement: " << alice << std::endl;

    // Test 6: Testing increment at highest grade
    displayHeader("BOUNDARY TESTS");

    displayTest("Incrementing a grade 1 bureaucrat (should throw GradeTooHighException)");
    try {
        Bureaucrat ceo("CEO", 1);
        std::cout << "Before: " << ceo << std::endl;
        ceo.incrementGrade();
        std::cout << RED << "❌ Test failed: No exception thrown!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << RESET << std::endl;
    }

    // Test 7: Testing decrement at lowest grade
    displayTest("Decrementing a grade 150 bureaucrat (should throw GradeTooLowException)");
    try {
        Bureaucrat intern("Intern", 150);
        std::cout << "Before: " << intern << std::endl;
        intern.decrementGrade();
        std::cout << RED << "❌ Test failed: No exception thrown!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << RESET << std::endl;
    }

    // Test 8: Testing copy constructor and assignment operator
    displayHeader("CANONICAL FORM TESTS");

    displayTest("Testing copy constructor");
    Bureaucrat original("Original", 42);
    Bureaucrat copy(original);
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;

    displayTest("Testing assignment operator");
    Bureaucrat assigned;
    assigned = original;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Assigned: " << assigned << std::endl;

    return 0;
}