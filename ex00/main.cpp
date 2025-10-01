/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/29 14:15:04 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";
	std::cout << "\033[1;32mTrying to create a bureaucrat with appropriate grade and test functionalities:\n\033[0m" << "\n";
	Bureaucrat* Teuvo = nullptr;

	try {
		Teuvo = new Bureaucrat("Teuvo", 150);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}
	if (Teuvo) {
		std::cout << "Bureaucrat " << Teuvo->getName() << " was created successfully!" << "\n";
		std::cout << *Teuvo << std::endl;
		std::cout << "\033[1;36mTesting Increment:\n\033[0m" << "\n";
		try {
			Teuvo->increment();
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << "\n";
		}
		std::cout << *Teuvo << std::endl;
		std::cout << "\033[1;36mTesting Decrement:\n\033[0m" << "\n";
		try {
			Teuvo->decrement();
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << "\n";
		}
		std::cout << *Teuvo << std::endl;
		std::cout << "\033[1;36mTesting copy constructor:\n\033[0m" << "\n";
		Bureaucrat Copy(*Teuvo);
		std::cout << Copy << std::endl;
		delete Teuvo;
	}

	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32mTrying to create a bureaucrat with a grade less than 1 (too high):\n\033[0m" << "\n";
	Bureaucrat* Kalevi = nullptr;
	try {
		Kalevi = new Bureaucrat("Kalevi", 0);
	} catch (std::exception &e) {
		std::cout <<"Exception: " << e.what() << "\n";
	}
	if (Kalevi) {
		std::cout << "Bureaucrat " << Kalevi->getName() << " was created successfully!" << "\n";
		std::cout << *Kalevi << std::endl;
		delete Kalevi;
	}

	std::cout << "\033[1;32m\n-------------------------------------------------------------------------\033[0m" << "\n";

	std::cout << "\033[1;32m\nTrying to create a bureaucrat with a grade more than 150 (too low):\n\033[0m" << "\n";
	Bureaucrat* Virpi = nullptr;
	try {
		Virpi = new Bureaucrat("Virpi", 151);
	} catch (std::exception &e) {
		std::cout <<"Exception: " << e.what() << "\n";
	}
	if (Virpi) {
		std::cout << "Bureaucrat " << Virpi->getName() << " was created successfully!" << "\n";
		std::cout << *Virpi << std::endl;
		std::cout << "\033[1;36mTesting copy constructor:\n\033[0m" << "\n";
		Bureaucrat Copy(*Virpi);
		std::cout << Copy << std::endl;
		delete Virpi;
	}
	std::cout << "\033[1;32m\n-------------------------------------------------------------------------\033[0m" << "\n";
}
