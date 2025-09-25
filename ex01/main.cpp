/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:30:18 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/25 12:26:04 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	std::cout << "\033[1;32mTrying grade more than 150 (too low):\n\033[0m" << "\n";
	try {
		Bureaucrat Seppo("Seppo", 500);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}
	std::cout << "\n";

	std::cout << "\033[1;32mTrying grade less than 1 (too high):\n\033[0m" << "\n";
	try {
		Bureaucrat Teppo("Teppo", 0);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;32m\nTrying appropriate grade 150, \033[0m";
	Bureaucrat Tarmo("Tarmo", 150);

	std::cout << "\033[1;32mand testing the << overload:\n\033[0m" << "\n";
	std::cout << Tarmo;

	std::cout << "\033[1;32m\n\nTesting lowering the grade too low (from 150 to 151):\n\033[0m" << "\n";
	try {
		Tarmo.decrementGrade();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	Bureaucrat Pekka("Pekka", 1);
	std::cout << "\033[1;32m\nTesting incrementing the grade too high (from 1 to 0):\n\033[0m" << "\n";
	try {
		Pekka.incrementGrade();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;32m\n-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32mForm tests: \n\033[0m" << "\n";

	Form importantPaper("importantPaper", false, 5, 5);
	std::cout << "\033[1;32mChecking initial status of importantPaper: \n\033[0m" << "\n";
	int grade = importantPaper.getGrade();
	std::cout << "Min grade required for " << importantPaper.getName() << " is " << grade << "\n";
	importantPaper.getStatus();
	Pekka.signForm(importantPaper);
	Tarmo.signForm(importantPaper);
}
