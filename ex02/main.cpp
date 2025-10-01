/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:12:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/01 15:35:55 by msuokas          ###   ########.fr       */
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
	PresidentialPardonForm* Form1 = nullptr;
	try {
		Form1 = new PresidentialPardonForm("Crazy Frog");
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << *Form1 << "\n";

	std::cout << "\033[1;32m***Creating a Bureaucrat with good enough grade***\n\033[0m" << "\n";
	Bureaucrat* Dude1 = nullptr;
	try {
		Dude1 = new Bureaucrat("Dude1", 5);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	if (Dude1 && Form1)
	{
		std::cout << *Dude1 << "\n";
		std::cout << "\033[1;32m***Signing the form***\n\033[0m" << "\n";
		try {
			Form1->beSigned(*Dude1);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		std::cout << *Form1 << "\n";
		std::cout << "\033[1;32m***Exceuting the form***\n\033[0m" << "\n";
		try {
			Dude1->executeForm(*Form1);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	delete Dude1;
	delete Form1;

	try {
		Form1 = new PresidentialPardonForm("Crazy Frog");
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with too low grade for executing***\n\033[0m" << "\n";

	Bureaucrat* Dude2 = nullptr;
	try {
		Dude2 = new Bureaucrat("Dude2", 6);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	if (Dude2 && Form1)
	{
		std::cout << *Dude2 << "\n";
		std::cout << "\033[1;32m***Signing the form***\n\033[0m" << "\n";
		try {
			Form1->beSigned(*Dude2);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		std::cout << *Form1 << "\n";

		std::cout << "\033[1;32m***Trying to execute the form***\n\033[0m" << "\n";

		try {
			Dude2->executeForm(*Form1);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	delete Form1;
	delete Dude2;
	std::cout << "\033[1;35m\n-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;32m-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;35m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***ROBOTOMY REEQUEST FORM TEST***\n\033[0m" << "\n";
	std::cout << "\033[1;32m***Creating a Robotomoy Request Form***\n\033[0m" << "\n";

	RobotomyRequestForm* RoboForm = nullptr;

	try {
		RoboForm = new RobotomyRequestForm("SomeThingToBeRobotomized");
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << *RoboForm << std::endl;

	std::cout << "\033[1;32m***Creating a Bureaucrat with good enough grade***\n\033[0m" << "\n";

	Bureaucrat* Buro = nullptr;

	try {
		Buro = new Bureaucrat("Teuvo", 44);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	if (Buro && RoboForm) {
		std::cout << *Buro << std::endl;
		std::cout << "\033[1;32m***Signing the form***\n\033[0m" << "\n";
		try {
			RoboForm->beSigned(*Buro);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		std::cout << *RoboForm << std::endl;

		std::cout << "\033[1;32m***Executing 10 times to see roughly 50% a time success***\n\033[0m" << "\n";

		for (int i = 0; i < 10; i++){
			try {
				Buro->executeForm(*RoboForm);
			} catch (std::exception &e) {
				std::cout << "Exception: " << e.what() << "\n";
			}
		}
	}
	delete Buro;
	delete RoboForm;

	try {
		RoboForm = new RobotomyRequestForm("SomeThingToBeRobotomized");
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with too low grade for executing***\n\033[0m" << "\n";

	Bureaucrat* Buro2 = nullptr;

	try {
		Buro2 = new Bureaucrat("Tahvo", 46);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	if (Buro2 && RoboForm) {
		std::cout << *Buro2 << "\n";
		std::cout << "\033[1;32m***Signing the form***\n\033[0m" << "\n";
		try {
			RoboForm->beSigned(*Buro2);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << "\n";
		}

		std::cout << *RoboForm << std::endl;

		std::cout << "\033[1;32m***Trying to execute the form***\n\033[0m" << "\n";

		try {
			Buro2->executeForm(*RoboForm);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << "\n";
		}
	}
	delete Buro2;
	delete RoboForm;

	std::cout << "\033[1;35m\n-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;32m-------------------------------------------------------------------------\033[0m" << "\n";
	std::cout << "\033[1;35m-------------------------------------------------------------------------\n\033[0m" << "\n";

	std::cout << "\033[1;32m***Creating a Shrubbery Request Form***\n\033[0m" << "\n";

	ShrubberyCreationForm* ShrubForm = nullptr;
	try {
		ShrubForm = new ShrubberyCreationForm("file1");
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << *ShrubForm << std::endl;

	std::cout << "\033[1;32m***Creating a Bureaucrat with good enough grade***\n\033[0m" << "\n";

	Bureaucrat* Seppo = nullptr;

	try {
		Seppo = new Bureaucrat("Seppo", 4);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	if (Seppo && ShrubForm) {
		std::cout << *Seppo << std::endl;
		std::cout << "\033[1;32m***Signing the form***\n\033[0m" << "\n";
		try {
			ShrubForm->beSigned(*Seppo);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		std::cout << *ShrubForm << std::endl;

		std::cout << "\033[1;32m***Trying to execute the form***\n\033[0m" << "\n";

		try {
			Seppo->executeForm(*ShrubForm);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << "\n";
		}
	}
	delete Seppo;
	delete ShrubForm;

	try {
		ShrubForm = new ShrubberyCreationForm("file2");
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\033[1;32m\n***Creating a Bureaucrat with too low grade for executing***\n\033[0m" << "\n";

	Bureaucrat* Teppo = nullptr;

	try {
		Teppo = new Bureaucrat("Teppo", 4);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	if (Teppo && ShrubForm) {
		std::cout << *Teppo << "\n";
		std::cout << "\033[1;32m***Signing the form***\n\033[0m" << "\n";
		try {
			ShrubForm->beSigned(*Teppo);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << "\n";
		}

		std::cout << *ShrubForm << std::endl;

		std::cout << "\033[1;32m***Trying to execute the form***\n\033[0m" << "\n";

		try {
			Teppo->executeForm(*ShrubForm);
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << "\n";
		}
	}
	delete Teppo;
	delete ShrubForm;
}
