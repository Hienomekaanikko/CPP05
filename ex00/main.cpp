/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 16:17:33 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";
	std::cout << "\033[1;32mTrying to create a bureaucrat with good enough grade and test it:\n\033[0m" << "\n";

	try {
		Bureaucrat Teuvo("Teuvo", 140);
		std::cout << Teuvo;
		try {
			Teuvo.increment();
			std::cout << Teuvo;
		} catch (std::exception &e) {
			std::cerr << "Exception: cannot increment because " << e.what() << std::endl;
		}
		try {
			Teuvo.decrement();
			std::cout << Teuvo;
		} catch (std::exception &e) {
			std::cerr << "Exception: cannot decrement because " << e.what() << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot create Bureaucrat because " << e.what() << std::endl;
	}

	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32mTrying to create a bureaucrat with too low grade to decrement:\n\033[0m" << "\n";

	try {
		Bureaucrat Leevi("Leevi", 150);
		std::cout << Leevi;
		try {
			Leevi.decrement();
			std::cout << Leevi;
		} catch (std::exception &e) {
			std::cerr << "Exception: cannot decrement because " << e.what()<< std::endl;
		}
		try {
			Leevi.increment();
			std::cout << Leevi;
		} catch (std::exception &e) {
			std::cerr << "Exception: cannot increment because " << e.what() << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot create bureaucrat because " << e.what() << std::endl;
	}
	std::cout << "\033[1;32m\n-------------------------------------------------------------------------\033[0m" << "\n";

	std::cout << "\033[1;32mTrying to create a bureaucrat with too high grade to increment:\n\033[0m" << "\n";

	try {
		Bureaucrat Virpi("Virpi", 1);
		std::cout << Virpi;
		try {
			Virpi.increment();
			std::cout << Virpi;
		} catch (std::exception &e) {
			std::cerr << "Exception: cannot increment because " << e.what()<< std::endl;
		}
		try {
			Virpi.decrement();
			std::cout << Virpi;
		} catch (std::exception &e) {
			std::cerr << "Exception: cannot decrement because " << e.what() << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot create bureaucrat because " << e.what() << std::endl;
	}
	{
	std::cout << "\n\033[1;32mTrying to create a bureaucrat with too high grade:\n\033[0m" << "\n";

	try {
		Bureaucrat Virpi("Virpi", -1);
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot create bureaucrat because " << e.what() << std::endl;
	}

	std::cout << "\n\033[1;32mTrying to create a bureaucrat with too low grade:\n\033[0m" << "\n";

	try {
		Bureaucrat Liisa("Liisa", 151);
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot create bureaucrat because " << e.what() << std::endl;
	}
	}
	std::cout << "\033[1;32m\n-------------------------------DONE--------------------------------------\n\033[0m" << "\n";
}
