#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

int main() {
    std::cout << "---------------------- Testing ShrubberyCreationForm ----------------------" << std::endl;
    try {
        // Create bureaucrats with different grades
        Bureaucrat bob("Bob", 145);  // Just enough to sign
        Bureaucrat alice("Alice", 137);  // Just enough to execute
        Bureaucrat dave("Dave", 150);  // Too low to sign or execute

        // Create a ShrubberyCreationForm
        ShrubberyCreationForm garden("garden");

        std::cout << "\nForm details: " << garden << std::endl;

        // Test signing with inadequate grade
        std::cout << "\nTesting signing with inadequate grade:" << std::endl;
        dave.signForm(garden);

        // Test signing with adequate grade
        std::cout << "\nTesting signing with adequate grade:" << std::endl;
        bob.signForm(garden);

        // Test executing unsigned form (shouldn't happen now, as it's signed)

        // Test executing with inadequate grade
        std::cout << "\nTesting executing with inadequate grade:" << std::endl;
        dave.executeForm(garden);

        // Test executing with adequate grade
        std::cout << "\nTesting executing with adequate grade:" << std::endl;
        alice.executeForm(garden);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n---------------------- Testing RobotomyRequestForm ----------------------" << std::endl;
    try {
        // Create bureaucrats with different grades
        Bureaucrat jack("Jack", 72);   // Just enough to sign
        Bureaucrat jill("Jill", 45);   // Just enough to execute
        Bureaucrat john("John", 80);   // Too low to sign or execute

        // Create a RobotomyRequestForm
        RobotomyRequestForm robot("R2D2");

        std::cout << "\nForm details: " << robot << std::endl;

        // Test signing with inadequate grade
        std::cout << "\nTesting signing with inadequate grade:" << std::endl;
        john.signForm(robot);

        // Test signing with adequate grade
        std::cout << "\nTesting signing with adequate grade:" << std::endl;
        jack.signForm(robot);

        // Test executing with inadequate grade
        std::cout << "\nTesting executing with inadequate grade:" << std::endl;
        john.executeForm(robot);

        // Test executing with adequate grade (should work ~50% of the time)
        std::cout << "\nTesting executing with adequate grade:" << std::endl;
        jill.executeForm(robot);

        // Test executing again to demonstrate randomness
        std::cout << "\nTesting executing again to demonstrate randomness:" << std::endl;
        jill.executeForm(robot);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n---------------------- Testing PresidentialPardonForm ----------------------" << std::endl;
    try {
        // Create bureaucrats with different grades
        Bureaucrat president("President", 5);   // High enough for everything
        Bureaucrat minister("Minister", 25);    // Can sign but can't execute
        Bureaucrat secretary("Secretary", 26);  // Too low to sign or execute

        // Create a PresidentialPardonForm
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\nForm details: " << pardon << std::endl;

        // Test signing with inadequate grade
        std::cout << "\nTesting signing with inadequate grade:" << std::endl;
        secretary.signForm(pardon);

        // Test signing with adequate grade
        std::cout << "\nTesting signing with adequate grade:" << std::endl;
        minister.signForm(pardon);

        // Test executing with inadequate grade
        std::cout << "\nTesting executing with inadequate grade:" << std::endl;
        minister.executeForm(pardon);

        // Test executing with adequate grade
        std::cout << "\nTesting executing with adequate grade:" << std::endl;
        president.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\n---------------------- Testing Unsigned Form Execution ----------------------" << std::endl;
    try {
        Bureaucrat chief("Chief", 1);  // Highest possible grade

        // Create a form without signing it
        PresidentialPardonForm urgent_pardon("Trillian");

        std::cout << "\nForm details: " << urgent_pardon << std::endl;

        // Try to execute an unsigned form (should fail)
        std::cout << "\nTrying to execute unsigned form:" << std::endl;
        chief.executeForm(urgent_pardon);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}