#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

/**
 * @brief PresidentialPardonForm class for pardoning targets
 *
 * This concrete form informs that the target has been pardoned by
 * Zaphod Beeblebrox when executed.
 * Required grades: sign 25, exec 5
 */
class PresidentialPardonForm : public AForm {
private:
    std::string _target;  // Target for the form's action

public:
    // Orthodox Canonical Form implementation
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
    virtual ~PresidentialPardonForm();

    // Getter for target
    std::string getTarget() const;

    // Implementation of abstract execute method
    virtual void execute(Bureaucrat const & executor) const;
};

#endif