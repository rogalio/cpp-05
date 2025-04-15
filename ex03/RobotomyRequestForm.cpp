#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

/**
 * Default constructor
 */
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), _target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

/**
 * Parameterized constructor
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

/**
 * Copy constructor
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

/**
 * Assignment operator
 */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;

    if (this != &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

/**
 * Destructor
 */
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/**
 * Get the target for the form
 */
std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

/**
 * Execute the form's action - attempt to robotomize the target
 */
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    // Check if the form is signed and the executor has sufficient grade
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }

    // Make drilling noises
    std::cout << "* DRILLING NOISES * Brrrrrr...Zzzzzz...Whirrrr...Krrrrrrr! *" << std::endl;

    // Seed random number generator with current time if not seeded yet
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }

    // 50% chance of successful robotomization
    if (std::rand() % 2) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomization of " << this->_target << " failed." << std::endl;
    }
}