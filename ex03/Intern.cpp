/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:24:15 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/26 15:22:05 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {}

Intern& Intern::operator=(const Intern& other) {
	return *this;
}

AForm* Intern::makeForm(const std::string formName, const std::string formTarget) {
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	AForm* (*formCreators[])(const std::string&) = {
		[](const std::string& target) -> AForm* { return new PresidentialPardonForm(target); },
		[](const std::string& target) -> AForm* { return new RobotomyRequestForm(target); },
		[](const std::string& target) -> AForm* { return new ShrubberyCreationForm(target); }
	};
	for (int i = 0; i < 3; ++i) {
		if (forms[i] == formName) {
			std::cout << "Intern creates " << forms[i] << std::endl;
			return formCreators[i](formTarget);
		}
	}
	std::cout << "Intern: No such form \"" << formName << "\"" << std::endl;
	return NULL;
}

const char* Intern::InternException::what() const throw() {
	return "Such form does not exist";
}
