/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:13:29 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/01 13:40:41 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern(){}

Intern::Intern(const Intern& other) {}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
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
