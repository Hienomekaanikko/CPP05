/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:30:18 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/26 15:47:42 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void) {
	srand(time(NULL));

	std::cout << "\033[1;32m\nCreate invalid form with the Intern:\n\033[0m" << "\n";
	Intern Teuvo;
	AForm *Form1 = nullptr;
	AForm *Form2 = nullptr;
	AForm *Form3 = nullptr;
	AForm *Form4 = nullptr;

	try {
		Form1 = Teuvo.makeForm("invalidName", "NoNo");
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\033[1;32m\n--------------------------------------------------------------------------------------" << "\n";

	std::cout << "\033[1;32m\nCreating all valid forms with the Intern:\n\033[0m" << "\n";

	try {
		Form2 = Teuvo.makeForm("PresidentialPardonForm", "WoopWoop");
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	try {
		Form3 = Teuvo.makeForm("RobotomyRequestForm", "WiipWiip");
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	try {
		Form4 = Teuvo.makeForm("ShrubberyCreationForm", "ZibidyDipiDoo");
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\033[1;32m\n--------------------------------------------------------------------------------------" << "\n";

	Bureaucrat* Kalevi = nullptr;
	std::cout << "\033[1;32m\nCreating Bureaucrat Kalevi to sign the forms:\n\033[0m" << "\n";
	try {
		Kalevi = new Bureaucrat("Kalevi", 140);
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	if (Kalevi)
	{
		try {
			if (Form2) Form2->beSigned(*Kalevi);
			if (Form3) Form3->beSigned(*Kalevi);
			if (Form4) Form4->beSigned(*Kalevi);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << "\n";
		}
		if (Form2) Kalevi->executeForm(*Form2);
		if (Form3) Kalevi->executeForm(*Form3);
		if (Form4) Kalevi->executeForm(*Form4);
	}
	delete Kalevi;

}
