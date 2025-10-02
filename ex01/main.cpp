/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 14:14:35 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";
	std::cout << "\033[1;32m***Creating a form with appropriate grades***\n\033[0m" << "\n";

	Form form("newForm", 5, 5);
	std::cout << form << std::endl;

	std::cout << "\033[1;32m***Creating a bureaucrat with good enough grade for signing and excecution***\n\033[0m" << "\n";

	Bureaucrat buro("PaperGuy", 5);
	std::cout << buro << std::endl;

	std::cout << "\033[1;32m***Trying to sign a form with the capable bureaucrat***\n\033[0m" << "\n";

	form.beSigned(buro);
	std::cout << form << std::endl;

	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***Creating a bureaucrat with too bad grade for signing and excecution***\n\033[0m" << "\n";

	Bureaucrat badburo("IncapablePaperGuy", 50);
	std::cout << badburo << std::endl;

	std::cout << "\033[1;32m***Trying to sign a form with not capable bureaucrat***\n\033[0m" << "\n";

	try {
		form.beSigned(badburo);
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot sign because " << e.what() << std::endl;
	}
	std::cout << form << std::endl;

	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***Creating another buro with good enough grade***\n\033[0m" << "\n";

	Bureaucrat newburo("AnotherPaperGuy", 5);
	std::cout << newburo << std::endl;

	std::cout << "\033[1;32m***Trying to sign the form again***\n\033[0m" << "\n";

	try {
		form.beSigned(newburo);
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot sign because " << e.what() << std::endl;
	}
	std::cout << form << std::endl;

	std::cout << "\033[1;32m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***Creating a form with too low grades***\n\033[0m" << "\n";

	try {
		Form errorForm("errForm", 151, 151);
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot create form because " << e.what() << std::endl;
	};

	std::cout << "\033[1;32m\n***Creating a form with too high grades***\n\033[0m" << "\n";

	try {
		Form errorForm("errForm", -1, -1);
	} catch (std::exception &e) {
		std::cerr << "Exception: cannot create form because " << e.what() << std::endl;
	};

	std::cout << "\033[1;32m\n-------------------------------DONE--------------------------------------\n\033[0m" << "\n";
}
