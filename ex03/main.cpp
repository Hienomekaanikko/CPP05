/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 15:20:07 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int	main(void) {
	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***INTERN TRIES RANDOM VALUES FOR PARDON FORM***\n\033[0m" << "\n";

	Intern Jill;
	try {
		AForm* newForm = Jill.makeForm("blahblah", "yupyup");
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot create form because " << e.what() << std::endl;
	}

	std::cout << "\033[1;32m\n***INTERN CREATES PRESIDENTIAL PARDON FORM**\n\033[0m" << "\n";
	std::cout << "\033[1;32m***Creating a Presidential Pardon Form***\n\033[0m" << "\n";
	Intern Bill;
	{

	AForm* newForm = Bill.makeForm("presidential pardon", "Vinnie_The_Pooh");

	std::cout << *newForm;

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with too bad grade to execute***\n\033[0m" << "\n";

	Bureaucrat Sari("Sari", 6);
	std::cout << Sari;

	std::cout << "\033[1;32m\n***Trying to sign the presidential pardon***\n\033[0m" << "\n";

	Sari.signForm(*newForm);
	std::cout << *newForm;

	std::cout << "\033[1;32m\n***Trying to execute the presidential pardon***\n\033[0m" << "\n";

	Sari.executeForm(*newForm);

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with good enough grade to sign and execute***\n\033[0m" << "\n";

	Bureaucrat Tarmo("Tarmo", 5);
	std::cout << Tarmo;

	std::cout << "\033[1;32m\n***Trying to sign the presidential pardon again***\n\033[0m" << "\n";

	Tarmo.signForm(*newForm);

	std::cout << "\033[1;32m\n***Trying to execute the presidential pardon***\n\033[0m" << "\n";

	Tarmo.executeForm(*newForm);
	}
	std::cout << "\033[1;35m\n-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;32m-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;35m-------------------------------------------------------------------------\n\033[0m" << "\n";
	{
	std::cout << "\033[1;32m***INTERN CREATES ROBOTOMY REQUEST FORM***\n\033[0m" << "\n";
	std::cout << "\033[1;32m***Creating a Robotomoy Request Form***\n\033[0m" << "\n";

	AForm* newForm = Bill.makeForm("robotomy request", "Vinnie_The_Pooh");
	std::cout << *newForm;

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with too bad grade to execute***\n\033[0m" << "\n";

	Bureaucrat Jari("Jari", 72);
	std::cout << Jari;

	std::cout << "\033[1;32m\n***Trying to sign the robotomy request***\n\033[0m" << "\n";

	Jari.signForm(*newForm);
	std::cout << *newForm;

	std::cout << "\033[1;32m\n***Trying to execute the robotomy request***\n\033[0m" << "\n";

	Jari.executeForm(*newForm);

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with good enough grade to sign and execute***\n\033[0m" << "\n";

	Bureaucrat Tuulikki("Tuulikki", 5);
	std::cout << Tuulikki;

	std::cout << "\033[1;32m\n***Trying to sign the robotomy request again***\n\033[0m" << "\n";

	Tuulikki.signForm(*newForm);

	std::cout << "\033[1;32m\n***Trying to execute the robotomy request 10 times to see the 50 percent hitrate***\n\033[0m" << "\n";

	for (int i = 0; i < 10; i++) {
		Tuulikki.executeForm(*newForm);
	}
	}
	std::cout << "\033[1;35m\n-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;32m-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;35m-------------------------------------------------------------------------\n\033[0m" << "\n";
	{
	std::cout << "\033[1;32m***INTERN CREATES SHRUBBERY CREATION FORM***\n\033[0m" << "\n";
	std::cout << "\033[1;32m***Creating a Shrubbery Creation Form***\n\033[0m" << "\n";

	AForm* newForm = Bill.makeForm("shrubbery creation", "out");
	std::cout << *newForm;

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with too bad grade to execute***\n\033[0m" << "\n";

	Bureaucrat Tero("Tero", 6);
	std::cout << Tero;

	std::cout << "\033[1;32m\n***Trying to sign the shrubbery creation form***\n\033[0m" << "\n";

	Tero.signForm(*newForm);
	std::cout << *newForm;

	std::cout << "\033[1;32m\n***Trying to execute the shrubbery creation form***\n\033[0m" << "\n";

	Tero.executeForm(*newForm);

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with good enough grade to sign and execute***\n\033[0m" << "\n";

	Bureaucrat Aune("Aune", 4);
	std::cout << Aune;

	std::cout << "\033[1;32m\n***Trying to sign the shrubbery creation form again***\n\033[0m" << "\n";

	Aune.signForm(*newForm);

	std::cout << "\033[1;32m\n***Trying to execute the shrubbery creation***\n\033[0m" << "\n";

	Aune.executeForm(*newForm);
	std::cout << "\033[1;32m\n-------------------------------------------------------------------------\n\033[0m" << "\n";
	}
}
