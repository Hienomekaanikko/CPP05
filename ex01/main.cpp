/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/30 10:50:20 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";
	std::cout << "\033[1;32m***Creating a form with appropriate grades***\n\033[0m" << "\n";

	Form* form = nullptr;
	try {
		form = new Form("newForm", 5, 5);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;36mForm was created:\n\033[0m" << *form << "\n";

	std::cout << "\033[1;32m***Creating a bureaucrat with good enough grade for signing and excecution***\n\033[0m" << "\n";

	Bureaucrat* bure = nullptr;
	try {
		bure = new Bureaucrat("Jorma", 3);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;36mBureaucrat was created:\n\033[0m" << *bure;

	std::cout << "\033[1;32m\n***Trying to sign a form with the capable bureaucrat***\n\033[0m" << "\n";

	try {
		form->beSigned(*bure);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;36m\nForm after signing:\n\033[0m" << *form << "\n";

	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***Creating a form with appropriate grades***\n\033[0m" << "\n";

	Form* form2 = nullptr;
	try {
		form2 = new Form("newForm", 2, 1);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;36mForm was created:\n\033[0m" << *form2 << "\n";

	std::cout << "\033[1;32m***Creating a bureaucrat with too low grade for signing and excecution***\033[0m" << "\n";

	Bureaucrat* bure2 = nullptr;
	try {
		bure2 = new Bureaucrat("Jorma", 3);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\n\033[1;36mBureaucrat was created:\n\033[0m" << *bure2;

	std::cout << "\033[1;32m\n***Trying to sign a form with not capable bureaucrat***\n\033[0m" << "\n";

	try {
		form2->beSigned(*bure2);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;32m\n-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***Creating a form with too high grades***\n\033[0m" << "\n";

	Form* form3 = nullptr;
	try {
		form3 = new Form("newForm", 0, 0);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;32m\n***Creating a bureaucrat with too high grade***\n\033[0m" << "\n";

	Bureaucrat* bure3 = nullptr;
	try {
		bure3 = new Bureaucrat("Seppo", 0);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;32m\n-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***Creating a form with too low grades***\n\033[0m" << "\n";

	Form* form4 = nullptr;
	try {
		form4 = new Form("newForm", 151, 151);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\033[1;32m\n***Creating a bureaucrat with too low grade***\n\033[0m" << "\n";

	Bureaucrat* bure4 = nullptr;
	try {
		bure4 = new Bureaucrat("Seppo", 151);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}
	delete form;
	delete form2;
	delete form3;
	delete form4;
	delete bure;
	delete bure2;
	delete bure3;
	delete bure4;
}
