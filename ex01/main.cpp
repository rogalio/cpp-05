#include "Bureaucrat.hpp"
#include "Form.hpp"
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
    std::cout << YELLOW << "FORM AND BUREAUCRAT TEST PROGRAM" << RESET << std::endl;
    std::cout << "This program demonstrates the interaction between Bureaucrat and Form classes." << std::endl;

    // Test 1: Form construction
    displayHeader("FORM CONSTRUCTION TESTS");

    displayTest("Creating a valid form (Tax Form, sign grade 50, exec grade 25)");
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << GREEN << "✓ Successfully created: " << taxForm << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "❌ Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // Test 2: Form with invalid grades
    displayTest("Creating a form with too high sign grade (0)");
    try {
        Form invalidForm("Invalid Form", 0, 25);
        std::cout << RED << "❌ Test failed: No exception thrown!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << RESET << std::endl;
    }

    displayTest("Creating a form with too low exec grade (151)");
    try {
        Form invalidForm("Invalid Form", 50, 151);
        std::cout << RED << "❌ Test failed: No exception thrown!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << GREEN << "✓ Exception caught: " << e.what() << RESET << std::endl;
    }

    // Test 3: Form signing - successful case
    displayHeader("FORM SIGNING TESTS - SUCCESSFUL");

    displayTest("High-ranked bureaucrat signing a form (Grade 10 signs form requiring grade 50)");
    try {
        Bureaucrat director("Director", 10);
        Form contract("Contract", 50, 25);

        std::cout << "Bureaucrat: " << director << std::endl;
        std::cout << "Form Before: " << contract << std::endl;

        director.signForm(contract);

        std::cout << "Form After: " << contract << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "❌ Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // Test 4: Form signing - failure case (bureaucrat grade too low)
    displayHeader("FORM SIGNING TESTS - FAILURE");

    displayTest("Low-ranked bureaucrat trying to sign a form (Grade 100 tries to sign form requiring grade 50)");
    try {
        Bureaucrat clerk("Clerk", 100);
        Form importantContract("Important Contract", 50, 25);

        std::cout << "Bureaucrat: " << clerk << std::endl;
        std::cout << "Form Before: " << importantContract << std::endl;

        clerk.signForm(importantContract);

        std::cout << "Form After: " << importantContract << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "❌ Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // Test 5: Direct beSigned method - with exception handling
    displayHeader("DIRECT beSigned METHOD TEST");

    displayTest("Using Form::beSigned directly with try-catch");
    try {
        Bureaucrat intern("Intern", 140);
        Form executiveOrder("Executive Order", 5, 5);

        std::cout << "Bureaucrat: " << intern << std::endl;
        std::cout << "Form: " << executiveOrder << std::endl;

        try {
            std::cout << "Attempting to sign the form directly..." << std::endl;
            executiveOrder.beSigned(intern);
            std::cout << GREEN << "✓ Form signed successfully!" << RESET << std::endl;
        } catch (Form::GradeTooLowException &e) {
            std::cout << YELLOW << "⚠ Couldn't sign the form: " << e.what() << RESET << std::endl;
        }

        std::cout << "Form after attempt: " << executiveOrder << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "❌ Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // Test 6: Testing Orthodox Canonical Form
    displayHeader("ORTHODOX CANONICAL FORM TESTS");

    displayTest("Copy constructor test");
    try {
        Form original("Original Form", 30, 15);
        Form copy(original);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;

        // Sign the original and show that copy remains unchanged
        Bureaucrat boss("Boss", 1);
        boss.signForm(original);

        std::cout << "After signing original:" << std::endl;
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "❌ Unexpected exception: " << e.what() << RESET << std::endl;
    }

    displayTest("Assignment operator test");
    try {
        Form formA("Form A", 20, 10);
        Form formB("Form B", 40, 30);

        std::cout << "Before assignment:" << std::endl;
        std::cout << "Form A: " << formA << std::endl;
        std::cout << "Form B: " << formB << std::endl;

        // Sign form A
        Bureaucrat manager("Manager", 10);
        manager.signForm(formA);

        // Assign A to B
        formB = formA;

        std::cout << "After assignment:" << std::endl;
        std::cout << "Form A: " << formA << std::endl;
        std::cout << "Form B: " << formB << std::endl;
        std::cout << YELLOW << "Note: Names and grades don't change due to const attributes!" << RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << "❌ Unexpected exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}