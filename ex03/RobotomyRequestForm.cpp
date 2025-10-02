/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:56:49 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 14:20:52 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("DefaultRobotomyRequestForm", 72, 45), _target("DefaultTarget"){
	std::cout << "RobotomyRequestForm with target " << _target << " was created"  << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm with target " << _target << " was thrown into bin"  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RoboromyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm with target " << _target << " was created"  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): _target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

const char* RobotomyRequestForm::RobotomyException::what() const noexcept {
	return "Robotomy failed";
}

void RobotomyRequestForm::action() const {
	int nb = rand() % 2;

	if (nb == 1)
		std::cout << "\033[1;36m" << "BRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR! " << "Robotomization of " << _target << " succeeded!" << "\033[0m" << std::endl;
	else
		throw RobotomyException();
}

std::string RobotomyRequestForm::getTarget() const {
	return _target;
}
