#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>

// Function to test ShrubberyCreationForm
void test_shrubbery_creation() {
    std::cout << "\n\033[1;36m========== TESTING SHRUBBERY CREATION FORM ==========\033[0m" << std::endl;

    try {
        // Create bureaucrats
        Bureaucrat bob("Bob", 145);        // Exactly at sign limit
        Bureaucrat alice("Alice", 137);    // Exactly at execution limit
        Bureaucrat dave("Dave", 150);      // Too low for anything

        // Create the form
        ShrubberyCreationForm garden("garden");
        std::cout << "\n\033[1;33mForm details:\033[0m " << garden << std::endl;

        // Test signing
        std::cout << "\n\033[1;33mTesting signing with inadequate grade:\033[0m" << std::endl;
        dave.signForm(garden);

        std::cout << "\n\033[1;33mTesting signing with adequate grade:\033[0m" << std::endl;
        bob.signForm(garden);

        // Test execution
        std::cout << "\n\033[1;33mTesting execution with inadequate grade:\033[0m" << std::endl;
        dave.executeForm(garden);

        std::cout << "\n\033[1;33mTesting execution with adequate grade:\033[0m" << std::endl;
        alice.executeForm(garden);
    }
    catch (std::exception &e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
}

// Function to test RobotomyRequestForm
void test_robotomy_request() {
    std::cout << "\n\033[1;36m========== TESTING ROBOTOMY REQUEST FORM ==========\033[0m" << std::endl;

    try {
        // Create bureaucrats
        Bureaucrat jack("Jack", 72);   // Exactly at sign limit
        Bureaucrat jill("Jill", 45);   // Exactly at execution limit
        Bureaucrat john("John", 80);   // Too low to sign or execute

        // Create the form
        RobotomyRequestForm robot("R2D2");
        std::cout << "\n\033[1;33mForm details:\033[0m " << robot << std::endl;

        // Test signing
        std::cout << "\n\033[1;33mTesting signing with inadequate grade:\033[0m" << std::endl;
        john.signForm(robot);

        std::cout << "\n\033[1;33mTesting signing with adequate grade:\033[0m" << std::endl;
        jack.signForm(robot);

        // Test execution
        std::cout << "\n\033[1;33mTesting execution with inadequate grade:\033[0m" << std::endl;
        john.executeForm(robot);

        std::cout << "\n\033[1;33mTesting execution with adequate grade:\033[0m" << std::endl;
        jill.executeForm(robot);
    }
    catch (std::exception &e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
}

// Function to test PresidentialPardonForm
void test_presidential_pardon() {
    std::cout << "\n\033[1;36m========== TESTING PRESIDENTIAL PARDON FORM ==========\033[0m" << std::endl;

    try {
        // Create bureaucrats
        Bureaucrat president("President", 5);     // Can sign and execute
        Bureaucrat minister("Minister", 25);      // Can only sign
        Bureaucrat secretary("Secretary", 26);    // Too low for either

        // Create the form
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << "\n\033[1;33mForm details:\033[0m " << pardon << std::endl;

        // Test signing
        std::cout << "\n\033[1;33mTesting signing with inadequate grade:\033[0m" << std::endl;
        secretary.signForm(pardon);

        std::cout << "\n\033[1;33mTesting signing with adequate grade:\033[0m" << std::endl;
        minister.signForm(pardon);

        // Test execution
        std::cout << "\n\033[1;33mTesting execution with inadequate grade:\033[0m" << std::endl;
        minister.executeForm(pardon);

        std::cout << "\n\033[1;33mTesting execution with adequate grade:\033[0m" << std::endl;
        president.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
}

// Function to test the Intern class
void test_intern() {
    std::cout << "\n\033[1;36m========== TESTING INTERN CLASS ==========\033[0m" << std::endl;

    try {
        // Create an intern
        std::cout << "\n\033[1;33mCreating an intern:\033[0m" << std::endl;
        Intern someRandomIntern;

        // Test creating a RobotomyRequestForm
        std::cout << "\n\033[1;33mTesting RobotomyRequestForm creation:\033[0m" << std::endl;
        AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        if (rrf) {
            std::cout << "\033[0;32mCreated form:\033[0m " << *rrf << std::endl;

            // Test the form
            Bureaucrat boss("The Boss", 1);  // Highest possible grade
            boss.signForm(*rrf);
            boss.executeForm(*rrf);

            delete rrf;
        }

        // Test creating a ShrubberyCreationForm
        std::cout << "\n\033[1;33mTesting ShrubberyCreationForm creation:\033[0m" << std::endl;
        AForm *scf = someRandomIntern.makeForm("shrubbery creation", "home");

        if (scf) {
            std::cout << "\033[0;32mCreated form:\033[0m " << *scf << std::endl;

            // Test the form
            Bureaucrat supervisor("Supervisor", 137);  // Just enough to execute
            Bureaucrat clerk("Clerk", 145);            // Just enough to sign

            clerk.signForm(*scf);
            supervisor.executeForm(*scf);

            delete scf;
        }

        // Test creating a PresidentialPardonForm
        std::cout << "\n\033[1;33mTesting PresidentialPardonForm creation:\033[0m" << std::endl;
        AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");

        if (ppf) {
            std::cout << "\033[0;32mCreated form:\033[0m " << *ppf << std::endl;

            // Test the form
            Bureaucrat president("President", 5);  // High enough for everything

            president.signForm(*ppf);
            president.executeForm(*ppf);

            delete ppf;
        }

        // Test error handling with an invalid form type
        std::cout << "\n\033[1;33mTesting with invalid form type:\033[0m" << std::endl;
        AForm *invalid = someRandomIntern.makeForm("coffee making", "Office");

        if (invalid) {  // Should not reach here
            delete invalid;
        }
    }
    catch (std::exception &e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m" << std::endl;
    }
}

int main() {
    std::cout << "\033[1;35m============================================================\033[0m" << std::endl;
    std::cout << "\033[1;35m=           CPP MODULE 05 - EXERCISE 03 TESTS             =\033[0m" << std::endl;
    std::cout << "\033[1;35m============================================================\033[0m" << std::endl;

    // Test each form type
    test_shrubbery_creation();
    test_robotomy_request();
    test_presidential_pardon();

    // Test the Intern class
    test_intern();

    return 0;
}