#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

/**
 * @brief RobotomyRequestForm class for robotomizing targets
 *
 * This concrete form makes drilling noises and declares that the target has been
 * robotomized successfully 50% of the time when executed.
 * Required grades: sign 72, exec 45
 */
class RobotomyRequestForm : public AForm {
private:
    std::string _target;  // Target for the form's action

public:
    // Orthodox Canonical Form implementation
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
    virtual ~RobotomyRequestForm();

    // Getter for target
    std::string getTarget() const;

    // Implementation of abstract execute method
    virtual void execute(Bureaucrat const & executor) const;
};

#endif