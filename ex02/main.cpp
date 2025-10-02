/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 16:13:19 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int	main(void) {
	srand(time(NULL));
	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***PRESIDENTIAL PARDON FORM TEST***\n\033[0m" << "\n";
	std::cout << "\033[1;32m***Creating a Presidential Pardon Form***\n\033[0m" << "\n";

	PresidentialPardonForm newForm("Vinnie_The_Pooh");
	std::cout << newForm;

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with too bad grade to execute***\n\033[0m" << "\n";

	Bureaucrat Sari("Sari", 6);
	std::cout << Sari;

	std::cout << "\033[1;32m\n***Trying to sign the presidential pardon***\n\033[0m" << "\n";

	Sari.signForm(newForm);
	std::cout << newForm;

	std::cout << "\033[1;32m\n***Trying to execute the presidential pardon***\n\033[0m" << "\n";

	Sari.executeForm(newForm);

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with good enough grade to sign and execute***\n\033[0m" << "\n";

	Bureaucrat Tarmo("Tarmo", 5);
	std::cout << Tarmo;

	std::cout << "\033[1;32m\n***Trying to sign the presidential pardon again***\n\033[0m" << "\n";

	Tarmo.signForm(newForm);

	std::cout << "\033[1;32m\n***Trying to execute the presidential pardon***\n\033[0m" << "\n";

	Tarmo.executeForm(newForm);

	std::cout << "\033[1;35m\n-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;32m-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;35m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***ROBOTOMY REEQUEST FORM TEST***\n\033[0m" << "\n";
	std::cout << "\033[1;32m***Creating a Robotomoy Request Form***\n\033[0m" << "\n";
	{
	RobotomyRequestForm newForm("Vinnie_The_Pooh");
	std::cout << newForm;

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with too bad grade to execute***\n\033[0m" << "\n";

	Bureaucrat Jari("Jari", 72);
	std::cout << Jari;

	std::cout << "\033[1;32m\n***Trying to sign the robotomy request***\n\033[0m" << "\n";

	Jari.signForm(newForm);
	std::cout << newForm;

	std::cout << "\033[1;32m\n***Trying to execute the robotomy request***\n\033[0m" << "\n";

	Jari.executeForm(newForm);

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with good enough grade to sign and execute***\n\033[0m" << "\n";

	Bureaucrat Tuulikki("Tuulikki", 5);
	std::cout << Tuulikki;

	std::cout << "\033[1;32m\n***Trying to sign the robotomy request again***\n\033[0m" << "\n";

	Tuulikki.signForm(newForm);

	std::cout << "\033[1;32m\n***Trying to execute the robotomy request 10 times to see the 50 percent hitrate***\n\033[0m" << "\n";

	for (int i = 0; i < 10; i++)
		Tuulikki.executeForm(newForm);
	}

	std::cout << "\033[1;35m\n-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;32m-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;35m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***Creating a Shrubbery Request Form***\n\033[0m" << "\n";
	{
	ShrubberyCreationForm newForm("out");
	std::cout << newForm;

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with too bad grade to execute***\n\033[0m" << "\n";

	Bureaucrat Tero("Tero", 6);
	std::cout << Tero;

	std::cout << "\033[1;32m\n***Trying to sign the shrubbery request form***\n\033[0m" << "\n";

	Tero.signForm(newForm);
	std::cout << newForm;

	std::cout << "\033[1;32m\n***Trying to execute the shrubbery request form***\n\033[0m" << "\n";

	Tero.executeForm(newForm);

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with good enough grade to sign and execute***\n\033[0m" << "\n";

	Bureaucrat Aune("Aune", 4);
	std::cout << Aune;

	std::cout << "\033[1;32m\n***Trying to sign the shrubbery request form again***\n\033[0m" << "\n";

	Aune.signForm(newForm);

	std::cout << "\033[1;32m\n***Trying to execute the shrubbery request***\n\033[0m" << "\n";

	Aune.executeForm(newForm);
	std::cout << "\033[1;32m\n-------------------------------DONE--------------------------------------\n\033[0m" << "\n";
	}
}
