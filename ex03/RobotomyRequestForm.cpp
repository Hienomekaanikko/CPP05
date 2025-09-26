/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:15:58 by msuokas           #+#    #+#             */
/*   Updated: 2025/09/26 12:59:51 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyDefaultForm", 72, 45), _target("DefaultTarget") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	_target = other._target;
	return *this;
}

const char* RobotomyRequestForm::RobotomizationException::what() const throw() {
	return "Robotomy failed";
}

void RobotomyRequestForm::action() const {
	int nb = rand() % 2;

	if (nb == 1)
		std::cout << "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR! " << " robotomization of " << _target << " succeeded!" << std::endl;
	else
		throw RobotomizationException();
}

std::string& RobotomyRequestForm::getTarget() {
	return _target;
}
