/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:30:18 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/26 14:19:01 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	srand(time(NULL));

	Bureaucrat* Jorma = nullptr;
	std::cout << "\033[1;32m\nCreating Bureaucrat Jorma and form Roboform (Roboform min signing grade 72, min execution grade 45):\n\033[0m" << "\n";

	try {
		Jorma = new Bureaucrat("Jorma", 15);
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	RobotomyRequestForm RoboForm("Target");
	if (Jorma)
	{
		try {
			RoboForm.beSigned(*Jorma);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << "\n";
		}
		Jorma->executeForm(RoboForm);
	}

	delete Jorma;
	std::cout << "\033[1;32m\n--------------------------------------------------------------------------------------" << "\n";

	Bureaucrat* Seppo = nullptr;
	std::cout << "\033[1;32m\nCreating Bureaucrat Seppo and form PresidentialPardon (PresidentialPardon min signing grade 25, min execution grade 5):\n\033[0m" << "\n";

	try {
		Seppo = new Bureaucrat("Seppo", 5);
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	PresidentialPardonForm PresidentialPardon("Puppy 🐕");
	if (Seppo)
	{
		try {
			PresidentialPardon.beSigned(*Seppo);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << "\n";
		}
		Seppo->executeForm(PresidentialPardon);
	}

	delete Seppo;
	std::cout << "\033[1;32m\n--------------------------------------------------------------------------------------" << "\n";

	Bureaucrat* Kalevi = nullptr;
	std::cout << "\033[1;32m\nCreating Bureaucrat Kalevi and form CreateShrubbery (CreateShrubbery min signing grade 145, min execution grade 137):\n\033[0m" << "\n";
	try {
		Kalevi = new Bureaucrat("Kalevi", 100);
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	ShrubberyCreationForm CreateShrubbery("ShrubbydyShrub");
	if (Kalevi)
	{
		try {
			CreateShrubbery.beSigned(*Kalevi);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << "\n";
		}
		Kalevi->executeForm(CreateShrubbery);
	}
	delete Kalevi;
}
