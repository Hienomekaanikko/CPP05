/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/01 15:31:01 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int	main(void) {
	srand(time(NULL));
	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***INTERN TESTS***\n\033[0m" << "\n";

	Intern John;
	AForm* Form1 = nullptr;
	AForm* Form2 = nullptr;
	AForm* Form3 = nullptr;
	AForm* Form4 = nullptr;

	Bureaucrat* SignerSteve = nullptr;

	try {
		SignerSteve = new Bureaucrat("Steve", 130);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}
	if (SignerSteve == nullptr)
		return 1;

	std::cout << "\033[1;32m***Creating a Presidential Pardon Form***\n\033[0m" << "\n";

	try {
		Form1 = John.makeForm("PresidentialPardonForm", "Kitten");
		std::cout << *Form1;
		std::cout << "\033[1;32m*Trying to sign*\n\033[0m";
		try {
			Form1->beSigned(*SignerSteve);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
		std::cout << *Form1;
		std::cout << "\033[1;32m*Trying to excecute*\n\033[0m";
		try {
			SignerSteve->executeForm(*Form1);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	delete Form1;

	std::cout << "\033[1;32m\n***Creating a Robotomy Request Form***\n\033[0m" << "\n";

	try {
		Form2 = John.makeForm("RobotomyRequestForm", "Tauski");
		std::cout << *Form2;
		std::cout << "\033[1;32m*Trying to sign*\n\033[0m";
		try {
			Form2->beSigned(*SignerSteve);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
		std::cout << *Form2;
		std::cout << "\033[1;32m*Trying to excecute*\n\033[0m";
		try {
			SignerSteve->executeForm(*Form2);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	delete Form2;

	std::cout << "\033[1;32m\n***Creating a Shrubbery Request Form***\n\033[0m" << "\n";

	try {
		Form3 = John.makeForm("ShrubberyCreationForm", "out");
		std::cout << *Form3;
		std::cout << "\033[1;32m*Trying to sign*\n\033[0m";
		try {
			Form3->beSigned(*SignerSteve);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
		std::cout << *Form3;
		std::cout << "\033[1;32m*Trying to excecute*\n\033[0m";
		try {
			SignerSteve->executeForm(*Form3);
		} catch (std::exception &e) {
			std::cout << e.what() << "\n";
		}
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	delete Form3;
	std::cout << "\033[1;32m\n***Trying to create nonexisting form***\n\033[0m" << "\n";
	Form4 = John.makeForm("nonexisting_form", "nope");

	delete SignerSteve;

	std::cout << "\033[1;35m\n-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;32m-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;35m-------------------------------------------------------------------------\n\033[0m" << "\n";
}
